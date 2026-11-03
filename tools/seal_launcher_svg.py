import glob, os, re, sys
# Closes the hairline seams inside the start menu's art (L, 2026-11-03). The art is traced, so shapes meet edge to edge
# instead of overlapping; on the pixels along a meeting edge each shape covers only part of the pixel, so what lies
# behind shows through as a thin line (the sky's blue through the title's yellow outlines read as green specks). A
# stroke in each shape's own colour makes neighbours overlap by a fraction of a pixel; the art's outer edges stay
# antialiased. Shapes that already have a stroke, or are see-through (opacity), are left as they are.
# Run again after tools/split_launcher_svg.py or tools/split_title_letters.py; running it twice changes nothing.
# Usage: python3 tools/seal_launcher_svg.py [assets/launcher]
folder = sys.argv[1] if len(sys.argv) > 1 else 'assets/launcher'
# Stroke widths in each file's own units, about a pixel at a 1440-high window: the letters' units are about two pixels,
# the background layers' (L's artboard) under one.
TITLE_WIDTH = 0.6
LAYER_WIDTH = 1.5
shape = re.compile(r'<(path|polygon|rect|circle|ellipse)\b[^>]*>')
for path in sorted(glob.glob(os.path.join(folder, '*.svg'))):
    name = os.path.basename(path)
    if name.endswith('-source.svg'):
        continue
    width = TITLE_WIDTH if name.startswith('title_') else LAYER_WIDTH
    text = open(path, encoding='utf-8').read()
    def seal(m):
        el = m.group(0)
        fill = re.search(r'fill="(#[0-9a-fA-F]+)"', el)
        if fill is None or 'stroke=' in el or 'opacity' in el:
            return el
        return el.replace(fill.group(0), f'{fill.group(0)} stroke="{fill.group(1)}" stroke-width="{width}" stroke-linejoin="round"', 1)
    sealed = shape.sub(seal, text)
    if sealed != text:
        open(path, 'w', encoding='utf-8', newline='').write(sealed)
        print(name, 'sealed')
