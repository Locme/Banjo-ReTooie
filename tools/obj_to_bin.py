#!/usr/bin/env python3
"""Rebuilds a Banjo-Tooie model asset (asset_<id>.bin) from a .glb/.gltf or .obj, on top of the original .bin, so an
edited model can be loaded in the game as an asset mod. Python 3, standard library only (Pillow is used for textures
that are not PNG, when it is installed).

    py tools/obj_to_bin.py <edited.glb|.obj> --template <original asset_XXXX.bin> [-o <out .bin>]

The original keeps its bones, bone table, selectors and the rest of its geo layout; the textures, display list,
vertices and per-vertex normals are written new from the mesh, and each geo-layout part is pointed at its new
geometry. Which part a triangle belongs to comes from its object's name (p<NN>_..., as tools/bin_to_obj.py names
them); for other objects, from the nearest triangle of the original (alternative parts under a selector, such as
other eye states, are only used by name). In a joint part (geo command 0x18), each vertex follows the bone or its
parent, as the original's nearest vertex in that part does.

Positions: a .glb/.gltf is read in metres (as tools/bin_to_obj.py writes it and Blender exports it) and multiplied
by 100; an .obj is read in game units. --scale overrides either.
"""

import argparse
import json
import math
import os
import re
import struct
import sys
import zlib

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import bin_to_obj as b2o  # noqa: E402

VERTEX_SLOTS = 32  # F3DEX2's vertex buffer

# Display-list words, as the game's own models write them.
GEOM_CLEAR_1S = (0xD9C0FFFB, 0)           # leaves the cull bits as the game set them (back faces culled)
GEOM_CLEAR_2S = (0xD9C0F9FB, 0)           # clears the cull bits: double sided
GEOM_SET = (0xD9FFFFFF, 0x00200004)       # G_SHADE | G_SHADING_SMOOTH
TEX_OFF = (0xD7000000, 0x80008000)
TEX_ON = (0xD7000002, 0x80008000)         # s/t are scaled by 0.5, so they are stored at twice the texel size
PIPESYNC, TILESYNC, LOADSYNC = (0xE7000000, 0), (0xE8000000, 0), (0xE6000000, 0)
CC_TEXTURE = (0xFC129804, 0x3F15FFFF)     # texture times vertex colour
CC_SHADE = (0xFC62FE04, 0x3F15F9FF)       # vertex colour only
RENDER_OPAQUE = (0xDE000000, 0x03000010)  # the game's render-mode lists in segment 3
RENDER_CUTOUT = (0xDE000000, 0x03000040)
ALPHA_COMPARE_ON = (0xE2001E01, 1)
ALPHA_COMPARE_OFF = (0xE2001E01, 0)
TLUT_RGBA16, TLUT_NONE = (0xE3001001, 0x8000), (0xE3001001, 0)
RESTORE_CULL = (0xDE000000, 0x07000000)   # what the game's double-sided blocks end with
POP_MATRIX = (0xD8380002, 0x40)
ENDDL = (0xDF000000, 0)

TEX_CI4, TEX_CI8, TEX_RGBA16 = b2o.TEX_CI4, b2o.TEX_CI8, b2o.TEX_RGBA16


def warn(msg):
    print("  warning: " + msg, file=sys.stderr)


# ---------------------------------------------------------------------------------------------------------------
# Images

def decode_png(data):
    """(width, height, RGBA bytes) from a non-interlaced PNG of any colour type, at 8 or 16 bits (or fewer for
    grey and palette)."""
    if data[:8] != b"\x89PNG\r\n\x1a\n":
        raise ValueError("not a PNG")
    pos, idat, palette, trns = 8, bytearray(), None, None
    while pos < len(data):
        length, tag = struct.unpack_from(">I4s", data, pos)
        body = data[pos + 8:pos + 8 + length]
        pos += 12 + length
        if tag == b"IHDR":
            w, h, depth, ctype, _, _, interlace = struct.unpack(">IIBBBBB", body)
        elif tag == b"PLTE":
            palette = body
        elif tag == b"tRNS":
            trns = body
        elif tag == b"IDAT":
            idat += body
        elif tag == b"IEND":
            break
    if interlace:
        raise ValueError("interlaced PNGs are not read; save it without interlacing")
    channels = {0: 1, 2: 3, 3: 1, 4: 2, 6: 4}[ctype]
    bits = depth * channels
    stride = (w * bits + 7) // 8
    bpp = max(1, bits // 8)
    raw = zlib.decompress(bytes(idat))
    rows, prev, p = [], bytearray(stride), 0
    for _ in range(h):
        f = raw[p]
        line = bytearray(raw[p + 1:p + 1 + stride])
        p += 1 + stride
        for i in range(stride):
            a = line[i - bpp] if i >= bpp else 0
            b = prev[i]
            c = prev[i - bpp] if i >= bpp else 0
            if f == 1:
                line[i] = (line[i] + a) & 255
            elif f == 2:
                line[i] = (line[i] + b) & 255
            elif f == 3:
                line[i] = (line[i] + ((a + b) >> 1)) & 255
            elif f == 4:
                pa, pb, pc = abs(b - c), abs(a - c), abs(a + b - 2 * c)
                line[i] = (line[i] + (a if pa <= pb and pa <= pc else b if pb <= pc else c)) & 255
        rows.append(line)
        prev = line
    out = bytearray()
    for line in rows:
        if depth < 8:
            vals = [(line[i * depth // 8] >> (8 - depth - (i * depth) % 8)) & ((1 << depth) - 1) for i in range(w)]
        elif depth == 16:
            vals = [line[i * 2] for i in range(w * channels)]
        else:
            vals = list(line[:w * channels])
        for x in range(w):
            if ctype == 3:
                i = vals[x]
                r, g, b = palette[i * 3:i * 3 + 3]
                a = trns[i] if trns and i < len(trns) else 255
            elif ctype == 0:
                v = vals[x] * 255 // ((1 << depth) - 1) if depth < 8 else vals[x]
                r = g = b = v
                a = 255
            elif ctype == 4:
                r = g = b = vals[x * 2]
                a = vals[x * 2 + 1]
            elif ctype == 2:
                r, g, b = vals[x * 3:x * 3 + 3]
                a = 255
            else:
                r, g, b, a = vals[x * 4:x * 4 + 4]
            out += bytes((r, g, b, a))
    return w, h, bytes(out)


def decode_image(data):
    if data[:8] == b"\x89PNG\r\n\x1a\n":
        return decode_png(data)
    try:
        import io
        from PIL import Image
        im = Image.open(io.BytesIO(data)).convert("RGBA")
        return im.width, im.height, im.tobytes()
    except ImportError:
        raise ValueError("a texture is not a PNG and Pillow is not installed; save textures as PNG")


def resize(w, h, rgba, nw, nh):
    """Box filter going down, nearest going up."""
    out = bytearray()
    for y in range(nh):
        y0, y1 = y * h // nh, max(y * h // nh + 1, (y + 1) * h // nh)
        for x in range(nw):
            x0, x1 = x * w // nw, max(x * w // nw + 1, (x + 1) * w // nw)
            acc, n = [0, 0, 0, 0], 0
            for yy in range(y0, y1):
                for xx in range(x0, x1):
                    o = (yy * w + xx) * 4
                    for c in range(4):
                        acc[c] += rgba[o + c]
                    n += 1
            out += bytes(v // n for v in acc)
    return bytes(out)


def to_5551(r, g, b, a):
    return (r >> 3) << 11 | (g >> 3) << 6 | (b >> 3) << 1 | (1 if a >= 128 else 0)


def floor_pow2(n):
    return 1 << max(0, int(n).bit_length() - 1)


class Texture:
    """An image made ready for the N64: power-of-two size that fits TMEM (at most 128 a side), then CI4 when it has
    up to 16 colours (in RGBA5551), CI8 up to 256, otherwise RGBA16. TMEM holds 4096 CI4 texels next to the palette,
    2048 of the others."""

    def __init__(self, w, h, rgba):
        nw, nh = min(128, floor_pow2(w)), min(128, floor_pow2(h))

        def fit(limit):
            a, b = nw, nh
            while a * b > limit:
                if a >= b:
                    a //= 2
                else:
                    b //= 2
            return a, b

        def pixels(size):
            img = rgba if size == (w, h) else resize(w, h, rgba, *size)
            return [to_5551(*img[i:i + 4]) for i in range(0, len(img), 4)]

        size = fit(4096)
        # Grey images in 4-bit steps (the game's IA8 textures, such as glows and shadows) stay IA8 at full size.
        if all(rgba[i] == rgba[i + 1] == rgba[i + 2] and rgba[i] % 17 == 0 and rgba[i + 3] % 17 == 0
               for i in range(0, len(rgba), 4)):
            img = rgba if size == (w, h) else resize(w, h, rgba, *size)
            self.w, self.h = size
            self.kind, self.palette_size = b2o.TEX_IA8, 0
            self.data = bytes((img[i] // 17) << 4 | img[i + 3] // 17 for i in range(0, len(img), 4))
            self.has_alpha = any(img[i] < 255 for i in range(3, len(img), 4))
            return
        px = pixels(size)
        if len(set(px)) > 16 and size[0] * size[1] > 2048:
            size = fit(2048)
            px = pixels(size)
        self.w, self.h = size
        colours = sorted(set(px))
        if len(colours) <= 16:
            self.kind, n = TEX_CI4, 16
        elif len(colours) <= 256:
            self.kind, n = TEX_CI8, 256
        else:
            self.kind, n = TEX_RGBA16, 0
        if n:
            index = {c: i for i, c in enumerate(colours)}
            pal = b"".join(struct.pack(">H", c) for c in colours + [0] * (n - len(colours)))
            if self.kind == TEX_CI4:
                pix = bytes((index[px[i]] << 4) | index[px[i + 1]] for i in range(0, len(px), 2))
            else:
                pix = bytes(index[c] for c in px)
            self.data, self.palette_size = pal + pix, len(pal)
        else:
            self.data, self.palette_size = b"".join(struct.pack(">H", c) for c in px), 0
        self.has_alpha = any(not (c & 1) for c in px)


# ---------------------------------------------------------------------------------------------------------------
# Reading the mesh

class Material:
    def __init__(self, name, image=None, wrap=(0, 0), alpha=None, double_sided=False, factor=(1, 1, 1, 1)):
        self.name, self.image, self.wrap, self.alpha = name, image, wrap, alpha
        self.double_sided, self.factor = double_sided, factor


class MeshObject:
    """A named object: triangles of ((x, y, z), (u, v) or None, (r, g, b, a) 0-255, normal or None) corners, each
    with a Material."""

    def __init__(self, name):
        self.name, self.tris = name, []


def linear_to_srgb(c):
    c = min(1.0, max(0.0, c))
    return round(255 * (c * 12.92 if c <= 0.0031308 else 1.055 * c ** (1 / 2.4) - 0.055))


def mat_mul(a, b):
    return [[sum(a[i][k] * b[k][j] for k in range(4)) for j in range(4)] for i in range(4)]


def node_matrix(node):
    if "matrix" in node:
        m = node["matrix"]
        return [[m[c * 4 + r] for c in range(4)] for r in range(4)]
    tx, ty, tz = node.get("translation", (0, 0, 0))
    qx, qy, qz, qw = node.get("rotation", (0, 0, 0, 1))
    sx, sy, sz = node.get("scale", (1, 1, 1))
    rot = [[1 - 2 * (qy * qy + qz * qz), 2 * (qx * qy - qz * qw), 2 * (qx * qz + qy * qw)],
           [2 * (qx * qy + qz * qw), 1 - 2 * (qx * qx + qz * qz), 2 * (qy * qz - qx * qw)],
           [2 * (qx * qz - qy * qw), 2 * (qy * qz + qx * qw), 1 - 2 * (qx * qx + qy * qy)]]
    return [[rot[0][0] * sx, rot[0][1] * sy, rot[0][2] * sz, tx],
            [rot[1][0] * sx, rot[1][1] * sy, rot[1][2] * sz, ty],
            [rot[2][0] * sx, rot[2][1] * sy, rot[2][2] * sz, tz],
            [0, 0, 0, 1]]


def read_gltf(path, scale):
    with open(path, "rb") as f:
        data = f.read()
    folder = os.path.dirname(os.path.abspath(path))
    bin_chunk = b""
    if data[:4] == b"glTF":
        jlen = struct.unpack_from("<I", data, 12)[0]
        gltf = json.loads(data[20:20 + jlen])
        p = 20 + jlen
        if p + 8 <= len(data):
            blen = struct.unpack_from("<I", data, p)[0]
            bin_chunk = data[p + 8:p + 8 + blen]
    else:
        gltf = json.loads(data)

    buffers = []
    for i, buf in enumerate(gltf.get("buffers", [])):
        uri = buf.get("uri")
        if uri is None:
            buffers.append(bin_chunk)
        elif uri.startswith("data:"):
            import base64
            buffers.append(base64.b64decode(uri.split(",", 1)[1]))
        else:
            from urllib.parse import unquote
            with open(os.path.join(folder, unquote(uri)), "rb") as f:
                buffers.append(f.read())

    def view_bytes(vi):
        v = gltf["bufferViews"][vi]
        o = v.get("byteOffset", 0)
        return buffers[v["buffer"]][o:o + v["byteLength"]], v.get("byteStride")

    comp = {5120: ("b", 1, 127), 5121: ("B", 1, 255), 5122: ("h", 2, 32767), 5123: ("H", 2, 65535),
            5125: ("I", 4, 1), 5126: ("f", 4, 1)}
    width = {"SCALAR": 1, "VEC2": 2, "VEC3": 3, "VEC4": 4}

    def accessor(ai):
        a = gltf["accessors"][ai]
        if "sparse" in a:
            raise ValueError("sparse glTF accessors are not read")
        fmt, size, norm = comp[a["componentType"]]
        n = width[a["type"]]
        raw, stride = view_bytes(a["bufferView"])
        stride = stride or size * n
        base = a.get("byteOffset", 0)
        out = []
        for i in range(a["count"]):
            vals = struct.unpack_from("<" + fmt * n, raw, base + i * stride)
            if a.get("normalized"):
                vals = tuple(max(-1.0, v / norm) for v in vals)
            out.append(vals)
        return out

    image_cache = {}

    def image(ii):
        if ii in image_cache:
            return image_cache[ii]
        im = gltf["images"][ii]
        if "bufferView" in im:
            raw = view_bytes(im["bufferView"])[0]
        elif im["uri"].startswith("data:"):
            import base64
            raw = base64.b64decode(im["uri"].split(",", 1)[1])
        else:
            from urllib.parse import unquote
            with open(os.path.join(folder, unquote(im["uri"])), "rb") as f:
                raw = f.read()
        image_cache[ii] = decode_image(raw)
        return image_cache[ii]

    wrap_bits = {10497: 0, 33648: 1, 33071: 2}
    materials = {}

    def material(mi):
        if mi in materials:
            return materials[mi]
        if mi is None:
            materials[mi] = Material("default")
            return materials[mi]
        m = gltf["materials"][mi]
        pbr = m.get("pbrMetallicRoughness", {})
        img, wrap = None, (0, 0)
        if "baseColorTexture" in pbr:
            t = gltf["textures"][pbr["baseColorTexture"]["index"]]
            if "source" in t:
                img = image(t["source"])
            s = gltf["samplers"][t["sampler"]] if "sampler" in t else {}
            wrap = (wrap_bits.get(s.get("wrapS", 10497), 0), wrap_bits.get(s.get("wrapT", 10497), 0))
        mode = m.get("alphaMode", "OPAQUE")
        materials[mi] = Material(m.get("name", f"material{mi}"), img, wrap, None if mode == "OPAQUE" else mode,
                                 m.get("doubleSided", False), tuple(pbr.get("baseColorFactor", (1, 1, 1, 1))))
        return materials[mi]

    objects = []

    def visit(ni, parent):
        node = gltf["nodes"][ni]
        world = mat_mul(parent, node_matrix(node))
        if "mesh" in node:
            mesh = gltf["meshes"][node["mesh"]]
            obj = MeshObject(node.get("name") or mesh.get("name") or f"node{ni}")
            normal_m = [row[:3] for row in world[:3]]
            for prim in mesh["primitives"]:
                if prim.get("mode", 4) != 4:
                    warn(f"{obj.name}: a primitive that is not triangles was left out")
                    continue
                at = prim["attributes"]
                pos = accessor(at["POSITION"])
                uv = accessor(at["TEXCOORD_0"]) if "TEXCOORD_0" in at else None
                col = accessor(at["COLOR_0"]) if "COLOR_0" in at else None
                nrm = accessor(at["NORMAL"]) if "NORMAL" in at else None
                idx = [i[0] for i in accessor(prim["indices"])] if "indices" in prim else list(range(len(pos)))
                mat = material(prim.get("material"))
                f = mat.factor

                def corner(i):
                    x, y, z = pos[i]
                    wp = tuple((world[r][0] * x + world[r][1] * y + world[r][2] * z + world[r][3]) * scale
                               for r in range(3))
                    if col:
                        c = col[i]
                        rgba = (*(linear_to_srgb(c[k] * f[k]) for k in range(3)),
                                round(255 * min(1.0, (c[3] if len(c) > 3 else 1.0) * f[3])))
                    else:
                        rgba = (*(linear_to_srgb(f[k]) for k in range(3)), round(255 * f[3]))
                    n = None
                    if nrm:
                        n = tuple(sum(normal_m[r][k] * nrm[i][k] for k in range(3)) for r in range(3))
                    return wp, (uv[i] if uv else None), rgba, n

                for k in range(0, len(idx) - 2, 3):
                    obj.tris.append(([corner(idx[k]), corner(idx[k + 1]), corner(idx[k + 2])], mat))
            objects.append(obj)
        for c in node.get("children", []):
            visit(c, world)

    identity = [[1 if r == c else 0 for c in range(4)] for r in range(4)]
    scene = gltf["scenes"][gltf.get("scene", 0)]
    for ni in scene["nodes"]:
        visit(ni, identity)
    return objects


def read_obj(path, scale):
    folder = os.path.dirname(os.path.abspath(path))
    vs, vts, vns, cols = [], [], [], []
    materials, current_mat = {}, None
    objects, obj = [], None
    image_cache = {}

    def load_mtl(name):
        mtl_path = os.path.join(folder, name)
        if not os.path.exists(mtl_path):
            warn(f"material library {name} not found")
            return
        m = None
        for line in open(mtl_path, encoding="utf-8", errors="replace"):
            parts = line.split()
            if not parts:
                continue
            if parts[0] == "newmtl":
                m = materials[parts[1]] = Material(parts[1])
            elif m and parts[0] == "Kd" and len(parts) >= 4:
                m.factor = (float(parts[1]), float(parts[2]), float(parts[3]), m.factor[3])
            elif m and parts[0] == "map_Kd":
                tex = os.path.join(folder, line.split(None, 1)[1].strip().split()[-1])
                if tex not in image_cache:
                    with open(tex, "rb") as f:
                        image_cache[tex] = decode_image(f.read())
                m.image = image_cache[tex]
                m.factor = (1, 1, 1, m.factor[3])
            elif m and parts[0] == "map_d":
                m.alpha = "MASK"
            elif m and parts[0] == "d" and float(parts[1]) < 1:
                m.factor = (*m.factor[:3], float(parts[1]))
        for m in materials.values():
            if re.search(r"_2s(_|$)", m.name):
                m.double_sided = True

    for line in open(path, encoding="utf-8", errors="replace"):
        parts = line.split()
        if not parts or parts[0].startswith("#"):
            continue
        tag = parts[0]
        if tag == "v":
            vs.append(tuple(float(x) * scale for x in parts[1:4]))
            cols.append(tuple(float(x) for x in parts[4:7]) if len(parts) >= 7 else None)
        elif tag == "vt":
            vts.append((float(parts[1]), 1.0 - float(parts[2]) if len(parts) > 2 else 0.0))
        elif tag == "vn":
            vns.append(tuple(float(x) for x in parts[1:4]))
        elif tag in ("o", "g") and len(parts) > 1:
            if tag == "g" and obj is not None and obj.tris and obj.name == " ".join(parts[1:]):
                continue
            obj = MeshObject(" ".join(parts[1:]))
            objects.append(obj)
        elif tag == "mtllib":
            load_mtl(line.split(None, 1)[1].strip())
        elif tag == "usemtl":
            current_mat = materials.get(parts[1]) or materials.setdefault(parts[1], Material(parts[1]))
        elif tag == "f":
            if obj is None:
                obj = MeshObject("object")
                objects.append(obj)
            mat = current_mat or materials.setdefault(None, Material("default"))
            corners = []
            for ref in parts[1:]:
                ix = (ref.split("/") + ["", ""])[:3]

                def get(lst, s):
                    if not s:
                        return None
                    i = int(s)
                    return lst[i - 1 if i > 0 else len(lst) + i]
                vi = int(ix[0])
                vi = vi - 1 if vi > 0 else len(vs) + vi
                c = cols[vi]
                f = mat.factor
                rgba = (tuple(round(255 * min(1.0, c[k] * f[k])) for k in range(3)) if c else
                        tuple(round(255 * min(1.0, f[k])) for k in range(3))) + (round(255 * f[3]),)
                corners.append((vs[vi], get(vts, ix[1]), rgba, get(vns, ix[2])))
            for k in range(1, len(corners) - 1):
                obj.tris.append(([corners[0], corners[k], corners[k + 1]], mat))
    return objects


# ---------------------------------------------------------------------------------------------------------------
# Building the model

def pos_key(p):
    return tuple(round(x, 3) for x in p)


def centroid(pts):
    return tuple(sum(p[i] for p in pts) / len(pts) for i in range(3))


class Grid:
    """Nearest-point lookup over a fixed set of points."""

    def __init__(self, points, cell=24.0):
        self.points, self.cell, self.cells = points, cell, {}
        for i, p in enumerate(points):
            self.cells.setdefault(self.key(p), []).append(i)

    def key(self, p):
        return tuple(int(math.floor(c / self.cell)) for c in p)

    def nearest(self, p):
        if not self.points:
            return None
        k = self.key(p)
        best, best_d, r = None, float("inf"), 0
        while True:
            for dx in range(-r, r + 1):
                for dy in range(-r, r + 1):
                    for dz in range(-r, r + 1):
                        if max(abs(dx), abs(dy), abs(dz)) != r:
                            continue
                        for i in self.cells.get((k[0] + dx, k[1] + dy, k[2] + dz), ()):
                            d = sum((a - b) ** 2 for a, b in zip(p, self.points[i]))
                            if d < best_d:
                                best, best_d = i, d
            # Anything in a ring further out is at least r cells away.
            if best is not None and best_d <= (r * self.cell) ** 2:
                return best
            r += 1
            if r > 4096:
                return best


class DisplayList:
    def __init__(self):
        self.words = []

    def add(self, *cmds):
        self.words += cmds


def vtx_cmd(slot, count, index):
    return (0x01000000 | count << 12 | (slot + count) << 1, 0x01000000 | index * 16)


def tri_cmds(tris):
    out = []
    for i in range(0, len(tris) - 1, 2):
        a, b = tris[i], tris[i + 1]
        out.append((0x06000000 | a[0] * 2 << 16 | a[1] * 2 << 8 | a[2] * 2, b[0] * 2 << 16 | b[1] * 2 << 8 | b[2] * 2))
    if len(tris) % 2:
        a = tris[-1]
        out.append((0x05000000 | a[0] * 2 << 16 | a[1] * 2 << 8 | a[2] * 2, 0))
    return out


def log2(n):
    return n.bit_length() - 1


def texture_load(tex, address, wrap):
    """The commands that load `tex` (at segment-2 `address`) into tile 0, with its palette for CI kinds, as the
    game's own gDPLoadTextureBlock/gDPLoadTLUT sequences do."""
    cms, cmt = wrap
    masks, maskt = log2(tex.w), log2(tex.h)
    wrap_bits = cmt << 18 | maskt << 14 | cms << 8 | masks << 4
    cmds = []
    if tex.kind in (TEX_CI4, TEX_CI8):
        colours = 16 if tex.kind == TEX_CI4 else 256
        cmds += [(0xFD100000, 0x02000000 | address), TILESYNC, (0xF5000100, 0x07000000), LOADSYNC,
                 (0xF0000000, 0x07000000 | (colours - 1) << 14), PIPESYNC, TLUT_RGBA16]
        image = address + tex.palette_size
        fmt, siz = 2, (0 if tex.kind == TEX_CI4 else 1)
    elif tex.kind == b2o.TEX_IA8:
        cmds.append(TLUT_NONE)
        image = address
        fmt, siz = 3, 1
    else:
        cmds.append(TLUT_NONE)
        image = address
        fmt, siz = 0, 2
    texels = tex.w * tex.h
    if siz == 0:
        lrs, words = ((texels + 3) >> 2) - 1, max(1, tex.w // 16)
    elif siz == 1:
        lrs, words = ((texels + 1) >> 1) - 1, max(1, tex.w // 8)
    else:
        lrs, words = texels - 1, max(1, tex.w * 2 // 8)
    dxt = (2048 + words - 1) // words
    line = ((tex.w * (4 << siz) // 8) + 7) >> 3
    cmds += [(0xFD000000 | fmt << 21 | 2 << 19, 0x02000000 | image),
             (0xF5000000 | fmt << 21 | 2 << 19, 0x07000000 | wrap_bits), LOADSYNC,
             (0xF3000000, 0x07000000 | lrs << 12 | dxt), PIPESYNC,
             (0xF5000000 | fmt << 21 | siz << 19 | line << 9, wrap_bits),
             (0xF2000000, (tex.w - 1) * 4 << 12 | (tex.h - 1) * 4)]
    return cmds


class Builder:
    def __init__(self, template_path, objects):
        with open(template_path, "rb") as f:
            self.tdata = f.read()
        self.model = b2o.Model(self.tdata, os.path.dirname(os.path.abspath(template_path)))
        self.parts, self.ttris = b2o.model_triangles(self.model)
        if not self.parts:
            raise ValueError("the template has no geo layout parts to put the mesh on")
        self.objects = objects
        self.textures, self.texture_index = [], {}
        self.vertices = []  # (x, y, z, s, t, r, g, b, a)
        self.vertex_normals = []
        self.dl = DisplayList()

    # -- which part each triangle goes on -----------------------------------------------------------------------
    def assign(self):
        named, by_nearest = {}, []
        for obj in self.objects:
            m = re.match(r"p(\d+)", obj.name)
            if m and int(m.group(1)) < len(self.parts):
                named.setdefault(int(m.group(1)), []).extend(obj.tris)
            elif re.match(r"loose(\.\d+)?$", obj.name):
                # Blocks the original never drew; the game would not show them either.
                warn(f"object {obj.name!r} ({len(obj.tris)} triangles) left out: the original never draws it")
            else:
                warn(f"object {obj.name!r} has no p<NN> name; its triangles go on the nearest part")
                by_nearest += obj.tris
        if by_nearest:
            pts, owner = [], []
            for t in self.ttris:
                if t.part >= 0 and self.parts[t.part]["alt"] == 0:
                    pts.append(centroid([self.model.verts[c[0]][:3] for c in t.corners]))
                    owner.append(t.part)
            grid = Grid(pts)
            for tri in by_nearest:
                named.setdefault(owner[grid.nearest(centroid([c[0] for c in tri[0]]))], []).append(tri)
        self.part_tris = named

    # -- textures -----------------------------------------------------------------------------------------------
    def texture(self, image):
        key = (image[0], image[1], hash(image[2]))
        if key not in self.texture_index:
            self.texture_index[key] = len(self.textures)
            self.textures.append(Texture(*image))
        return self.textures[self.texture_index[key]]

    # -- display list -------------------------------------------------------------------------------------------
    def part_geometry_mode(self, pi):
        """The template part's own G_GEOMETRYMODE words (clear, set) from its block's start: lighting, fog and
        texture generation stay as the game had them."""
        d, m = self.tdata, self.model
        i = self.parts[pi]["blocks"][0]
        clear, set_ = GEOM_CLEAR_1S[0], GEOM_SET[1]
        while i < m.command_count():
            w0, w1 = b2o.u32(d, m.gfx + 8 + i * 8), b2o.u32(d, m.gfx + 12 + i * 8)
            if w0 >> 24 == 0xD9:
                if (w0 & 0xFFFFFF) != 0xFFFFFF:
                    clear = w0
                else:
                    set_ = w1
            elif w0 >> 24 in (0x01, 0xDF):
                break
            i += 1
        return clear, set_

    def material_geometry(self, mat):
        """The G_GEOMETRYMODE set word for a material: from its name's tokens when tools/bin_to_obj.py named it
        (tex<NN>/untextured and _lit, _env, ...), else the template part's own."""
        if not re.match(r"(tex\d+|untextured)(_|$)", mat.name):
            return self.geometry[1]
        flags = sum(bit for token, bit in b2o.GEOMETRY_TOKENS if re.search(token + r"(_|$|\.)", mat.name))
        return (self.geometry[1] & ~b2o.GEOMETRY_FLAGS) | flags

    def texture_on(self, mat):
        """G_TEXTURE on. Environment-mapped materials (texture generation) keep the scale their name carries
        (_s07c0), 0x07C0 when it has none; the rest use 0.5, which the s/t written here assume."""
        if not self.material_geometry(mat) & b2o.G_TEXTURE_GEN:
            return TEX_ON
        m = re.search(r"_s([0-9a-fA-F]{4})(_|$|\.)", mat.name)
        scale = int(m.group(1), 16) if m else 0x07C0
        return (TEX_ON[0], scale << 16 | scale)

    def vertex(self, corner, tex, mat):
        """The vertex record for a corner. When lighting is on the colour bytes hold the normal (the alpha
        stays)."""
        (x, y, z), uv, (r, g, b, a), _ = corner
        s = t = 0
        if tex is not None and uv is not None:
            s = max(-32768, min(32767, round(uv[0] * tex.w * 64)))
            t = max(-32768, min(32767, round(uv[1] * tex.h * 64)))
        if self.material_geometry(mat) & b2o.G_LIGHTING:
            n = corner[3] or self.normal_at.get(pos_key(corner[0]), (0, 1, 0))
            ln = math.sqrt(sum(c * c for c in n)) or 1
            r, g, b = (max(-127, min(127, round(127 * c / ln))) & 0xFF for c in n)
        return (max(-32768, min(32767, round(x))), max(-32768, min(32767, round(y))),
                max(-32768, min(32767, round(z))), s, t, r, g, b, a)

    def material_cmds(self, mat, state):
        """Commands to switch to `mat`; `state` carries whether alpha compare is on and cull was cleared, so a
        block can be closed properly."""
        tex = self.texture(mat.image) if mat.image else None
        cutout = tex is not None and (tex.has_alpha or mat.alpha)
        clear = self.geometry[0] & ~0x600 if mat.double_sided else self.geometry[0] | 0x600
        cmds = [(clear, 0), (0xD9FFFFFF, self.material_geometry(mat))]
        if mat.double_sided:
            state["cull_cleared"] = True
        if tex is not None:
            address = self.texture_address[id(tex)]
            cmds.append(self.texture_on(mat))
            cmds += texture_load(tex, address, mat.wrap)
            cmds += [PIPESYNC, CC_TEXTURE]
        else:
            cmds += [TEX_OFF, PIPESYNC, CC_SHADE]
        if cutout:
            cmds += [ALPHA_COMPARE_ON, RENDER_CUTOUT]
            state["alpha_compare"] = True
        else:
            if state.get("alpha_compare"):
                cmds.append(ALPHA_COMPARE_OFF)
                state["alpha_compare"] = False
            cmds.append(RENDER_OPAQUE)
        return cmds, tex

    def close_block(self, state):
        self.dl.add(TLUT_NONE)
        if state.get("alpha_compare"):
            self.dl.add(ALPHA_COMPARE_OFF)
        if state.get("cull_cleared"):
            self.dl.add(RESTORE_CULL)
        self.dl.add(ENDDL)

    def write_vertices(self, keys):
        first = len(self.vertices)
        for k in keys:
            self.vertices.append(k[0])
            self.vertex_normals.append(k[1])
        return first

    def emit_batches(self, tris, state):
        """Draws `tris` [(corners, material, ...)], grouped by material, in batches that fit the vertex buffer.
        Each batch's vertices are written new and contiguous, so one G_VTX loads them."""
        by_mat = {}
        for tri in tris:
            by_mat.setdefault(id(tri[1]), []).append(tri)
        for group in by_mat.values():
            cmds, tex = self.material_cmds(group[0][1], state)
            self.dl.add(*cmds)
            batch, index = [], {}

            def flush():
                if batch:
                    order = sorted(index, key=index.get)
                    self.dl.add(vtx_cmd(0, len(order), self.write_vertices(order)))
                    self.dl.add(*tri_cmds([[index[k] for k in t] for t in batch]))
                    batch.clear()
                    index.clear()

            for tri in group:
                keys = [(self.vertex(c, tex, tri[1]), c[0]) for c in tri[0]]
                if len(index) + len({k for k in keys if k not in index}) > VERTEX_SLOTS:
                    flush()
                for k in keys:
                    index.setdefault(k, len(index))
                batch.append(keys)
            flush()

    def build_part(self, pi):
        part = self.parts[pi]
        tris = self.part_tris.get(pi, [])
        self.geometry = self.part_geometry_mode(pi)
        start_cmd = len(self.dl.words)
        first_vertex = len(self.vertices)
        if part["cmd"] != 0x18:
            state = {}
            self.emit_batches(tris, state)
            self.close_block(state)
            return {"dl": start_cmd, "vstart": first_vertex, "vcount": len(self.vertices) - first_vertex,
                    "tris": len(tris)}
        return self.build_joint(pi, part, tris)

    def build_joint(self, pi, part, tris):
        """A joint part (0x18): per block, the bone's vertices are loaded and drawn first, the matrix is popped and
        the parent's are loaded, so triangles across the seam need both sides in the vertex buffer at once. The
        command has room for two blocks, which gives the seam two buffers; seam triangles that fit neither follow
        the bone only."""
        base, g = part["vstart"], part["groups"]
        bone_v, parent_v = [], []
        cursor = base
        for k, n in enumerate(g):
            (bone_v if k % 2 == 0 else parent_v).extend(range(cursor, cursor + n))
            cursor += n
        pts = [self.model.verts[i][:3] for i in bone_v + parent_v]
        is_parent = [False] * len(bone_v) + [True] * len(parent_v)
        grid = Grid(pts, 8.0)

        def group_of(corner):
            i = grid.nearest(corner[0])
            return 1 if i is not None and is_parent[i] else 0

        bone_tris, seam, parent_tris = [], [], []
        for corners, mat in tris:
            gs = [group_of(c) for c in corners]
            (bone_tris if sum(gs) == 0 else parent_tris if sum(gs) == 3 else seam).append((corners, mat, gs))

        seams = [[[], set(), set()], [[], set(), set()]]  # per block: triangles, bone keys, parent keys
        rigid = 0
        for corners, mat, gs in seam:
            tex = self.texture(mat.image) if mat.image else None
            kb = {(self.vertex(c, tex, mat), c[0]) for c, gg in zip(corners, gs) if gg == 0}
            kp = {(self.vertex(c, tex, mat), c[0]) for c, gg in zip(corners, gs) if gg == 1}
            for s in seams:
                if len(s[1] | kb) + len(s[2] | kp) <= VERTEX_SLOTS:
                    s[0].append((corners, mat, gs))
                    s[1] |= kb
                    s[2] |= kp
                    break
            else:
                bone_tris.append((corners, mat, [0, 0, 0]))
                rigid += 1
        if rigid:
            warn(f"part {pi}: {rigid} seam triangles did not fit the vertex buffer and follow the bone only")

        first_vertex = len(self.vertices)
        blocks = [(bone_tris, seams[0], parent_tris)]
        if seams[1][0]:
            blocks.append(([], seams[1], []))
        out = []
        for bone_side, (seam_tris, keys_b, keys_p), parent_side in blocks:
            state = {}
            dl = len(self.dl.words)
            first = len(self.vertices)
            self.emit_batches(bone_side, state)
            keys_b, keys_p = sorted(keys_b, key=str), sorted(keys_p, key=str)
            slot = {k: i for i, k in enumerate(keys_b)}
            slot_p = {k: VERTEX_SLOTS - len(keys_p) + i for i, k in enumerate(keys_p)}
            if keys_b:
                self.dl.add(vtx_cmd(0, len(keys_b), self.write_vertices(keys_b)))
            n_bone = len(self.vertices) - first
            self.dl.add(POP_MATRIX)
            first_parent = len(self.vertices)
            if keys_p:
                self.dl.add(vtx_cmd(VERTEX_SLOTS - len(keys_p), len(keys_p), self.write_vertices(keys_p)))
                by_mat = {}
                for tri in seam_tris:
                    by_mat.setdefault(id(tri[1]), []).append(tri)
                for group in by_mat.values():
                    cmds, tex = self.material_cmds(group[0][1], state)
                    self.dl.add(*cmds)
                    self.dl.add(*tri_cmds([[(slot if gg == 0 else slot_p)[(self.vertex(c, tex, group[0][1]), c[0])]
                                             for c, gg in zip(corners, gs)] for corners, _, gs in group]))
            self.emit_batches(parent_side, state)
            self.close_block(state)
            out.append((dl, n_bone, len(self.vertices) - first_parent))
        if len(out) == 1:
            out.append((0, 0, 0))
        return {"dl": out[0][0], "dl_b": out[1][0], "vstart": first_vertex, "tris": len(tris),
                "counts": (out[0][1], out[0][2], out[1][1], out[1][2])}

    def compute_normals(self):
        """A unit normal per position: the mesh's own where it has one, else the average of the faces round it."""
        acc, given = {}, {}
        for tris in self.part_tris.values():
            for corners, _ in tris:
                a, b, c = (p[0] for p in corners)
                u = [b[i] - a[i] for i in range(3)]
                v = [c[i] - a[i] for i in range(3)]
                n = (u[1] * v[2] - u[2] * v[1], u[2] * v[0] - u[0] * v[2], u[0] * v[1] - u[1] * v[0])
                for p in corners:
                    s = acc.setdefault(pos_key(p[0]), [0, 0, 0])
                    for i in range(3):
                        s[i] += n[i]
                    if p[3] is not None:
                        given[pos_key(p[0])] = p[3]
        acc.update(given)
        self.normal_at = {}
        for k, n in acc.items():
            ln = math.sqrt(sum(x * x for x in n)) or 1
            self.normal_at[k] = tuple(x / ln for x in n)

    # -- whole file ---------------------------------------------------------------------------------------------
    def build(self):
        self.assign()
        self.compute_normals()
        # Textures first, so material commands know their addresses.
        for pi in range(len(self.parts)):
            for _, mat in self.part_tris.get(pi, []):
                if mat.image:
                    self.texture(mat.image)
        self.texture_address, addr = {}, 0
        for tex in self.textures:
            self.texture_address[id(tex)] = addr
            addr += (len(tex.data) + 7) & ~7
        self.built = [self.build_part(pi) for pi in range(len(self.parts))]
        if len(self.vertices) > 32767:
            raise ValueError(f"{len(self.vertices)} vertices; a model holds at most 32767")
        return self.write()

    def smooth_normals(self):
        """The 0x38 section's normal per written vertex, as signed bytes."""
        out = []
        for pos in self.vertex_normals:
            n = self.normal_at.get(pos_key(pos), (0, 1, 0))
            out.append(tuple(max(-127, min(127, round(127 * x))) for x in n))
        return out

    def write(self):
        t = self.tdata
        out = bytearray(t[:0x50])

        def align():
            while len(out) % 8:
                out.append(0)

        def put32(o, v):
            struct.pack_into(">I", out, o, v)

        # Textures.
        tex_start = len(out)
        entries = b""
        data = bytearray()
        for tex in self.textures:
            entries += struct.pack(">IBBBB", len(data), 0, tex.kind, tex.w & 0xFF, tex.h & 0xFF)
            data += tex.data
            while len(data) % 8:
                data.append(0)
        out += struct.pack(">IHBB", 8 + len(entries) + len(data), len(self.textures), 0, 0) + entries + data
        struct.pack_into(">H", out, 0x08, tex_start)
        align()

        # Display list.
        put32(0x0C, len(out))
        out += struct.pack(">II", len(self.dl.words), 0)
        for w0, w1 in self.dl.words:
            out += struct.pack(">II", w0 & 0xFFFFFFFF, w1 & 0xFFFFFFFF)
        align()

        # Sections copied as they are: bone table (0x18), collision (0x1C), effects (0x24, end at 0x20) and the
        # unknown 0x2C/0x30, wherever the template has them.
        known = {o: b2o.u32(t, o) for o in (0x04, 0x0C, 0x10, 0x18, 0x1C, 0x24, 0x2C, 0x30, 0x38)}
        known[0x08] = b2o.u16(t, 0x08)
        starts = sorted({v for v in known.values() if 0 < v < len(t)} | {len(t)})

        def extent(off):
            return off, next(s for s in starts if s > off)

        for field, label in ((0x18, "bone table"), (0x1C, "collision"), (0x24, "effects"), (0x2C, "0x2C section"),
                             (0x30, "0x30 section")):
            off = known[field]
            if not (0 < off < len(t)):
                put32(field, 0)
                if field == 0x24:
                    put32(0x20, 0)
                continue
            a, b = extent(off)
            put32(field, len(out))
            if field == 0x24 and b2o.u32(t, 0x20):
                put32(0x20, len(out) + (b2o.u32(t, 0x20) - off))
            out += t[a:b]
            align()
            if field in (0x1C, 0x24, 0x2C, 0x30):
                warn(f"the template's {label} was copied as it is; it may still refer to the old geometry")

        # Vertices.
        put32(0x10, len(out))
        verts = self.vertices or [(0, 0, 0, 0, 0, 0, 0, 0, 0)]
        mn = [min(v[i] for v in verts) for i in range(3)]
        mx = [max(v[i] for v in verts) for i in range(3)]
        centre = [int((mn[i] + mx[i]) / 2) for i in range(3)]
        rc = max(math.dist(v[:3], centre) for v in verts)
        ro = max(math.dist(v[:3], (0, 0, 0)) for v in verts)
        out += struct.pack(">12h", *mn, *mx, *centre, int(rc), int(ro), min(32767, 2 * len(self.vertices)))
        for x, y, z, s, tt, r, g, b, a in self.vertices:
            out += struct.pack(">hhhhhhBBBB", x, y, z, 0, s, tt, r, g, b, a)
        align()

        # Per-vertex normals (header 0x38), when the template has them.
        if 0 < known[0x38] < len(t):
            put32(0x38, len(out))
            for n in self.smooth_normals():
                out += struct.pack(">bbbb", *n, 0)
            out += b"\0\0\0\0"
            align()

        # Geo layout, last as in the game's files, with each drawing command pointed at its new geometry.
        geo_old = known[0x04]
        geo_new = len(out)
        put32(0x04, geo_new)
        out += t[geo_old:]
        for part, built in zip(self.parts, self.built):
            o = part["off"] - geo_old + geo_new
            struct.pack_into(">H", out, o + 8, built["dl"])
            if part["cmd"] == 0x03:
                struct.pack_into(">H", out, o + 10, min(0xFFFF, built["tris"]))
            elif part["cmd"] == 0x11:
                struct.pack_into(">HH", out, o + 10, built["vstart"], built["vcount"])
            elif part["cmd"] == 0x18:
                # Bone and parent counts: block A's in the high halves, block B's bone count beside A's parent
                # count and B's parent count beside A's bone count, as the game's files have them.
                a_bone, a_parent, b_bone, b_parent = built["counts"]
                struct.pack_into(">H", out, o + 10, built["dl_b"])
                struct.pack_into(">HH", out, o + 0x14, a_bone, b_parent)
                struct.pack_into(">HH", out, o + 0x20, a_parent, b_bone)
                struct.pack_into(">H", out, o + 0x2C, built["vstart"])

        total_tris = sum(b["tris"] for b in self.built)
        struct.pack_into(">HH", out, 0x44, min(0xFFFF, total_tris), len(self.vertices))
        return bytes(out), total_tris


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("mesh", help="edited model: .glb, .gltf or .obj")
    ap.add_argument("-t", "--template", required=True, help="the original asset_XXXX.bin the mesh was made from")
    ap.add_argument("-o", "--out", help="output .bin (default: asset_XXXX.bin beside the mesh, named as the template)")
    ap.add_argument("--scale", type=float, help="multiply positions by this (default 100 for glTF, 1 for .obj)")
    args = ap.parse_args()

    ext = os.path.splitext(args.mesh)[1].lower()
    if ext in (".glb", ".gltf"):
        objects = read_gltf(args.mesh, 100.0 if args.scale is None else args.scale)
    elif ext == ".obj":
        objects = read_obj(args.mesh, 1.0 if args.scale is None else args.scale)
    else:
        sys.exit("give a .glb, .gltf or .obj")
    builder = Builder(args.template, objects)
    data, tris = builder.build()
    out = args.out or os.path.join(os.path.dirname(os.path.abspath(args.mesh)), os.path.basename(args.template))
    if os.path.abspath(out) == os.path.abspath(args.template):
        sys.exit("refusing to overwrite the template; give -o")
    with open(out, "wb") as f:
        f.write(data)
    print(f"{out}: {tris} triangles, {len(builder.vertices)} vertices, {len(builder.textures)} textures, "
          f"{len(builder.parts)} parts, {len(data)} bytes")


if __name__ == "__main__":
    main()
