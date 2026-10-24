# Splits L's BANJO.svg into the start menu's background layers (src/ui/launcher_background.cpp),
# with each class turned into fill/opacity attributes.
# Usage: python3 tools/split_launcher_svg.py assets/launcher/BANJO-source.svg assets/launcher
# If the art changes, measure the groups' bounding boxes again (getBBox in a browser) and update
# them here and in launcher_background.cpp.
import math, re, sys
src = open(sys.argv[1]).read()
out = sys.argv[2]
styles = {}
for sel, body in re.findall(r'([^{}]+)\{([^}]*)\}', src.split('<style>')[1].split('</style>')[0]):
    props = dict(p.split(':') for p in [x.strip() for x in body.split(';')] if p)
    for c in sel.split(','):
        styles.setdefault(c.strip().lstrip('.'), {}).update({k.strip(): v.strip() for k, v in props.items()})
# Fills whose shapes meet edge to edge on the island block: a thin stroke of the same colour hides the
# hairline seam where the grass behind showed through between them (L, 2026-10-24).
seam_fills = {'#63522b'}
def inline(s):
    def rep(m):
        p = styles[m.group(1)]
        a = f'fill="{p["fill"]}"'
        if 'opacity' in p:
            a += f' opacity="{p["opacity"]}"'
        elif p['fill'] in seam_fills:
            a += f' stroke="{p["fill"]}" stroke-width="2" stroke-linejoin="round"'
        return a
    return re.sub(r'class="(st\d+)"', rep, s)
def element(id_, keep=None):
    m = re.search(r'<(rect|path) id="%s"[^>]*/>' % id_, src) or re.search(r'<g id="%s">.*?</g>' % id_, src, re.S)
    # Drop the stray dot far left of the artboard (M-2279.98,21.39), so it doesn't stretch a layer's box.
    s = re.sub(r'\s*<path [^>]*d="M-2279[^>]*/>', '', m.group(0))
    if keep is not None:
        # Only the group's paths at these indices (to split one of L's groups into parts).
        paths = re.findall(r'<path [^>]*/>', s)
        s = '<g id="%s">\n%s\n</g>' % (id_, '\n'.join('    ' + paths[i] for i in keep))
    return inline(s)
# Group "5": the grass ledge (paths 0-1), the bird on it (2-9 and 30) and the fence (10-29).
bird = list(range(2, 10)) + [30]
ledge = [0, 1] + list(range(10, 30))
ledge_floor = '<polygon fill="#63522b" points="1723.72,1690 2777.72,1700 2777.72,3000 1723.72,3000"/>'
layers = {  # bounding boxes measured in Chromium (getBBox)
    'background': (['Background_color', 'Background_2'], (-826.98, -914.44, 3213.02, 2220.67)),
    'slide_right': (['Slide_from_the_right'], (518.24, 349.38, 3208.35, 1296.61)),
    # Group "1": the path and dirt patches in front.
    'path': (['_x31_'], (0.92, 1033.06, 1940.68, 1959.98)),
    # Group "2", the head (1267.77, -272.75, 1969.25, 818.31), turns about the foot of its ladder,
    # (1550, 1040): its box is centred there, as the menu turns and squashes a layer about its middle.
    'head': (['_x32_'], (1130, -274, 1970, 2354)),
    # Group "3", the ladder (1509.41, 664.85, 1586.21, 1043.21), unrolls from its top, (1547, 664).
    'ladder': (['_x33_'], (1500, 282, 1594, 1046)),
    # Group "4": the rock arch and waterfall at the back left.
    'back_left': (['_x34_'], (-839.99, 586.32, 666.73, 1186.89)),
    'slide_left': (['Slide_from_the_left'], (265.39, 592.48, 1817.86, 1552.71)),
    # The ledge's brown side carries on far below its art (to y 3000), so its bottom edge never shows
    # while it rises or drifts (L, 2026-10-24).
    'ledge': ([ledge_floor, ('_x35_', ledge)], (1723.72, 1196.88, 2852.73, 3000.0)),
    # The bird (about 2116-2250 by 1336-1450) hops from its feet, (2183, 1450).
    'bird': ([('_x35_', bird)], (2093, 1318, 2273, 1582)),
}
for name, (ids, (x0, y0, x1, y1)) in layers.items():
    x0, y0, x1, y1 = math.floor(x0) - 2, math.floor(y0) - 2, math.ceil(x1) + 2, math.ceil(y1) + 2
    # An entry is an element id, (group id, path indices), or literal markup.
    body = '\n'.join(element(*i) if isinstance(i, tuple) else i if i.startswith('<') else element(i) for i in ids)
    open(f'{out}/{name}.svg', 'w').write(
        f'<svg xmlns="http://www.w3.org/2000/svg" viewBox="{x0} {y0} {x1 - x0} {y1 - y0}">\n{body}\n</svg>\n')
    print(name, x0, y0, x1, y1)
