# The small creatures of the 3D grass (rt64-ext/src/render/rt64_critters.cpp), modelled in Blender.
#
# Run inside Blender (Text editor > Run Script, or exec(open(path).read())): builds every creature in a scene of its own,
# "Critters", leaving the rest of the file alone, from shaped primitives with vertex colours, round eyes with pupils and
# the parts that move (wings, legs, claws, flippers) marked; then call export() to write the meshes for the game:
# rt64-ext/src/shared/rt64_critter_meshes.h (the vertices, packed) and rt64-ext/src/shaders/CritterMeshes.hlsli (where
# each kind's vertices start, how many, and each moving part's pivot).
#
# The frame is the game's: +X forward (the nose), +Z up, and the creature's right at -Y (the game's local "across" is
# -Y here). A body is about 2 long (X from -1 to 1): the game scales it to the creature's size. Ground creatures (frog,
# crab, a resting bird) have their feet at Z = 0.
#
# Each face carries: its colour (a corner colour, so a body can shade lighter to its belly), a paint slot (0: the colour
# as it is; 1, 2, 3: the kind's variant colours, the colour then a multiplier; 4: a firefly's glow), the part it belongs
# to (0 the body, 1 to 6 parts that move) and whether it is flat (a wing or fin, lit from whichever side the camera is).

import bpy
import bmesh
import math
from mathutils import Vector, Matrix, Euler

SCENE = "Critters"

# Kinds, in the game's order (shared/rt64_critters.h's CRITTER_*).
KINDS = ["bee", "butterfly", "dragonfly", "moth", "firefly", "beetle", "fly", "fish", "bird", "frog", "crab", "turtle", "ray", "bubble", "eye"]

# The kinds' colour variants (Critter.look.y): for each kind and paint slot, a colour a variant (slot 1: its main
# colour, 2: its second, 3: its third, 4: a firefly's glow). A face in a slot shows that colour times its own (a
# grey, which can go over 1 for a paler belly). Exported to the shader with the meshes.
PALETTES = {
    "butterfly": {1: [(1.0, 0.88, 0.15), (1.0, 0.5, 0.08), (0.2, 0.55, 1.0), (0.97, 0.97, 0.92), (0.86, 0.94, 1.0), (0.9, 0.12, 0.1), (1.0, 0.62, 0.82), (0.75, 0.6, 1.0)],
                  2: [(0.95, 0.6, 0.08), (0.25, 0.12, 0.05), (0.08, 0.15, 0.45), (0.75, 0.78, 0.5), (0.5, 0.7, 0.95), (0.08, 0.06, 0.06), (0.6, 0.95, 0.95), (1.0, 0.85, 0.5)]},
    "dragonfly": {1: [(0.15, 0.55, 1.0), (0.25, 0.85, 0.35), (0.95, 0.18, 0.1)], 2: [(0.3, 0.75, 1.0), (0.5, 0.95, 0.5), (1.0, 0.45, 0.2)]},
    "moth": {1: [(0.62, 0.48, 0.32), (0.95, 0.9, 0.75), (0.62, 0.62, 0.6), (0.95, 0.38, 0.1), (0.85, 0.95, 1.0)]},
    "firefly": {4: [(0.92, 1.0, 0.42), (1.0, 0.62, 0.2)]},
    "beetle": {1: [(0.92, 0.1, 0.06), (0.15, 0.72, 0.3), (0.42, 0.25, 0.12)]},
    "fish": {1: [(1.0, 0.45, 0.08), (1.0, 0.86, 0.12), (0.15, 0.45, 1.0), (0.95, 0.16, 0.16), (0.3, 0.82, 0.32), (0.62, 0.3, 0.92)],
             2: [(0.98, 0.98, 0.95), (0.15, 0.35, 0.95), (1.0, 0.86, 0.12), (1.0, 0.85, 0.2), (1.0, 0.95, 0.4), (1.0, 0.55, 0.85)]},
    "bird": {1: [(0.2, 0.45, 0.95), (0.96, 0.96, 0.94), (0.12, 0.12, 0.14), (0.5, 0.32, 0.18)],
             2: [(0.98, 0.95, 0.9), (0.98, 0.98, 0.98), (0.2, 0.2, 0.24), (0.95, 0.3, 0.12)],
             3: [(1.0, 0.6, 0.1), (1.0, 0.82, 0.1), (0.45, 0.45, 0.48), (0.95, 0.75, 0.2)]},
    "frog": {1: [(0.25, 0.72, 0.18), (0.55, 0.42, 0.22), (0.92, 0.2, 0.12)]},
    "crab": {1: [(0.92, 0.22, 0.1), (0.95, 0.55, 0.15)]},
}
SLOTS = 5
VARIANTS = 8

WHITE = (0.97, 0.97, 0.95)


def sphere_detail(radii, segs, rings):
    """How many segments and rings a round part gets for its size (the average of its two largest radii, the body
    being about 1 across): a body a smooth 8 by 6, smaller parts fewer and fewer (they are a few pixels in the game),
    never more than asked for. Keeps a creature to a few hundred triangles."""
    r = sorted(radii)
    size = 0.5 * (r[1] + r[2])
    if size >= 0.4:
        tier = (8, 6)
    elif size >= 0.2:
        tier = (6, 5)
    elif size >= 0.1:
        tier = (6, 4)
    elif size >= 0.05:
        tier = (4, 3)
    else:
        tier = (3, 3)
    return min(segs, tier[0]), min(rings, tier[1])


def cone_detail(radius, segs):
    """Likewise for a cone or stick: a thin leg or antenna gets three sides."""
    if radius < 0.05:
        return 3
    if radius < 0.1:
        return min(segs, 4)
    return min(segs, 6)
BLACK = (0.05, 0.05, 0.06)


def lerp3(a, b, t):
    return tuple(a[i] + (b[i] - a[i]) * t for i in range(3))


class Creature:
    """A creature being built: one bmesh, with per-face slot, part and flat layers and per-corner colours."""

    def __init__(self, name):
        self.name = name
        self.bm = bmesh.new()
        self.col = self.bm.loops.layers.float_color.new("col")
        self.slot = self.bm.faces.layers.int.new("slot")
        self.part = self.bm.faces.layers.int.new("part")
        self.flat_layer = self.bm.faces.layers.int.new("flat")
        # Each moving part's pivot (in the game's frame; filled by the parts).
        self.pivots = {}

    def _take(self, tmp, matrix, paint, slot, part, flat, smooth=True):
        """Copies a temporary bmesh in, moved by matrix, its corners coloured by paint(position, normal, face)."""
        bmesh.ops.transform(tmp, matrix=matrix, verts=tmp.verts)
        tmp.normal_update()
        vmap = {}
        for v in tmp.verts:
            vmap[v] = self.bm.verts.new(v.co)
        for f in tmp.faces:
            try:
                nf = self.bm.faces.new([vmap[v] for v in f.verts])
            except ValueError:
                continue
            nf.smooth = smooth
            nf[self.slot] = slot
            nf[self.part] = part
            nf[self.flat_layer] = flat
            centre = f.calc_center_median()
            for loop, oloop in zip(nf.loops, f.loops):
                loop[self.col] = (*paint(oloop.vert.co, oloop.vert.normal, centre, f.normal), 1.0)
        tmp.free()

    def ellipsoid(self, centre, radii, paint, segs=10, rings=7, rot=(0, 0, 0), slot=0, part=0, smooth=True, pole='x'):
        """An ellipsoid of the given radii (along X, Y, Z before rot), its poles along pole: along X for a body, so its
        rings run across it (clean stripes and bands)."""
        segs, rings = sphere_detail(radii, segs, rings)
        tmp = bmesh.new()
        bmesh.ops.create_uvsphere(tmp, u_segments=segs, v_segments=rings, radius=1.0)
        turn = {'x': Euler((0, math.pi / 2, 0)), 'y': Euler((math.pi / 2, 0, 0)), 'z': Euler((0, 0, 0))}[pole]
        m = (Matrix.Translation(Vector(centre)) @ Euler(rot).to_matrix().to_4x4() @ Matrix.Diagonal((*radii, 1.0)) @
             turn.to_matrix().to_4x4())
        self._take(tmp, m, paint, slot, part, 0, smooth)

    def cone(self, base, tip, r1, r2, paint, segs=8, slot=0, part=0, smooth=True, caps=True):
        tmp = bmesh.new()
        base, tip = Vector(base), Vector(tip)
        axis = tip - base
        length = axis.length
        segs = cone_detail(max(r1, r2), segs)
        # (A thin stick's ends are hidden in what it joins: no caps.)
        caps = caps and max(r1, r2) >= 0.05
        bmesh.ops.create_cone(tmp, cap_ends=caps, cap_tris=False, segments=segs, radius1=r1, radius2=r2, depth=length)
        # create_cone is centred on Z: move it to start at Z = 0, then turn Z onto the axis.
        rotation = axis.to_track_quat('Z', 'Y').to_matrix().to_4x4()
        m = Matrix.Translation(base) @ rotation @ Matrix.Translation((0, 0, length / 2))
        self._take(tmp, m, paint, slot, part, 0, smooth)

    def flat(self, outline, paint, slot=0, part=0, z=0.0, rot=None, origin=(0, 0, 0)):
        """A flat shape (a wing or fin) from an outline of (x, y) points in its plane, as a fan from its middle."""
        tmp = bmesh.new()
        cx = sum(p[0] for p in outline) / len(outline)
        cy = sum(p[1] for p in outline) / len(outline)
        centre = tmp.verts.new((cx, cy, z))
        ring = [tmp.verts.new((p[0], p[1], z)) for p in outline]
        for i in range(len(ring)):
            tmp.faces.new((centre, ring[i], ring[(i + 1) % len(ring)]))
        m = Matrix.Translation(Vector(origin))
        if rot is not None:
            m = m @ Euler(rot).to_matrix().to_4x4()
        m = m @ Matrix.Translation(-Vector(origin))
        self._take(tmp, m, paint, slot, part, 1, smooth=False)

    def eye(self, centre, radius, look, pupil=0.62, iris=None, part=0, segs=10, rings=7):
        """A round eye: white, with a round black pupil (and a coloured ring round it) facing look."""
        look = Vector(look).normalized()

        def paint(co, normal, face_centre, face_normal):
            d = (Vector(face_centre) - Vector(centre)).normalized().dot(look)
            if d > pupil + (1.0 - pupil) * 0.45:
                return BLACK
            if iris is not None and d > pupil:
                return iris
            return WHITE
        segs, rings = min(segs, 8), min(rings, 5)
        tmp = bmesh.new()
        bmesh.ops.create_uvsphere(tmp, u_segments=segs, v_segments=rings, radius=radius)
        # (Its poles turned to look, so the pupil is round.)
        rotation = look.to_track_quat('Z', 'Y').to_matrix().to_4x4()
        self._take(tmp, Matrix.Translation(Vector(centre)) @ rotation, paint, 0, part, 0, True)

    def pivot(self, part, point):
        self.pivots[part] = point

    def finish(self, collection, place):
        bmesh.ops.triangulate(self.bm, faces=self.bm.faces)
        # (A second corner colour, "preview": the colour the game shows for variant 0, to look at in Blender.)
        preview = self.bm.loops.layers.float_color.new("preview")
        palette = PALETTES.get(self.name, {})
        for f in self.bm.faces:
            slot = f[self.slot]
            tint = palette.get(slot, [(1.0, 1.0, 1.0)])[0] if slot != 0 else (1.0, 1.0, 1.0)
            for loop in f.loops:
                c = loop[self.col]
                loop[preview] = (min(c[0] * tint[0], 1.0), min(c[1] * tint[1], 1.0), min(c[2] * tint[2], 1.0), 1.0)
        mesh = bpy.data.meshes.new(self.name)
        self.bm.to_mesh(mesh)
        self.bm.free()
        obj = bpy.data.objects.new(self.name, mesh)
        collection.objects.link(obj)
        obj.location = place
        obj["pivots"] = {str(k): list(v) for k, v in self.pivots.items()}
        # (A material showing the corner colours, to look at them in Blender.)
        mat = bpy.data.materials.get("CritterColours") or bpy.data.materials.new("CritterColours")
        mat.use_nodes = True
        nodes = mat.node_tree.nodes
        bsdf = next(n for n in nodes if n.type == 'BSDF_PRINCIPLED')
        attr = next((n for n in nodes if n.type == 'VERTEX_COLOR'), None) or nodes.new('ShaderNodeVertexColor')
        attr.layer_name = "preview"
        mat.node_tree.links.new(attr.outputs[0], bsdf.inputs[0])
        bsdf.inputs["Roughness"].default_value = 0.8
        mesh.materials.append(mat)
        return obj


def solid(c):
    return lambda co, n, fc, fn: c


def shaded(top, bottom, centre_z=0.0, spread=1.0):
    """Lighter on top, the bottom's colour underneath, by the corner's normal."""
    def paint(co, n, fc, fn):
        t = max(0.0, min(1.0, 0.5 + 0.5 * n.z / spread))
        return lerp3(bottom, top, t)
    return paint


# --- Helpers for the creatures -------------------------------------------------------------------------------------

def solid(c):
    return lambda co, n, fc, fn: c


def shaded(top, bottom):
    """The top colour on top, fading to the bottom colour underneath (by each corner's normal)."""
    def paint(co, n, fc, fn):
        t = max(0.0, min(1.0, 0.5 + 0.5 * n.z))
        return lerp3(bottom, top, t)
    return paint


def grey(v):
    return (v, v, v)


def mirror_outline(outline, root, side):
    """An outline drawn for the right side (out along -Y from its root), placed at root, mirrored for the left."""
    return [(root[0] + x, root[1] - y * side) for x, y in outline]


def wing_pair(c, outline, root, z, paint_right, part_right, slot=0, paint_left=None):
    """A pair of wings (part_right on the right, part_right + 1 on the left), pivoting at their roots."""
    for part, side in ((part_right, -1), (part_right + 1, 1)):
        r = (root[0], abs(root[1]) * side, z)
        c.flat(mirror_outline(outline, r, side), paint_right if side == -1 or paint_left is None else paint_left,
               slot=slot, part=part, z=z)
        c.pivot(part, r)


def legs(c, points, colour, side_y, thick=0.03, slot=0, part=0):
    """Thin legs from (x, z) roots at side_y out to feet."""
    for side in (1, -1):
        for (x0, z0, x1, y1, z1) in points:
            c.cone((x0, side_y * side, z0), (x1, y1 * side, z1), thick, thick * 0.6, colour, segs=4, caps=False, slot=slot, part=part)


# Insect wings: rounded outlines (right side, out along -Y).
ROUND_WING = [(0.12, 0.0), (0.2, -0.25), (0.15, -0.6), (0.0, -0.85), (-0.25, -0.92), (-0.45, -0.8), (-0.48, -0.5), (-0.3, -0.18), (-0.12, -0.02)]
LONG_WING = [(0.06, 0.0), (0.1, -0.3), (0.1, -0.8), (0.04, -1.15), (-0.06, -1.25), (-0.14, -1.15), (-0.13, -0.6), (-0.08, -0.15), (-0.05, 0.0)]
BUTTERFLY_FORE = [(0.1, 0.0), (0.35, -0.35), (0.62, -0.95), (0.55, -1.25), (0.25, -1.35), (-0.1, -1.15), (-0.25, -0.7), (-0.2, -0.25), (-0.1, -0.02)]
BUTTERFLY_HIND = [(0.05, 0.0), (-0.05, -0.45), (-0.25, -0.85), (-0.6, -0.95), (-0.85, -0.7), (-0.75, -0.35), (-0.45, -0.1), (-0.15, 0.0)]
MOTH_FORE = [(0.1, 0.0), (0.25, -0.4), (0.3, -0.95), (0.05, -1.1), (-0.35, -0.85), (-0.45, -0.45), (-0.3, -0.12)]
MOTH_HIND = [(0.0, 0.0), (-0.15, -0.5), (-0.4, -0.75), (-0.7, -0.55), (-0.6, -0.2), (-0.3, 0.0)]


def wing_paint(inner, edge, edge_from=0.7, span=1.3):
    """A wing's colour: inner near its root, edge out at its rim (by how far out the face is)."""
    def paint(co, n, fc, fn):
        t = abs(fc.y) / span
        return edge if t > edge_from else inner
    return paint


# --- The creatures -------------------------------------------------------------------------------------------------

def make_bee(c):
    yellow, black, gold = (1.0, 0.78, 0.08), (0.07, 0.06, 0.06), (0.95, 0.62, 0.14)

    def stripes(co, n, fc, fn):
        band = int(math.floor((fc.x + 1.02) / 0.2))
        base = black if band % 2 == 0 else yellow
        return lerp3(base, tuple(x * 0.75 for x in base), max(0.0, -n.z) * 0.6)
    c.ellipsoid((-0.38, 0, 0.0), (0.62, 0.5, 0.5), stripes, segs=10, rings=10)
    c.cone((-0.95, 0, -0.02), (-1.15, 0, -0.05), 0.07, 0.0, solid(black), segs=5)
    c.ellipsoid((0.25, 0, 0.05), (0.32, 0.36, 0.36), shaded(gold, (0.72, 0.45, 0.1)), segs=8, rings=6)
    c.ellipsoid((0.65, 0, 0.05), (0.27, 0.3, 0.29), shaded((0.18, 0.15, 0.15), black), segs=8, rings=6)
    for side in (1, -1):
        c.eye((0.78, 0.17 * side, 0.15), 0.13, (1.0, 0.75 * side, 0.25), segs=8, rings=6)
        c.cone((0.78, 0.08 * side, 0.3), (0.92, 0.16 * side, 0.6), 0.025, 0.02, solid(black), segs=4, caps=False)
        c.ellipsoid((0.93, 0.165 * side, 0.62), (0.045, 0.045, 0.045), solid(black), segs=5, rings=4)
    legs(c, [(0.42, -0.18, 0.34, 0.32, -0.48), (0.25, -0.2, 0.17, 0.34, -0.5), (0.05, -0.2, -0.05, 0.3, -0.48)], solid(black), 0.15)
    wing_pair(c, ROUND_WING, (0.3, 0.15), 0.38, solid((0.86, 0.93, 1.0)), 1)


def make_butterfly(c):
    dark = (0.18, 0.14, 0.12)
    c.ellipsoid((-0.25, 0, 0.0), (0.6, 0.11, 0.11), shaded((0.28, 0.22, 0.18), dark), segs=8, rings=8)
    c.ellipsoid((0.38, 0, 0.02), (0.18, 0.15, 0.15), shaded((0.3, 0.24, 0.2), dark), segs=8, rings=6)
    c.ellipsoid((0.62, 0, 0.04), (0.13, 0.14, 0.13), solid(dark), segs=8, rings=6)
    for side in (1, -1):
        c.eye((0.68, 0.1 * side, 0.08), 0.07, (0.6, 1.0 * side, 0.2), pupil=0.3, segs=6, rings=5)
        c.cone((0.7, 0.04 * side, 0.12), (1.05, 0.25 * side, 0.55), 0.015, 0.012, solid(dark), segs=4, caps=False)
        c.ellipsoid((1.06, 0.255 * side, 0.56), (0.05, 0.035, 0.035), solid(dark), segs=5, rings=4)
    # Wings: the variant's colour (slot 1) inside, its second colour (slot 2) round the rim, a white spot near each tip.
    def fore(co, n, fc, fn):
        t = abs(fc.y) / 1.3
        return grey(1.0) if t < 0.72 else grey(1.0)
    wing_pair(c, BUTTERFLY_FORE, (0.32, 0.1), 0.06, solid(grey(1.0)), 1, slot=1)
    wing_pair(c, BUTTERFLY_HIND, (0.12, 0.1), 0.04, solid(grey(1.0)), 3, slot=2)
    # Rims and spots, laid a hair above the wings (same parts, so they move with them).
    rim = [(x * 1.0, y * 1.0) for x, y in BUTTERFLY_FORE[2:6]]
    for part, side in ((1, -1), (2, 1)):
        root = (0.32, 0.1 * side, 0.065)
        tip = [(0.62, -0.95), (0.55, -1.25), (0.25, -1.35), (0.3, -1.05)]
        c.flat(mirror_outline(tip, root, side), solid(grey(1.0)), slot=2, part=part, z=0.065)
        spot = [(0.35 + 0.08 * math.cos(a), -0.95 + 0.08 * math.sin(a)) for a in [i * math.pi / 3 for i in range(6)]]
        c.flat(mirror_outline(spot, root, side), solid(WHITE), slot=0, part=part, z=0.07)


def make_dragonfly(c):
    # A long thin tail of beads, a thick thorax, a big head that is nearly all eyes, and four long clear wings.
    for i in range(7):
        x = -0.95 + i * 0.16
        c.ellipsoid((x, 0, 0.0), (0.09, 0.06, 0.06), shaded(grey(1.0), grey(0.55)), segs=6, rings=4, slot=1)
    c.ellipsoid((0.35, 0, 0.03), (0.26, 0.15, 0.16), shaded(grey(1.0), grey(0.6)), segs=8, rings=6, slot=1)
    c.ellipsoid((0.66, 0, 0.05), (0.12, 0.14, 0.12), shaded(grey(0.9), grey(0.5)), segs=8, rings=6, slot=1)
    for side in (1, -1):
        c.ellipsoid((0.72, 0.12 * side, 0.1), (0.12, 0.12, 0.12), shaded(grey(1.25), grey(0.7)), segs=8, rings=6, slot=2, pole='y')
    legs(c, [(0.4, -0.12, 0.45, 0.2, -0.3), (0.3, -0.12, 0.25, 0.22, -0.3)], solid(grey(0.12)), 0.08, thick=0.02)
    clear = wing_paint((0.85, 0.94, 1.0), (0.35, 0.4, 0.45), edge_from=0.9, span=1.25)
    wing_pair(c, LONG_WING, (0.42, 0.1), 0.12, clear, 1)
    wing_pair(c, LONG_WING, (0.26, 0.1), 0.1, clear, 3)


def make_moth(c):
    def fuzzy(co, n, fc, fn):
        return lerp3(grey(0.7), grey(1.0), max(0.0, min(1.0, 0.5 + 0.5 * n.z)))
    c.ellipsoid((-0.25, 0, 0.0), (0.6, 0.3, 0.3), fuzzy, segs=8, rings=8, slot=1)
    c.ellipsoid((0.35, 0, 0.04), (0.25, 0.28, 0.27), fuzzy, segs=8, rings=6, slot=1)
    c.ellipsoid((0.62, 0, 0.06), (0.15, 0.17, 0.16), solid(grey(0.75)), segs=8, rings=6, slot=1)
    for side in (1, -1):
        c.eye((0.7, 0.12 * side, 0.12), 0.08, (0.6, 1.0 * side, 0.2), pupil=0.3, segs=6, rings=5)
        # Feathery antennae: a flat leaf each.
        ant = [(0.0, 0.0), (0.2, -0.05), (0.38, -0.12), (0.3, -0.18), (0.12, -0.12)]
        c.flat(mirror_outline(ant, (0.72, 0.05 * side, 0.2), side), solid(grey(0.55)), slot=1, z=0.25)
    wing_pair(c, MOTH_FORE, (0.3, 0.2), 0.12, wing_paint(grey(1.0), grey(0.72), 0.75, 1.1), 1, slot=1)
    wing_pair(c, MOTH_HIND, (0.05, 0.2), 0.1, solid(grey(0.85)), 3, slot=1)


def make_firefly(c):
    brown = (0.25, 0.18, 0.12)
    # The big glowing tail (slot 4: lit by its glow), a dark thorax with an orange collar, a small head.
    c.ellipsoid((-0.4, 0, -0.03), (0.55, 0.42, 0.4), solid(grey(1.0)), segs=10, rings=8, slot=4)
    c.ellipsoid((0.25, 0, 0.05), (0.3, 0.32, 0.3), shaded((0.95, 0.5, 0.18), (0.6, 0.28, 0.1)), segs=8, rings=6)
    c.ellipsoid((0.58, 0, 0.05), (0.16, 0.18, 0.17), solid(brown), segs=8, rings=6)
    for side in (1, -1):
        c.eye((0.66, 0.12 * side, 0.1), 0.08, (0.6, 1.0 * side, 0.2), pupil=0.3, segs=6, rings=5)
        c.cone((0.68, 0.05 * side, 0.15), (0.95, 0.2 * side, 0.45), 0.015, 0.012, solid(brown), segs=4, caps=False)
    # Wing cases over its back (still) and clear wings beating (parts 1, 2).
    for side in (1, -1):
        case = [(0.25, 0.0), (0.1, -0.32), (-0.4, -0.36), (-0.75, -0.18), (-0.7, 0.0)]
        c.flat(mirror_outline(case, (0.0, 0.0, 0.33), side), solid(brown), z=0.33)
    wing_pair(c, ROUND_WING, (0.25, 0.12), 0.36, solid((0.75, 0.72, 0.62)), 1)


def make_beetle(c):
    # A domed shell in two halves (slot 1, with spots in slot 2 on a ladybird), a black head and legs.
    for side in (1, -1):
        def shell(co, n, fc, fn, side=side):
            # (Spots: on a few faces of the top, set by their place.)
            sx, sz = fc.x, abs(fc.y)
            spot = any((sx - px) ** 2 + (sz - py) ** 2 < 0.018 for px, py in ((-0.35, 0.3), (0.1, 0.42), (-0.6, 0.12), (0.25, 0.18)))
            return (0.04, 0.04, 0.05) if spot else lerp3(grey(0.7), grey(1.0), max(0.0, min(1.0, 0.5 + 0.5 * n.z)))
        c.ellipsoid((-0.15, 0.0, 0.05), (0.72, 0.62, 0.48), shell, segs=12, rings=8, slot=1)
        break
    c.ellipsoid((-0.15, 0, -0.1), (0.7, 0.58, 0.18), solid((0.08, 0.07, 0.07)), segs=10, rings=5)
    c.ellipsoid((0.62, 0, 0.0), (0.2, 0.3, 0.2), solid((0.07, 0.06, 0.06)), segs=8, rings=6)
    # The line down the middle where the shell halves meet.
    c.flat([(0.45, -0.015), (0.45, 0.015), (-0.85, 0.015), (-0.85, -0.015)], solid((0.05, 0.05, 0.05)), z=0.535)
    for side in (1, -1):
        c.eye((0.74, 0.14 * side, 0.08), 0.08, (0.6, 1.0 * side, 0.2), pupil=0.3, segs=6, rings=5)
        c.cone((0.75, 0.08 * side, 0.12), (1.0, 0.25 * side, 0.3), 0.015, 0.012, solid(BLACK), segs=4, caps=False)
    legs(c, [(0.3, -0.12, 0.45, 0.75, -0.3), (0.0, -0.12, 0.0, 0.8, -0.32), (-0.3, -0.12, -0.45, 0.75, -0.3)], solid(BLACK), 0.4, thick=0.035)
    # Flying wings (parts 1, 2), folded away under the shell when it rests.
    wing_pair(c, LONG_WING, (0.1, 0.25), 0.45, solid((0.82, 0.82, 0.86)), 1)


def make_fly(c):
    grey_body = (0.28, 0.28, 0.3)
    c.ellipsoid((-0.35, 0, 0.0), (0.5, 0.36, 0.33), shaded(grey_body, (0.15, 0.15, 0.17)), segs=8, rings=8)
    c.ellipsoid((0.2, 0, 0.05), (0.32, 0.32, 0.3), shaded((0.22, 0.24, 0.22), (0.1, 0.1, 0.1)), segs=8, rings=6)
    c.ellipsoid((0.58, 0, 0.05), (0.2, 0.26, 0.22), solid((0.12, 0.12, 0.13)), segs=8, rings=6)
    for side in (1, -1):
        # Big red eyes.
        c.ellipsoid((0.62, 0.17 * side, 0.12), (0.16, 0.16, 0.16), shaded((0.9, 0.2, 0.12), (0.45, 0.06, 0.05)), segs=8, rings=6, pole='y')
    legs(c, [(0.3, -0.15, 0.4, 0.4, -0.45), (0.1, -0.15, 0.05, 0.42, -0.47), (-0.1, -0.15, -0.25, 0.38, -0.45)], solid(BLACK), 0.15, thick=0.03)
    wing_pair(c, ROUND_WING, (0.25, 0.12), 0.32, solid((0.78, 0.82, 0.86)), 1)


def make_fish(c):
    # A deep, flat body (slot 1, a paler belly), a band of the second colour (slot 2), fins of the second colour, big
    # eyes, a little mouth. The tail swings with the game's swish (by how far back a corner is).
    def body(co, n, fc, fn):
        t = max(0.0, min(1.0, 0.5 + 0.5 * n.z))
        return lerp3(grey(1.45), grey(1.0), t)

    def band(co, n, fc, fn):
        return grey(1.0)
    c.ellipsoid((0.0, 0, 0.0), (0.9, 0.3, 0.48), body, segs=12, rings=10, slot=1)
    c.ellipsoid((-0.05, 0, 0.0), (0.2, 0.315, 0.49), band, segs=12, rings=6, slot=2, pole='z')
    c.ellipsoid((0.86, 0, -0.08), (0.08, 0.12, 0.06), solid((0.35, 0.12, 0.1)), segs=6, rings=4)
    for side in (1, -1):
        c.eye((0.55, 0.22 * side, 0.12), 0.14, (0.5, 1.0 * side, 0.1), pupil=0.45, segs=8, rings=6)
        fin = [(0.0, 0.0), (-0.05, -0.12), (-0.3, -0.32), (-0.35, -0.1)]
        c.flat(mirror_outline(fin, (0.3, 0.26 * side, -0.15), side), solid(grey(1.0)), slot=2, z=-0.15)
    tail = [(0.0, 0.0), (-0.45, 0.45), (-0.38, 0.0), (-0.45, -0.45)]
    c.flat([(-0.82 + x, z) for x, z in tail], solid(grey(1.0)), slot=2, rot=(math.pi / 2, 0, 0), origin=(0, 0, 0))
    dorsal = [(0.25, 0.0), (-0.1, 0.32), (-0.45, 0.3), (-0.5, 0.0)]
    c.flat([(x, z + 0.42) for x, z in dorsal], solid(grey(1.0)), slot=2, rot=(math.pi / 2, 0, 0), origin=(0, 0, 0))


def make_bird(c):
    # A round body (slot 1 on top, slot 2 its front and belly), a round head, a short beak (slot 3), eyes, broad
    # wings (parts 1, 2) and a fanned tail, little legs. Feet at Z = 0.
    def body(co, n, fc, fn):
        return grey(1.0)
    def belly(co, n, fc, fn):
        return grey(1.0)
    c.ellipsoid((-0.1, 0, 0.62), (0.62, 0.42, 0.42), solid(grey(1.0)), segs=10, rings=8, slot=1, rot=(0, 0.25, 0))
    c.ellipsoid((0.12, 0, 0.55), (0.45, 0.37, 0.36), solid(grey(1.0)), segs=10, rings=6, slot=2, rot=(0, 0.25, 0))
    c.ellipsoid((0.5, 0, 0.95), (0.3, 0.29, 0.29), solid(grey(1.0)), segs=10, rings=7, slot=1)
    c.cone((0.74, 0, 0.92), (1.02, 0, 0.88), 0.09, 0.0, solid(grey(1.0)), segs=6, slot=3)
    for side in (1, -1):
        c.eye((0.66, 0.17 * side, 1.02), 0.09, (0.5, 1.0 * side, 0.15), pupil=0.35, segs=8, rings=6)
        c.cone((0.05, 0.12 * side, 0.3), (0.08, 0.13 * side, 0.0), 0.03, 0.025, solid((0.9, 0.6, 0.2)), segs=4, caps=False)
        c.flat(mirror_outline([(0.0, 0.0), (0.15, -0.05), (0.15, 0.05)], (0.08, 0.13 * side, 0.01), side), solid((0.9, 0.6, 0.2)), z=0.01)
    wing = [(0.25, 0.0), (0.3, -0.4), (0.1, -0.95), (-0.15, -1.35), (-0.35, -1.0), (-0.45, -0.5), (-0.4, 0.0)]
    wing_pair(c, wing, (0.05, 0.3), 0.75, wing_paint(grey(0.85), grey(0.6), 0.8, 1.35), 1, slot=1)
    tail = [(0.0, 0.0), (-0.45, 0.22), (-0.55, 0.0), (-0.45, -0.22)]
    c.flat([(-0.6 + x, y) for x, y in tail], solid(grey(0.8)), slot=1, part=5, z=0.62)


def make_frog(c):
    # Sitting: hips low at the back, the body sloping up to a wide head. Feet at Z = 0. Slot 1: its skin.
    belly_tint = 1.6

    def skin(co, n, fc, fn):
        t = max(0.0, min(1.0, 0.5 + 0.5 * n.z))
        return lerp3(grey(belly_tint), grey(1.0), min(1.0, t * 1.6))
    dark = (0.15, 0.35, 0.1)
    c.ellipsoid((-0.18, 0, 0.42), (0.62, 0.55, 0.4), skin, segs=10, rings=7, rot=(0, -0.35, 0), slot=1)
    c.ellipsoid((0.38, 0, 0.62), (0.42, 0.52, 0.3), skin, segs=10, rings=7, rot=(0, -0.15, 0), slot=1)
    c.ellipsoid((0.5, 0, 0.56), (0.32, 0.47, 0.03), solid(grey(0.35)), segs=12, rings=3, rot=(0, -0.15, 0), slot=1)
    for side in (1, -1):
        c.ellipsoid((0.42, 0.3 * side, 0.82), (0.17, 0.17, 0.15), skin, segs=6, rings=3, slot=1, pole='z')
        c.eye((0.47, 0.31 * side, 0.92), 0.15, (0.75, 0.6 * side, 0.3), pupil=0.55, segs=8, rings=6)
        c.cone((0.35, 0.38 * side, 0.35), (0.45, 0.45 * side, 0.03), 0.08, 0.06, skin, segs=6, slot=1, caps=False)
        c.ellipsoid((0.52, 0.48 * side, 0.02), (0.14, 0.1, 0.03), solid(grey(0.9)), segs=5, rings=3, slot=1)
    for part, side in ((1, -1), (2, 1)):
        hip = (-0.45, 0.42 * side, 0.32)
        c.ellipsoid((-0.15, 0.55 * side, 0.3), (0.38, 0.16, 0.18), skin, segs=6, rings=4, rot=(0, -0.25, 0), slot=1, part=part)
        c.ellipsoid((-0.28, 0.62 * side, 0.12), (0.36, 0.1, 0.1), skin, segs=5, rings=3, rot=(0, 0.3, 0), slot=1, part=part)
        c.ellipsoid((0.05, 0.66 * side, 0.03), (0.3, 0.13, 0.03), solid(grey(0.9)), segs=5, rings=3, slot=1, part=part)
        c.pivot(part, hip)


def make_crab(c):
    # A wide, low shell (slot 1) on its legs, eyes on stalks, two big claws (parts 1, 2) and four legs a side (parts
    # 3, 4). Feet at Z = 0.
    def shell(co, n, fc, fn):
        t = max(0.0, min(1.0, 0.5 + 0.5 * n.z))
        return lerp3(grey(1.5), grey(1.0), t)
    c.ellipsoid((0.0, 0, 0.42), (0.55, 0.75, 0.3), shell, segs=12, rings=8, slot=1, pole='z')
    for side in (1, -1):
        c.cone((0.4, 0.15 * side, 0.6), (0.48, 0.18 * side, 0.85), 0.04, 0.035, solid(grey(0.9)), segs=4, caps=False, slot=1)
        c.eye((0.49, 0.18 * side, 0.9), 0.08, (1.0, 0.3 * side, 0.3), pupil=0.4, segs=6, rings=5)
    for part, side in ((1, -1), (2, 1)):
        root = (0.35, 0.55 * side, 0.4)
        c.cone(root, (0.65, 0.75 * side, 0.4), 0.07, 0.06, shell, segs=5, caps=False, slot=1, part=part)
        c.ellipsoid((0.82, 0.78 * side, 0.42), (0.2, 0.15, 0.13), shell, segs=8, rings=6, slot=1, part=part)
        c.cone((0.95, 0.73 * side, 0.46), (1.18, 0.66 * side, 0.5), 0.07, 0.01, shell, segs=5, slot=1, part=part)
        c.cone((0.95, 0.8 * side, 0.36), (1.12, 0.78 * side, 0.32), 0.05, 0.01, shell, segs=5, slot=1, part=part)
        c.pivot(part, root)
    for part, side in ((3, -1), (4, 1)):
        for i, x in enumerate((0.15, -0.05, -0.25, -0.42)):
            knee = (x, 0.98 * side, 0.45)
            c.cone((x, 0.6 * side, 0.38), knee, 0.045, 0.04, shell, segs=4, caps=False, slot=1, part=part)
            c.cone(knee, (x - 0.08, 1.12 * side, 0.0), 0.04, 0.015, shell, segs=4, caps=False, slot=1, part=part)
        c.pivot(part, (-0.1, 0.6 * side, 0.38))


def make_turtle(c):
    # A domed green shell with a pale rim, a yellow belly plate, a head out on a short neck with eyes, big front
    # flippers (parts 1, 2) and small back ones (parts 3, 4), a stubby tail.
    shell_top, shell_low = (0.32, 0.6, 0.28), (0.16, 0.36, 0.14)
    c.ellipsoid((-0.05, 0, 0.05), (0.85, 0.72, 0.42), shaded(shell_top, shell_low), segs=14, rings=8, pole='z')
    c.ellipsoid((-0.05, 0, -0.02), (0.88, 0.75, 0.08), solid((0.85, 0.78, 0.45)), segs=14, rings=4, pole='z')
    c.ellipsoid((-0.05, 0, -0.1), (0.78, 0.64, 0.14), solid((0.95, 0.88, 0.5)), segs=12, rings=5, pole='z')
    skin = shaded((0.58, 0.72, 0.38), (0.42, 0.55, 0.28))
    c.cone((0.7, 0, 0.0), (0.92, 0, 0.04), 0.14, 0.13, skin, segs=7, caps=False)
    c.ellipsoid((1.05, 0, 0.06), (0.2, 0.17, 0.15), skin, segs=10, rings=7)
    c.ellipsoid((1.19, 0, 0.02), (0.05, 0.11, 0.03), solid((0.25, 0.3, 0.15)), segs=6, rings=3)
    for side in (1, -1):
        c.eye((1.12, 0.12 * side, 0.12), 0.06, (0.7, 1.0 * side, 0.3), pupil=0.35, segs=6, rings=5)
    c.cone((-0.85, 0, 0.0), (-1.05, 0, -0.02), 0.08, 0.0, skin, segs=5)
    flipper = [(0.15, 0.0), (0.05, -0.5), (-0.25, -1.05), (-0.42, -1.0), (-0.3, -0.45), (-0.15, 0.0)]
    small = [(0.1, 0.0), (-0.05, -0.3), (-0.3, -0.42), (-0.35, -0.2), (-0.15, 0.0)]
    for part, side in ((1, -1), (2, 1)):
        root = (0.45, 0.62 * side, -0.02)
        pts = mirror_outline(flipper, root, side)
        c.flat(pts, skin, part=part, z=root[2])
        c.flat(pts, skin, part=part, z=root[2] - 0.04)
        c.pivot(part, root)
    for part, side in ((3, -1), (4, 1)):
        root = (-0.5, 0.58 * side, -0.02)
        c.flat(mirror_outline(small, root, side), skin, part=part, z=root[2])
        c.pivot(part, root)


def make_ray(c):
    # A flat diamond: a smooth, thin body grown out into wide wings (the game waves them), a long thin tail, small eyes
    # on top. Blue-grey on top, white underneath.
    top, under = (0.36, 0.45, 0.62), (0.92, 0.94, 0.96)

    def paint(co, n, fc, fn):
        return top if n.z > 0 else under
    # A smooth lens: its outline a diamond with rounded wingtips, a ring halfway in raised a little, the middle highest
    # on top and a little lower underneath.
    tmp = bmesh.new()
    n = 24
    outline = []
    for k in range(n):
        a = 2.0 * math.pi * k / n
        # (Pointed at the nose and tail, out to round tips at the sides.)
        x = math.cos(a) * (0.8 if math.cos(a) > 0 else 0.6)
        y = math.sin(a) * 1.4 * (abs(math.sin(a)) ** 0.35)
        outline.append((x + 0.1 * (1.0 - abs(math.sin(a))), y))
    for sgn, height in ((1, 0.17), (-1, -0.09)):
        centre = tmp.verts.new((0.05, 0.0, height))
        mid = [tmp.verts.new((0.05 + (x - 0.05) * 0.5, y * 0.5, height * 0.62)) for x, y in outline]
        rim = [tmp.verts.new((x, y, 0.0)) for x, y in outline]
        for k in range(n):
            k2 = (k + 1) % n
            faces = [(centre, mid[k], mid[k2]), (mid[k], rim[k], rim[k2], mid[k2])]
            for f in faces:
                tmp.faces.new(f if sgn == 1 else tuple(reversed(f)))
    bmesh.ops.remove_doubles(tmp, verts=tmp.verts, dist=1e-5)
    c._take(tmp, Matrix.Identity(4), paint, 0, 0, 0, True)
    c.cone((-0.7, 0, 0.0), (-2.0, 0, 0.0), 0.05, 0.0, solid(top), segs=4)
    for side in (1, -1):
        c.eye((0.55, 0.14 * side, 0.12), 0.06, (0.4, 0.6 * side, 0.8), pupil=0.3, segs=6, rings=5)


def make_bubble(c):
    def paint(co, n, fc, fn):
        return WHITE if (n.z > 0.75 and n.x < 0.2) else (0.7, 0.88, 1.0)
    c.ellipsoid((0, 0, 0), (1.0, 1.0, 1.0), paint, segs=10, rings=7, pole='z')


def make_eye(c):
    c.eye((0, 0, 0), 1.0, (1, 0, 0), pupil=0.45, segs=10, rings=7)


BUILDERS = {
    "bee": make_bee, "butterfly": make_butterfly, "dragonfly": make_dragonfly, "moth": make_moth,
    "firefly": make_firefly, "beetle": make_beetle, "fly": make_fly, "fish": make_fish, "bird": make_bird,
    "frog": make_frog, "crab": make_crab, "turtle": make_turtle, "ray": make_ray, "bubble": make_bubble, "eye": make_eye,
}

def build(only=None):
    scene = bpy.data.scenes.get(SCENE) or bpy.data.scenes.new(SCENE)
    collection = bpy.data.collections.get(SCENE) or bpy.data.collections.new(SCENE)
    if collection.name not in scene.collection.children:
        scene.collection.children.link(collection)
    for obj in list(collection.objects):
        if only is None or obj.name in only:
            bpy.data.objects.remove(obj, do_unlink=True)
    made = []
    for i, name in enumerate(KINDS):
        if name not in BUILDERS or (only is not None and name not in only):
            continue
        c = Creature(name)
        BUILDERS[name](c)
        made.append(c.finish(collection, ((i % 5) * 3.5, (i // 5) * 3.5, 0)))
    return made


# --- Export to the game ------------------------------------------------------------------------------------------

REPO = r"D:\Projects\Banjo Tooie N64\tooie-grass"


def export(repo=REPO):
    """Writes the meshes into the game: rt64-ext/src/shared/rt64_critter_meshes.h (each vertex as four words, every
    kind's after the last) and rt64-ext/src/shaders/CritterMeshes.hlsli (each kind's first vertex and count, each moving
    part's pivot, and the palettes)."""
    import os
    collection = bpy.data.collections[SCENE]
    words = []
    ranges = []
    pivots = []
    most = 0

    def i16(v):
        return max(-32768, min(32767, int(round(v * 8192.0)))) & 0xFFFF

    def s8(v):
        return max(-127, min(127, int(round(v * 127.0)))) & 0xFF

    def u8(v):
        return max(0, min(255, int(round(v * 255.0))))
    for name in KINDS:
        obj = collection.objects.get(name)
        first = len(words) // 4
        kind_pivots = [(0.0, 0.0, 0.0)] * 8
        if obj is None:
            ranges.append((first, 0))
            pivots.extend(kind_pivots)
            continue
        mesh = obj.data
        mesh.calc_loop_triangles()
        col = mesh.attributes["col"].data
        slot = mesh.attributes["slot"].data
        part = mesh.attributes["part"].data
        flat = mesh.attributes["flat"].data
        normals = mesh.corner_normals
        count = 0
        for tri in mesh.loop_triangles:
            f = tri.polygon_index
            for loop in tri.loops:
                v = mesh.vertices[mesh.loops[loop].vertex_index].co
                n = normals[loop].vector
                c = col[loop].color
                sl, pa, fl = slot[f].value, part[f].value, flat[f].value
                # (The game's frame: its right is -Y here.)
                x, y, z = v.x, -v.y, v.z
                nx, ny, nz = n.x, -n.y, n.z
                if sl != 0:
                    # A multiplier on the variant's colour: a grey, halved so up to 2 fits.
                    r = g = b = c[0] * 0.5
                else:
                    r, g, b = c[0], c[1], c[2]
                words.append(i16(x) | (i16(y) << 16))
                words.append(i16(z) | ((pa & 0xF) << 16) | ((sl & 0xF) << 20) | ((fl & 1) << 24))
                words.append(s8(nx) | (s8(ny) << 8) | (s8(nz) << 16))
                words.append(u8(r) | (u8(g) << 8) | (u8(b) << 16))
                count += 1
        for key, point in obj.get("pivots", {}).items():
            kind_pivots[int(key)] = (point[0], -point[1], point[2])
        pivots.extend(kind_pivots)
        ranges.append((first, count))
        most = max(most, count)

    header = os.path.join(repo, "rt64-ext", "src", "shared", "rt64_critter_meshes.h")
    with open(header, "w", newline="\n") as out:
        out.write("//\n// RT64\n//\n\n// Made by tools/critters/critter_models.py (in Blender): the small creatures' meshes. Don't edit by hand.\n\n")
        out.write("#pragma once\n#ifndef RT64_EXT_SHARED_RT64_CRITTER_MESHES_H\n#define RT64_EXT_SHARED_RT64_CRITTER_MESHES_H\n\n")
        out.write("// The most vertices any one kind has (each creature is drawn with this many; the rest of a smaller kind's are\n// left out).\n")
        out.write("#define CRITTER_MESH_VERTICES_MOST %d\n#define CRITTER_MESH_VERTEX_COUNT %d\n\n" % (most, len(words) // 4))
        out.write("#ifdef HLSL_CPU\n#include <cstdint>\n\n")
        out.write("// Each vertex four words: x and y (16 bits each, signed, 1/8192ths); z (16 bits), its part (4 bits), paint slot\n")
        out.write("// (4 bits) and whether it is flat (1 bit); its normal (x, y, z, 8 bits each, signed); its colour (RGB, 8 bits each).\n")
        out.write("static const uint32_t CritterMeshWords[%d] = {\n" % len(words))
        for i in range(0, len(words), 8):
            out.write("    " + ", ".join("0x%08Xu" % w for w in words[i:i + 8]) + ",\n")
        out.write("};\n\n// Each kind's first vertex and how many it has (shared/rt64_critters.h's CRITTER_* order).\n")
        out.write("static const uint32_t CritterMeshRanges[%d][2] = {\n" % len(ranges))
        out.write(",\n".join("    { %du, %du }" % r for r in ranges) + "\n};\n")
        out.write("#endif\n\n#endif\n")

    hlsli = os.path.join(repo, "rt64-ext", "src", "shaders", "CritterMeshes.hlsli")
    with open(hlsli, "w", newline="\n") as out:
        out.write("//\n// RT64\n//\n\n// Made by tools/critters/critter_models.py (in Blender): where each kind's vertices are in the mesh buffer,\n")
        out.write("// each moving part's pivot, and the kinds' colour variants. Don't edit by hand.\n\n")
        out.write("static const uint2 CritterMeshRange[%d] = {\n" % len(ranges))
        out.write(",\n".join("    uint2(%du, %du)" % r for r in ranges) + "\n};\n\n")
        out.write("static const float3 CritterPivots[%d] = {\n" % len(pivots))
        out.write(",\n".join("    float3(%.4ff, %.4ff, %.4ff)" % p for p in pivots) + "\n};\n\n")
        palette = []
        for name in KINDS:
            for slot in range(SLOTS):
                colours = PALETTES.get(name, {}).get(slot, [(1.0, 1.0, 1.0)])
                for v in range(VARIANTS):
                    palette.append(colours[v % len(colours)])
        out.write("// [kind][slot][variant]\nstatic const float3 CritterPalette[%d] = {\n" % len(palette))
        out.write(",\n".join("    float3(%.3ff, %.3ff, %.3ff)" % p for p in palette) + "\n};\n")
        out.write("#define CRITTER_PALETTE_SLOTS %d\n#define CRITTER_PALETTE_VARIANTS %d\n" % (SLOTS, VARIANTS))
    return most, len(words) // 4
