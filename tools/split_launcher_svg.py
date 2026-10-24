# Splits L's BANJO.svg into the start menu's three background layers (src/ui/launcher_background.cpp),
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
def element(id_):
    m = re.search(r'<(rect|path) id="%s"[^>]*/>' % id_, src) or re.search(r'<g id="%s">.*?</g>' % id_, src, re.S)
    # Drop the stray dot far left of the artboard (M-2279.98,21.39), so it doesn't stretch a layer's box.
    return inline(re.sub(r'\s*<path [^>]*d="M-2279[^>]*/>', '', m.group(0)))
layers = {  # bounding boxes measured in Chromium
    'background': (['Background_color', 'Background_2'], (-826.98, -914.44, 3213.02, 2220.67)),
    'slide_right': (['Slide_from_the_right'], (518.24, 349.38, 3208.35, 1296.61)),
    # Group "1": the path and dirt patches in front.
    'path': (['_x31_'], (0.92, 1033.06, 1940.68, 1959.98)),
    # Group "2", the head (1267.77, -272.75, 1969.25, 1043.21), turns about the foot of its ladder,
    # (1550, 1040): its box is centred there, as the menu turns and squashes a layer about its middle.
    'head': (['_x32_'], (1130, -274, 1970, 2354)),
    'slide_left': (['Slide_from_the_left'], (-839.99, 586.32, 1817.86, 1552.71)),
}
for name, (ids, (x0, y0, x1, y1)) in layers.items():
    x0, y0, x1, y1 = math.floor(x0) - 2, math.floor(y0) - 2, math.ceil(x1) + 2, math.ceil(y1) + 2
    body = '\n'.join(element(i) for i in ids)
    open(f'{out}/{name}.svg', 'w').write(
        f'<svg xmlns="http://www.w3.org/2000/svg" viewBox="{x0} {y0} {x1 - x0} {y1 - y0}">\n{body}\n</svg>\n')
    print(name, x0, y0, x1, y1)
