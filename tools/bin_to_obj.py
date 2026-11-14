#!/usr/bin/env python3
"""Converts a Banjo-Tooie model asset (asset_<id>.bin, as the DEV tab's Dump assets writes it or as a model mod
ships it) to a Wavefront .obj with a .mtl and the model's textures as PNGs, and to a .glb (glTF) with the textures
inside. Python 3, standard library only.

    py tools/bin_to_obj.py <asset_XXXX.bin> [more .bin ...] [-o <out folder>] [-f obj|glb|both]

The model's display list is walked from start to end and every triangle it draws is written, grouped by the texture
loaded when it was drawn. Vertices are written as stored, in the model's rest pose; bones and animation are not
applied. Vertex colours go on the `v` lines (x y z r g b), which Blender's importer reads as a colour attribute; for
parts drawn with lighting on, the colour bytes are normals and are written as `vn` instead.
"""

import argparse
import json
import os
import struct
import sys
import zlib

MODEL_MAGIC = 0x0B

# Texture kinds in the model's texture list.
TEX_CI4, TEX_CI8, TEX_RGBA16, TEX_RGBA32, TEX_IA8 = 0x01, 0x02, 0x04, 0x08, 0x10

G_LIGHTING = 0x00020000  # F3DEX2 geometry mode bits
# Geometry-mode bits the game's models switch per material, and the tokens material names carry them as, so that
# tools/obj_to_bin.py can set them again: fog, lighting, texture generation (environment mapping) and its linear form.
GEOMETRY_FLAGS = 0x000F0000
G_TEXTURE_GEN = 0x00040000
GEOMETRY_TOKENS = (("_fog", 0x00010000), ("_lit", 0x00020000), ("_env", 0x00040000), ("_lin", 0x00080000))


def combiner_uses_texture(w0, w1):
    """Whether a G_SETCOMBINE samples TEXEL0 or TEXEL1 in either cycle. Many parts of the game's models (Banjo's
    fur, for one) are drawn from vertex colours alone with no texture, after a textured part."""
    colour = [(w0 >> 20) & 0xF, (w0 >> 15) & 0x1F, (w0 >> 5) & 0xF, w0 & 0x1F,       # a0 c0 a1 c1
              (w1 >> 28) & 0xF, (w1 >> 24) & 0xF, (w1 >> 15) & 0x7, (w1 >> 6) & 0x7]  # b0 b1 d0 d1
    alpha = [(w0 >> 12) & 0x7, (w0 >> 9) & 0x7, (w1 >> 21) & 0x7, (w1 >> 18) & 0x7,
             (w1 >> 12) & 0x7, (w1 >> 9) & 0x7, (w1 >> 3) & 0x7, w1 & 0x7]
    # TEXEL0 is 1 and TEXEL1 is 2 in every slot; the colour C slots also have TEXEL0/1 alpha as 8 and 9.
    return any(v in (1, 2) for v in colour + alpha) or colour[1] in (8, 9) or colour[3] in (8, 9)


def u16(d, o):
    return struct.unpack_from(">H", d, o)[0]


def s16(d, o):
    return struct.unpack_from(">h", d, o)[0]


def u32(d, o):
    return struct.unpack_from(">I", d, o)[0]


def png_bytes(width, height, rgba):
    """Encodes 8-bit RGBA pixels (bytes, row by row) as a PNG."""
    raw = b"".join(b"\x00" + rgba[y * width * 4:(y + 1) * width * 4] for y in range(height))

    def chunk(tag, data):
        c = tag + data
        return struct.pack(">I", len(data)) + c + struct.pack(">I", zlib.crc32(c) & 0xFFFFFFFF)

    return (b"\x89PNG\r\n\x1a\n" + chunk(b"IHDR", struct.pack(">IIBBBBB", width, height, 8, 6, 0, 0, 0))
            + chunk(b"IDAT", zlib.compress(raw, 9)) + chunk(b"IEND", b""))


def rgba5551(c):
    r, g, b = (c >> 11) & 31, (c >> 6) & 31, (c >> 1) & 31
    return bytes(((r << 3) | (r >> 2), (g << 3) | (g >> 2), (b << 3) | (b >> 2), 255 if c & 1 else 0))


def decode_texture(data, off, kind, w, h):
    """Returns (rgba bytes, has_alpha), or None for a kind this does not know. CI textures keep their palette
    (RGBA16) in front of the pixels."""
    n = w * h
    out = bytearray()
    if kind == TEX_RGBA16:
        for i in range(n):
            out += rgba5551(u16(data, off + i * 2))
    elif kind == TEX_RGBA32:
        out += data[off:off + n * 4]
    elif kind == TEX_CI4:
        pal = [rgba5551(u16(data, off + i * 2)) for i in range(16)]
        px = off + 0x20
        for i in range(n):
            b = data[px + i // 2]
            out += pal[(b >> 4) if i % 2 == 0 else (b & 15)]
    elif kind == TEX_CI8:
        pal = [rgba5551(u16(data, off + i * 2)) for i in range(256)]
        px = off + 0x200
        for i in range(n):
            out += pal[data[px + i]]
    elif kind == TEX_IA8:
        for i in range(n):
            b = data[off + i]
            iv, av = (b >> 4) * 17, (b & 15) * 17
            out += bytes((iv, iv, iv, av))
    else:
        return None
    return bytes(out), any(out[i] != 255 for i in range(3, len(out), 4))


class Model:
    def __init__(self, data, folder=None):
        """`folder` is where the model's file is; models with external textures read them from the asset files
        beside it (as the DEV tab's dump writes them)."""
        if len(data) < 0x50 or u32(data, 0) != MODEL_MAGIC:
            raise ValueError("not a model asset (no 0x0B at the start; is it still compressed, or another kind?)")
        self.data = data
        self.folder = folder
        self.tex_list = u16(data, 0x08)
        self.gfx = u32(data, 0x0C)
        self.vtx = u32(data, 0x10)
        self.read_textures()
        self.read_vertices()

    def read_textures(self):
        d, t = self.data, self.tex_list
        self.textures = []  # (offset in segment 2, kind, width, height)
        self.tex_base = 0
        if not t:
            return
        count = u16(d, t + 4)
        self.tex_base = t + 8 + count * 8  # segment 2 starts after the entries
        self.external = bool(d[t + 6])
        if self.external:
            # Each entry names a texture file (0x1EF6 + its number); the game puts the files one after another in
            # segment 2, so the offsets are their running sizes.
            seg, offset = bytearray(), 0
            for i in range(count):
                e = t + 8 + i * 8
                fid = 0x1EF6 + u32(d, e)
                path = os.path.join(self.folder or ".", f"asset_{fid:04X}.bin")
                if not os.path.exists(path):
                    raise ValueError(f"the model's textures are in separate files; asset_{fid:04X}.bin was not found "
                                     "beside it (dump all assets into one folder)")
                with open(path, "rb") as f:
                    blob = f.read()
                self.textures.append((len(seg), d[e + 5], d[e + 6], d[e + 7]))
                seg += blob
            self.data = d = bytes(d) + bytes(seg)
            self.tex_base = len(d) - len(seg)
            return
        for i in range(count):
            e = t + 8 + i * 8
            # The kind's high byte is 0x80 for a mipmapped texture; its first level decodes the same.
            self.textures.append((u32(d, e), d[e + 5], d[e + 6], d[e + 7]))

    def texture_at(self, seg_off):
        """Index of the texture whose data holds segment-2 offset `seg_off` (a CI image's address points past its
        palette), or None."""
        best = None
        for i, (off, _, _, _) in enumerate(self.textures):
            if off <= seg_off and (best is None or off > self.textures[best][0]):
                best = i
        return best

    def read_vertices(self):
        d, v = self.data, self.vtx
        # The model header holds the vertex count at 0x46 (the triangle count at 0x44); the vertex list's own header
        # has it doubled at 0x16. Its 0x14 is not the count in Tooie's models.
        count = u16(d, 0x46) or u16(d, v + 0x16) // 2
        self.verts = []
        base = v + 0x18
        for i in range(count):
            o = base + i * 16
            if o + 16 > len(d):
                break
            self.verts.append((s16(d, o), s16(d, o + 2), s16(d, o + 4), s16(d, o + 8), s16(d, o + 10),
                               d[o + 12], d[o + 13], d[o + 14], d[o + 15]))

    def command_count(self):
        # The list's command count stops at 32767 on big models; then walk up to the vertex list that follows.
        count = u32(self.data, self.gfx)
        if count >= 32767 and self.vtx > self.gfx:
            count = max(count, (self.vtx - self.gfx - 8) // 8)
        return count

    def parts(self):
        """The geo layout's drawing commands, in the order they are met: dicts with `off` (file offset of the
        command), `cmd`, `blocks` (display-list indices it draws, each up to its G_ENDDL), `bone`, `alt` (which child
        of the nearest selector it sits under; 0 is the one shown by default) and, for the skinned kinds, `vstart`
        and `groups` (vertex counts: one for 0x11; for 0x18, the bone's then its parent's, per block).

        Commands: 0x02 bone (child at byte +8), 0x0C selector (count at +8, child offsets from +0x0C), 0x0D draw
        distance (child at u16 +0x14), 0x08 LOD (child at u32 +0x1C), 0x0F and 0x00 (child at u16 +8), 0x01 sort
        (children at u16 +0x22 and u32 +0x24); drawing: 0x03 {dl/8, tris}, 0x16 {dl/8}, 0x11 {dl/8, first vertex,
        vertex count}, 0x18 {dl/8 A, dl/8 B, bone count A at +0x14, parent count A at +0x20, (B's counts in the low
        halves), first vertex at +0x2C}. Every command's u32 +4 is the offset to the next one, 0 for the last."""
        d = self.data
        out, seen = [], set()

        def visit(off, bone, alt):
            while 0 < off and off + 8 <= len(d) and off not in seen:
                seen.add(off)
                c, nxt = u32(d, off), u32(d, off + 4)
                if c == 0x02:
                    if d[off + 8]:
                        visit(off + d[off + 8], d[off + 9], alt)
                elif c == 0x0C:
                    for i in range(u16(d, off + 8)):
                        visit(off + u32(d, off + 0x0C + 4 * i), bone, i)
                elif c == 0x0D:
                    visit(off + u16(d, off + 0x14), bone, alt)
                elif c == 0x08:
                    visit(off + u32(d, off + 0x1C), bone, alt)
                elif c in (0x0F, 0x00):
                    visit(off + u16(d, off + 8), bone, alt)
                elif c == 0x01:
                    if u16(d, off + 0x22):
                        visit(off + u16(d, off + 0x22), bone, alt)
                    if u32(d, off + 0x24):
                        visit(off + u32(d, off + 0x24), bone, alt)
                elif c in (0x03, 0x16, 0x11, 0x18):
                    p = {"off": off, "cmd": c, "blocks": [u16(d, off + 8)], "bone": bone, "alt": alt}
                    if c == 0x11:
                        p["vstart"], p["groups"] = u16(d, off + 10), [u16(d, off + 12)]
                    elif c == 0x18:
                        p["vstart"] = u16(d, off + 0x2C)
                        p["groups"] = [u16(d, off + 0x14), u16(d, off + 0x20)]
                        if u16(d, off + 10):
                            p["blocks"].append(u16(d, off + 10))
                            p["groups"] += [u16(d, off + 0x22), u16(d, off + 0x16)]
                    out.append(p)
                if nxt == 0:
                    return
                off += nxt

        geo = u32(d, 0x04)
        if geo and geo < len(d):
            visit(geo, 0, 0)
        return out

    def walk(self, start=0, block=False):
        """Yields (texture index or None, (wrap s, wrap t), [(vertex index, u, v, lit) x3], (double sided,
        geometry flags, G_TEXTURE scale word when texture generation is on)) per triangle, with u/v already turned into 0..1 texture coordinates for that texture. Wrap is the render tile's
        clamp/mirror bits: 1 mirror, 2 clamp. With `block`, walks from command `start` up to its G_ENDDL only."""
        d = self.data
        count = self.command_count()
        pos = self.gfx + 8 + start * 8
        count -= start
        double_sided = False
        texture_scale = 0x80008000
        buf = [None] * 64
        geom = 0
        scale_s = scale_t = 1.0
        last_img = None
        cur_tex = None
        textured = True
        tile_size = {}   # tile -> (uls, ult, width, height) in texels
        tile_shift = {}  # tile -> (shift s, shift t)
        tile_wrap = {}   # tile -> (cms, cmt)

        def uv(vi):
            v = self.verts[vi]
            s, t = v[3] * scale_s / 32.0, v[4] * scale_t / 32.0
            ss, st = tile_shift.get(0, (0, 0))
            s = s / (1 << ss) if ss <= 10 else s * (1 << (16 - ss))
            t = t / (1 << st) if st <= 10 else t * (1 << (16 - st))
            if cur_tex is not None:
                _, _, w, h = self.textures[cur_tex]
            else:
                w = h = 32
            uls, ult, _, _ = tile_size.get(0, (0, 0, w, h))
            return (s - uls) / w, (t - ult) / h

        def tri(a, b, c):
            ids = [buf[a], buf[b], buf[c]]
            if None in ids:
                return None
            lit = bool(geom & G_LIGHTING)
            tex = cur_tex if textured else None
            return (tex, (tile_wrap.get(0, (0, 0)) if tex is not None else (0, 0)), [(i, *uv(i), lit) for i in ids],
                    (double_sided, geom & GEOMETRY_FLAGS, texture_scale if geom & G_TEXTURE_GEN else 0))

        for _ in range(count):
            if pos + 8 > len(d):
                break
            w0, w1 = u32(d, pos), u32(d, pos + 4)
            pos += 8
            op = w0 >> 24
            if op == 0x01:  # G_VTX
                n = (w0 >> 12) & 0xFF
                v0 = ((w0 >> 1) & 0x7F) - n
                if (w1 >> 24) == 0x01:
                    first = (w1 & 0xFFFFFF) // 16
                    for k in range(n):
                        if 0 <= v0 + k < 64:
                            idx = first + k
                            buf[v0 + k] = idx if idx < len(self.verts) else None
            elif op == 0x05:  # G_TRI1
                r = tri(((w0 >> 16) & 0xFF) // 2, ((w0 >> 8) & 0xFF) // 2, (w0 & 0xFF) // 2)
                if r:
                    yield r
            elif op in (0x06, 0x07):  # G_TRI2, G_QUAD
                for r in (tri(((w0 >> 16) & 0xFF) // 2, ((w0 >> 8) & 0xFF) // 2, (w0 & 0xFF) // 2),
                          tri(((w1 >> 16) & 0xFF) // 2, ((w1 >> 8) & 0xFF) // 2, (w1 & 0xFF) // 2)):
                    if r:
                        yield r
            elif op == 0xDF and block:  # G_ENDDL
                return
            elif op == 0xD9:  # G_GEOMETRYMODE: clear then set
                geom = (geom & (w0 & 0xFFFFFF | 0xFF000000)) | w1
                # The game's blocks clear the cull bits (D9C0F9FB) for double-sided parts and leave them as the
                # game set them (back faces culled) otherwise.
                if (w0 & 0xFFFFFF) != 0xFFFFFF:
                    double_sided = not (w0 & 0x600)
            elif op == 0xD7:  # G_TEXTURE
                texture_scale = w1
                hs, ht = w1 >> 16, w1 & 0xFFFF
                scale_s = 1.0 if hs == 0xFFFF else hs / 65536.0
                scale_t = 1.0 if ht == 0xFFFF else ht / 65536.0
            elif op == 0xFC:  # G_SETCOMBINE
                textured = combiner_uses_texture(w0, w1)
            elif op == 0xFD:  # G_SETTIMG
                last_img = w1
            elif op in (0xF3, 0xF4):  # G_LOADBLOCK, G_LOADTILE: the last image set is the texture
                if last_img is not None and (last_img >> 24) == 0x02:
                    cur_tex = self.texture_at(last_img & 0xFFFFFF)
            elif op == 0xF5:  # G_SETTILE
                tile = (w1 >> 24) & 7
                tile_shift[tile] = (w1 & 0xF, (w1 >> 10) & 0xF)
                tile_wrap[tile] = ((w1 >> 8) & 3, (w1 >> 18) & 3)
            elif op == 0xF2:  # G_SETTILESIZE
                tile = (w1 >> 24) & 7
                uls, ult = ((w0 >> 12) & 0xFFF) / 4.0, (w0 & 0xFFF) / 4.0
                lrs, lrt = ((w1 >> 12) & 0xFFF) / 4.0, (w1 & 0xFFF) / 4.0
                tile_size[tile] = (uls, ult, lrs - uls + 1, lrt - ult + 1)
            # G_DL and the rest are skipped: G_DL calls the game's own render-mode lists (segment 3 and 7), not
            # the model's.




class Tri:
    """One triangle: `part` (index into Model.parts(), or -1 for one no geo-layout command draws), `tex` (texture
    index or None), `wrap`, `corners` [(vertex index, u, v, lit) x3] and `mode` (double sided, geometry flags)."""
    __slots__ = ("part", "tex", "wrap", "corners", "mode")

    def __init__(self, part, tex, wrap, corners, mode):
        self.part, self.tex, self.wrap, self.corners, self.mode = part, tex, wrap, corners, mode


def model_triangles(model):
    """Every triangle, tagged with the geo-layout part that draws it. Blocks no part reaches (a few models have
    them) are walked too and come out as part -1."""
    parts = model.parts()
    if not parts:
        return parts, [Tri(-1, *t) for t in model.walk()]
    tris, reached = [], set()
    for pi, p in enumerate(parts):
        for start in p["blocks"]:
            reached.add(start)
            tris += [Tri(pi, *t) for t in model.walk(start, block=True)]
    d, count = model.data, model.command_count()
    start = 0
    for i in range(count):
        if u32(d, model.gfx + 8 + i * 8) >> 24 == 0xDF:
            if start not in reached:
                tris += [Tri(-1, *t) for t in model.walk(start, block=True)]
            start = i + 1
    return parts, tris


def part_name(parts, index):
    """Object name for a part: p<index>_bone<bone>, with _alt<n> for a selector's other children (eye states and
    the like, which all show at once outside the game). The reverse tool reads the p<index> back. "loose" holds
    triangles in blocks the geo layout never draws; the game does not show them and the reverse tool leaves them
    out."""
    if index < 0:
        return "loose"
    p = parts[index]
    return f"p{index:02d}_bone{p['bone']:02d}" + (f"_alt{p['alt']}" if p["alt"] else "")


def signed_normal(vert):
    """The normal a lit vertex keeps in its colour bytes, made unit length."""
    n = [c - 256 if c > 127 else c for c in vert[5:8]]
    ln = max(1e-6, (n[0] ** 2 + n[1] ** 2 + n[2] ** 2) ** 0.5)
    return n[0] / ln, n[1] / ln, n[2] / ln


def decode_used(model, tris):
    """{texture index: (png bytes, width, height, alpha) } for every texture the triangles use; alpha is None for
    opaque, "MASK" for on/off alpha and "BLEND" for partial."""
    out = {}
    for ti in sorted({t.tex for t in tris if t.tex is not None}):
        off, kind, w, h = model.textures[ti]
        dec = decode_texture(model.data, model.tex_base + off, kind, w, h)
        if dec is None:
            print(f"  texture {ti}: kind {kind:#x} not known, left out", file=sys.stderr)
            continue
        alpha = None
        if dec[1]:
            alpha = "BLEND" if any(0 < a < 255 for a in dec[0][3::4]) else "MASK"
        out[ti] = (png_bytes(w, h, dec[0]), w, h, alpha)
    return out


def material_name(tex, mode):
    """tex<NN> or untextured, then _2s for double sided, a token per geometry flag (GEOMETRY_TOKENS) and, for an
    environment-mapped material, _s<scale> with its G_TEXTURE scale (07c0 or 0fc0 in the game's models)."""
    double_sided, flags, scale = mode
    return (("untextured" if tex is None else f"tex{tex:02d}") + ("_2s" if double_sided else "")
            + "".join(token for token, bit in GEOMETRY_TOKENS if flags & bit)
            + (f"_s{scale >> 16:04x}" if scale else ""))


def write_obj(model, parts, tris, textures, out_dir, name, source):
    tex_dir = os.path.join(out_dir, name + "_textures")
    mtl_lines = []
    if textures:
        os.makedirs(tex_dir, exist_ok=True)
    for ti in textures:
        with open(os.path.join(tex_dir, f"tex{ti:02d}.png"), "wb") as f:
            f.write(textures[ti][0])
    for tex, mode in sorted({(t.tex, t.mode) for t in tris}, key=lambda m: (-1 if m[0] is None else m[0], m[1])):
        mtl_lines += ["", f"newmtl {material_name(tex, mode)}", "Kd 1 1 1", "Ka 0 0 0", "Ks 0 0 0", "illum 1"]
        if tex in textures:
            png = f"{name}_textures/tex{tex:02d}.png"
            mtl_lines.append(f"map_Kd {png}")
            if textures[tex][3]:
                mtl_lines.append(f"map_d {png}")

    obj = [f"# {source}: {len(tris)} triangles, {len(model.verts)} vertices, one object per geo-layout part",
           f"mtllib {name}.mtl"]
    for x, y, z, _, _, r, g, b, _ in model.verts:
        obj.append(f"v {x} {y} {z} {r / 255:.4f} {g / 255:.4f} {b / 255:.4f}")
    vt_index, vn_index = {}, {}
    vt_lines, vn_lines, faces = [], [], {}
    for t in tris:
        face = []
        for vi, u, v, lit in t.corners:
            key = (round(u, 6), round(1.0 - v, 6))
            if key not in vt_index:
                vt_index[key] = len(vt_index) + 1
                vt_lines.append(f"vt {key[0]} {key[1]}")
            ref = f"{vi + 1}/{vt_index[key]}"
            if lit:
                n = signed_normal(model.verts[vi])
                if n not in vn_index:
                    vn_index[n] = len(vn_index) + 1
                    vn_lines.append(f"vn {n[0]:.4f} {n[1]:.4f} {n[2]:.4f}")
                ref += f"/{vn_index[n]}"
            face.append(ref)
        faces.setdefault(t.part, {}).setdefault(material_name(t.tex, t.mode), []).append(
            "f " + " ".join(face))
    obj += vt_lines + vn_lines
    for part in sorted(faces):
        obj.append(f"o {part_name(parts, part)}")
        for mat, lines in faces[part].items():
            obj.append(f"usemtl {mat}")
            obj += lines

    with open(os.path.join(out_dir, name + ".obj"), "w", newline="\n") as f:
        f.write("\n".join(obj) + "\n")
    with open(os.path.join(out_dir, name + ".mtl"), "w", newline="\n") as f:
        f.write("\n".join(mtl_lines).lstrip() + "\n")
    return os.path.join(out_dir, name + ".obj")


GL_FLOAT, GL_UINT = 5126, 5125
GL_REPEAT, GL_MIRRORED, GL_CLAMP = 10497, 33648, 33071


def srgb_to_linear(byte):
    c = byte / 255
    return c / 12.92 if c <= 0.04045 else ((c + 0.055) / 1.055) ** 2.4


def gl_wrap(bits):
    return GL_MIRRORED if bits & 1 else GL_CLAMP if bits & 2 else GL_REPEAT


def write_glb(model, parts, tris, textures, out_dir, name):
    """A node and mesh per geo-layout part (named as part_name() says), a primitive per material, the textures
    packed inside. Vertex colours go in COLOR_0, which glTF multiplies with the base colour, so untextured parts
    show their colours with no extra setup. The positions stay in game units and a root node scales them by 0.01
    (about a metre to 100 units)."""
    blob = bytearray()
    views, accessors = [], []

    def add_view(data, target=None):
        while len(blob) % 4:
            blob.append(0)
        view = {"buffer": 0, "byteOffset": len(blob), "byteLength": len(data)}
        if target:
            view["target"] = target
        blob.extend(data)
        views.append(view)
        return len(views) - 1

    def add_accessor(data, comp, count, kind, target, **extra):
        acc = {"bufferView": add_view(data, target), "componentType": comp, "count": count, "type": kind}
        acc.update(extra)
        accessors.append(acc)
        return len(accessors) - 1

    images, gl_textures, samplers, materials = [], [], [], []
    image_index, sampler_index, texture_index, material_index = {}, {}, {}, {}

    def material(tex, wrap, mode):
        key = (tex, wrap, mode)
        if key in material_index:
            return material_index[key]
        mat = {"name": material_name(tex, mode), "doubleSided": mode[0],
               "pbrMetallicRoughness": {"metallicFactor": 0.0, "roughnessFactor": 1.0}}
        if tex in textures:
            png, _, _, alpha = textures[tex]
            if tex not in image_index:
                images.append({"bufferView": add_view(png), "mimeType": "image/png", "name": f"tex{tex:02d}"})
                image_index[tex] = len(images) - 1
            if wrap not in sampler_index:
                samplers.append({"magFilter": 9729, "minFilter": 9987,
                                 "wrapS": gl_wrap(wrap[0]), "wrapT": gl_wrap(wrap[1])})
                sampler_index[wrap] = len(samplers) - 1
            if (tex, wrap) not in texture_index:
                gl_textures.append({"source": image_index[tex], "sampler": sampler_index[wrap]})
                texture_index[(tex, wrap)] = len(gl_textures) - 1
            mat["pbrMetallicRoughness"]["baseColorTexture"] = {"index": texture_index[(tex, wrap)]}
            if alpha:
                mat["alphaMode"] = alpha
        materials.append(mat)
        material_index[key] = len(materials) - 1
        return material_index[key]

    by_part = {}
    for t in tris:
        wrap = t.wrap if t.tex in textures else (0, 0)
        by_part.setdefault(t.part, {}).setdefault((t.tex, wrap, t.mode), []).append(t.corners)

    meshes, nodes = [], [{"name": name, "scale": [0.01, 0.01, 0.01], "children": []}]
    for part in sorted(by_part):
        prims = []
        for (tex, wrap, mode), faces in by_part[part].items():
            # glTF has one index per corner for every attribute, so a corner is (vertex, uv, lit).
            corner_index, pos, col, uvs, nrm, idx = {}, [], [], [], [], []
            all_lit = all(c[3] for f in faces for c in f)
            for f in faces:
                for vi, u, v, lit in f:
                    key = (vi, round(u, 6), round(v, 6), lit)
                    if key not in corner_index:
                        corner_index[key] = len(corner_index)
                        vert = model.verts[vi]
                        pos.append(vert[0:3])
                        # A lit vertex's colour bytes are its normal, so its colour is white.
                        col.append((255, 255, 255, vert[8]) if lit else vert[5:9])
                        uvs.append((u, v))
                        if all_lit:
                            nrm.append(signed_normal(vert))
                    idx.append(corner_index[key])
            n = len(pos)
            attrs = {
                "POSITION": add_accessor(b"".join(struct.pack("<3f", *p) for p in pos), GL_FLOAT, n, "VEC3", 34962,
                                         min=[min(p[i] for p in pos) for i in range(3)],
                                         max=[max(p[i] for p in pos) for i in range(3)]),
                # glTF vertex colours are linear and the game's are sRGB; floats keep the dark ones from banding.
                "COLOR_0": add_accessor(b"".join(struct.pack("<4f", *(srgb_to_linear(x) for x in c[:3]), c[3] / 255)
                                                 for c in col), GL_FLOAT, n, "VEC4", 34962),
            }
            if tex in textures:
                attrs["TEXCOORD_0"] = add_accessor(b"".join(struct.pack("<2f", *t) for t in uvs), GL_FLOAT, n,
                                                   "VEC2", 34962)
            if all_lit:
                attrs["NORMAL"] = add_accessor(b"".join(struct.pack("<3f", *v) for v in nrm), GL_FLOAT, n, "VEC3",
                                               34962)
            prims.append({"attributes": attrs, "material": material(tex, wrap, mode), "mode": 4,
                          "indices": add_accessor(struct.pack(f"<{len(idx)}I", *idx), GL_UINT, len(idx), "SCALAR",
                                                  34963)})
        pname = part_name(parts, part)
        meshes.append({"name": pname, "primitives": prims})
        nodes.append({"name": pname, "mesh": len(meshes) - 1})
        nodes[0]["children"].append(len(nodes) - 1)

    while len(blob) % 4:
        blob.append(0)
    gltf = {"asset": {"version": "2.0", "generator": "Banjo Re-Tooie tools/bin_to_obj.py"},
            "scene": 0, "scenes": [{"nodes": [0]}], "nodes": nodes, "meshes": meshes,
            "materials": materials, "accessors": accessors, "bufferViews": views,
            "buffers": [{"byteLength": len(blob)}]}
    if images:
        gltf.update(images=images, textures=gl_textures, samplers=samplers)
    js = json.dumps(gltf, separators=(",", ":")).encode()
    js += b" " * (-len(js) % 4)
    path = os.path.join(out_dir, name + ".glb")
    with open(path, "wb") as f:
        f.write(struct.pack("<III", 0x46546C67, 2, 12 + 8 + len(js) + 8 + len(blob)))
        f.write(struct.pack("<II", len(js), 0x4E4F534A) + js)
        f.write(struct.pack("<II", len(blob), 0x004E4942) + bytes(blob))
    return path


def convert(path, out_dir, formats):
    with open(path, "rb") as f:
        model = Model(f.read(), os.path.dirname(os.path.abspath(path)))
    name = os.path.splitext(os.path.basename(path))[0]
    os.makedirs(out_dir, exist_ok=True)
    parts, tris = model_triangles(model)
    textures = decode_used(model, tris)
    written = []
    if "obj" in formats:
        written.append(write_obj(model, parts, tris, textures, out_dir, name, os.path.basename(path)))
    if "glb" in formats:
        written.append(write_glb(model, parts, tris, textures, out_dir, name))
    print(f"{path}: {len(tris)} triangles in {len(parts)} parts, {len(textures)} textures -> {', '.join(written)}")


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("files", nargs="+", help="asset_XXXX.bin model files")
    ap.add_argument("-o", "--out", help="output folder (default: beside each .bin)")
    ap.add_argument("-f", "--format", choices=["obj", "glb", "both"], default="both",
                    help="what to write (default: both)")
    args = ap.parse_args()
    formats = ("obj", "glb") if args.format == "both" else (args.format,)
    failed = 0
    for path in args.files:
        try:
            convert(path, args.out or os.path.dirname(os.path.abspath(path)), formats)
        except Exception as e:  # keep going through the rest of a batch
            print(f"{path}: {e}", file=sys.stderr)
            failed += 1
    sys.exit(1 if failed else 0)


if __name__ == "__main__":
    main()
