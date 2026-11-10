#!/usr/bin/env python3
"""Sorts a texture dump (texture_dump/png/) into one folder per map, with an index to search.

    py tools/organize_textures.py <png folder> <out folder> [--mode hardlink|copy] [--context DIR ...]

The texture sweep (src/game/texture_sweep.cpp) saves <hash>.png, an rt64.json that lists them, and a <hash>.json
beside each PNG that says where the texture was first seen (map, entrance, frame) and what it belongs to
(src/game/texture_context.cpp: drawn in the HUD, the asset it sits in, whether that asset is a map's own model). This
reads those and builds, in <out folder>:

  Levels/<map>/                  the map's own models (its solid and see-through model)
  Characters/<name>/             models named in tools/texture_categories.csv, by the category given there
  Objects/<name>/, Pickups/<name>/, FX/<name>/, HUD/Menus/<name>/, ... (any category the csv uses)
  HUD/<name or asset id>/        textures drawn in the HUD, menus and text (the frame's 2D part)
  Unsorted/Models/<id> (<map>)/  models with no name in the csv
  Unsorted/Assets/<kind> <id> (<map>)/  textures of other assets (sprites, effects) not yet named
  Unsorted/Not in an asset/<map>/       textures loaded from outside the game's loaded assets
  Unsorted/By map/<map>/         textures from dumps made before the "what it belongs to" fields existed
  Shared/                        textures that more than one --context dump saw in different maps (old dumps only)
  Unknown/                       textures with no context json
  index.html                     every texture with a thumbnail, a folder tree with counts, category buttons and a
                                 search over category, name, asset id, map, size and format (no outside files)
  manifest.csv                   the same rows

A file is named "<hash8> <asset id> <width>x<height> <format>.png". Model names and categories come from
tools/texture_categories.csv (edit it and run this again; nothing needs dumping again).

Files are hard-linked (NTFS; no extra disk space) or copied with --mode copy, and copied if linking fails (another
drive). The source folder is never changed. Python 3, standard library only.

rt64.json is only written when a dump stops, so after a crash it can miss newer PNGs. Any PNG in the folder that
rt64.json does not list is still sorted (into Unknown, marked "not in rt64.json" in the index), named in a WARNING
line, and counted as a failed check unless --allow-unlisted is given.

Exit code 0 if every PNG (listed in rt64.json or not) is in the output exactly once, the number of files matches, and
no PNG is unlisted (or --allow-unlisted was given); 1 if not.
"""

import argparse
import csv
import html
import json
import os
import re
import shutil
import struct
import sys
import urllib.parse
from collections import Counter, OrderedDict

UNKNOWN = "Unknown"
SHARED = "Shared"
BAD_NAME_CHARS = re.compile(r'[<>:"/\\|?*\x00-\x1f]')


def read_json(path):
    try:
        with open(path, "r", encoding="utf-8") as f:
            return json.load(f)
    except (OSError, ValueError):
        return None


def rt64_hashes(folder):
    """The hashes rt64.json lists, in order, each once."""
    data = read_json(os.path.join(folder, "rt64.json"))
    if data is None:
        sys.exit("error: %s has no readable rt64.json" % folder)
    hashes = OrderedDict()
    for entry in data.get("textures", []):
        h = entry.get("hashes", {}).get("rt64") or entry.get("path")
        if h:
            hashes[h] = True
    return list(hashes)


def unlisted_pngs(folder, listed):
    """Hashes of the *.png files in the folder that rt64.json does not list, sorted."""
    known = set(listed)
    found = []
    for name in os.listdir(folder):
        stem, ext = os.path.splitext(name)
        if ext.lower() == ".png" and stem not in known:
            found.append(stem)
    return sorted(found)


def png_size(path):
    """Width and height from the PNG header, for textures with no context json."""
    try:
        with open(path, "rb") as f:
            head = f.read(24)
        if head[:8] == b"\x89PNG\r\n\x1a\n":
            return struct.unpack(">II", head[16:24])
    except OSError:
        pass
    return None


def map_key(text):
    """'0x0AF' -> 175, so maps from different dumps compare equal."""
    try:
        return int(str(text), 16)
    except ValueError:
        return None


def map_folder(map_id, map_name):
    """'0AF Spiral Mountain' from 0x0AF and 'SM - Spiral Mountain'. A short capital prefix before ' - ' is dropped."""
    name = re.sub(r"^[A-Z0-9]{1,5} - ", "", map_name or "")
    name = BAD_NAME_CHARS.sub("_", name).strip(" .")
    digits = "%03X" % map_id
    return (digits + " " + name) if name else digits


TOOLS_DIR = os.path.dirname(os.path.abspath(__file__))


def load_map_names():
    """Map id -> name from src/game/map_names.inc (the port's own list)."""
    names = {}
    path = os.path.join(TOOLS_DIR, "..", "src", "game", "map_names.inc")
    try:
        with open(path, "r", encoding="utf-8") as f:
            for line in f:
                m = re.match(r'\s*\{\s*0x([0-9A-Fa-f]+)\s*,\s*"([^"]*)"', line)
                if m:
                    names[int(m.group(1), 16)] = m.group(2)
    except OSError:
        pass
    return names


def load_categories(path):
    """Model asset id -> (name, category path) from texture_categories.csv; '#' lines are comments."""
    table = {}
    try:
        with open(path, "r", encoding="utf-8") as f:
            lines = [l for l in f if not l.lstrip().startswith("#")]
    except OSError:
        return table
    for row in csv.DictReader(lines):
        try:
            mid = int(row["id"], 16)
        except (KeyError, ValueError, TypeError):
            continue
        name = (row.get("name") or "").strip()
        cat = (row.get("category") or "").strip().strip("/")
        if name and cat:
            table[mid] = (name, cat)
    return table


def clean(text):
    return BAD_NAME_CHARS.sub("_", str(text)).strip(" .") or "_"


KIND_NAMES = {0: "Model", 7: "Sprite", 8: "Sprite", 10: "Gldb"}


def owner_folder(first, map_names, categories):
    """The folder for a texture from its first context's owner fields, and a label for the index; None when the
    context has no owner fields (a dump made before they existed)."""
    if "asset" not in first and "drawn_2d" not in first:
        return None
    seen_map = map_key(first.get("map"))
    seen = map_folder(seen_map, first.get("map_name", "")) if seen_map is not None else "unknown map"
    asset = first.get("asset", -1)
    kind = first.get("asset_kind", -1)
    level_of = first.get("level_of", -1)
    has_asset = isinstance(asset, int) and asset >= 0
    asset_text = ("0x%03X" % asset) if has_asset else ""
    kind_name = KIND_NAMES.get(kind, "Kind %s" % kind)
    if first.get("drawn_2d"):
        if has_asset and asset in categories:
            name, cat = categories[asset]
            if cat.split("/")[0] == "HUD":
                return "/".join(clean(p) for p in cat.split("/")) + "/" + clean(name), cat + ": " + name
        elif has_asset:
            name = "%s %s" % (kind_name, asset_text)
        else:
            name = "Not in an asset"
        return "HUD/" + clean(name), "HUD: " + name
    if isinstance(level_of, int) and level_of >= 0:
        level = map_folder(level_of, map_names.get(level_of, ""))
        return "Levels/" + clean(level), "level " + level
    if has_asset:
        if asset in categories:
            name, cat = categories[asset]
            return "/".join(clean(p) for p in cat.split("/")) + "/" + clean(name), cat + ": " + name
        if kind == 0:
            return "Unsorted/Models/%s (%s)" % (asset_text, clean(seen)), "unnamed model " + asset_text
        return ("Unsorted/Assets/%s %s (%s)" % (clean(kind_name), asset_text, clean(seen)),
                "asset %s (%s)" % (asset_text, kind_name))
    return "Unsorted/Not in an asset/" + clean(seen), "not in an asset"


def read_context(folder, hash_, sources):
    """Every (map id, map name, exit, frame, width, height, format) any context folder has for this hash."""
    found = []
    for src in sources:
        data = read_json(os.path.join(src, hash_ + ".json"))
        if not isinstance(data, dict):
            continue
        found.append(data)
    return found


def link_or_copy(src, dst, mode):
    if os.path.lexists(dst):
        os.remove(dst)
    if mode == "hardlink":
        try:
            os.link(src, dst)
            return "link"
        except OSError:
            pass
    shutil.copy2(src, dst)
    return "copy"


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("png_folder")
    ap.add_argument("out_folder")
    ap.add_argument("--mode", choices=["hardlink", "copy"], default="hardlink")
    ap.add_argument("--context", action="append", default=[], metavar="DIR",
                    help="another dump's png folder, read for context json only (a texture seen in more than one "
                         "map across dumps goes to Shared); may be repeated")
    ap.add_argument("--categories", default=os.path.join(TOOLS_DIR, "texture_categories.csv"),
                    help="model id -> name and category table (default: texture_categories.csv beside this script)")
    ap.add_argument("--allow-unlisted", action="store_true",
                    help="do not fail the checks for PNGs that rt64.json does not list (they are still sorted and reported)")
    args = ap.parse_args()

    src_dir = os.path.abspath(args.png_folder)
    out_dir = os.path.abspath(args.out_folder)
    if not os.path.isdir(src_dir):
        sys.exit("error: %s is not a folder" % src_dir)
    # normcase: Windows paths differ only in case, and C:\A and c:\a are the same folder.
    norm_out = os.path.normcase(out_dir)
    norm_src = os.path.normcase(src_dir)
    if norm_out == norm_src or norm_out.startswith(norm_src + os.sep):
        sys.exit("error: the output folder must not be inside the source folder")
    sources = [src_dir] + [os.path.abspath(d) for d in args.context]

    map_names = load_map_names()
    categories = load_categories(args.categories)
    hashes = rt64_hashes(src_dir)
    unlisted = unlisted_pngs(src_dir, hashes)
    unlisted_set = set(unlisted)
    problems = []
    rows = []
    for h in hashes + unlisted:
        png = os.path.join(src_dir, h + ".png")
        if not os.path.isfile(png):
            problems.append("rt64.json lists %s but %s.png is missing" % (h, h))
            continue
        contexts = read_context(src_dir, h, sources)
        maps = OrderedDict()  # map id -> name, in the order found
        first = None
        for c in contexts:
            mid = map_key(c.get("map"))
            if mid is None:
                continue
            maps.setdefault(mid, c.get("map_name", ""))
            if first is None:
                first = c
        size = png_size(png)
        if first is not None:
            width = first.get("width", size[0] if size else 0)
            height = first.get("height", size[1] if size else 0)
            fmt = first.get("format", "unknown")
            exit_ = first.get("exit", -1)
            frame = first.get("frame", 0)
        else:
            width, height = size if size else (0, 0)
            fmt, exit_, frame = "unknown", -1, 0
        owner = owner_folder(first, map_names, categories) if first is not None else None
        label = ""
        if h in unlisted_set:
            folder = UNKNOWN
        elif not maps:
            folder = UNKNOWN
        elif owner is not None:
            folder, label = owner
        elif len(maps) > 1:
            folder = SHARED
        else:
            mid = next(iter(maps))
            folder = "Unsorted/By map/" + map_folder(mid, maps[mid])
        asset = first.get("asset", -1) if first is not None else -1
        asset_text = ("0x%03X" % asset) if isinstance(asset, int) and asset >= 0 else ""
        rows.append({
            "hash": h, "folder": folder, "width": width, "height": height, "format": fmt,
            "maps": ("not in rt64.json" if h in unlisted_set else
                     ", ".join(map_folder(m, n) for m, n in maps.items()) if maps else ""),
            "exit": exit_, "frame": frame, "src": png, "label": label, "asset": asset_text,
        })

    os.makedirs(out_dir, exist_ok=True)
    used = set()
    modes = Counter()
    for r in rows:
        os.makedirs(os.path.join(out_dir, *r["folder"].split("/")), exist_ok=True)
        name = "%s%s %dx%d %s" % (r["hash"][:8], (" " + r["asset"]) if r["asset"] else "", r["width"], r["height"],
                                  BAD_NAME_CHARS.sub("_", str(r["format"])))
        rel = "%s/%s.png" % (r["folder"], name)
        if rel.lower() in used:
            # Two hashes sharing their first 8 digits: keep the whole hash in the name.
            rel = "%s/%s %s.png" % (r["folder"], r["hash"], name[9:])
        used.add(rel.lower())
        r["path"] = rel
        modes[link_or_copy(r["src"], os.path.join(out_dir, *rel.split("/")), args.mode)] += 1

    with open(os.path.join(out_dir, "manifest.csv"), "w", newline="", encoding="utf-8") as f:
        w = csv.writer(f)
        w.writerow(["hash", "folder", "what", "asset", "maps", "width", "height", "format", "exit", "frame", "path"])
        for r in rows:
            w.writerow([r["hash"], r["folder"], r["label"], r["asset"], r["maps"], r["width"], r["height"], r["format"],
                        r["exit"], r["frame"], r["path"]])

    write_index(out_dir, rows)

    # Checks: each hash in rt64.json once in the output, and as many files as unique hashes.
    in_output = Counter(r["hash"] for r in rows)
    for h in hashes + unlisted:
        if in_output.get(h, 0) != 1:
            problems.append("hash %s appears %d times in the output" % (h, in_output.get(h, 0)))
    files = 0
    for folder in {r["folder"] for r in rows}:
        files += sum(1 for n in os.listdir(os.path.join(out_dir, *folder.split("/"))) if n.lower().endswith(".png"))
    unique = len(set(hashes)) + len(unlisted)
    if unlisted and not args.allow_unlisted:
        problems.append("%d png files are not in rt64.json (it is written when a dump stops; a crashed sweep leaves it "
                        "behind); first: %s. Use --allow-unlisted to accept them" % (len(unlisted), ", ".join(unlisted[:5])))
    if files != unique:
        problems.append("%d png files in the output for %d unique hashes (is the output folder reused from an older run? use an empty one)" % (files, unique))

    per_folder = Counter(r["folder"] for r in rows)
    for name in sorted(per_folder):
        print("%6d  %s" % (per_folder[name], name))
    print("%6d  total in %d folders (%d linked, %d copied)" % (len(rows), len(per_folder), modes["link"], modes["copy"]))
    if unlisted:
        print("WARNING: %d png files are not listed in rt64.json; they are in %s" % (len(unlisted), UNKNOWN))
    print("rt64.json hashes: %d, not listed: %d, files in output: %d" % (len(set(hashes)), len(unlisted), files))
    if problems:
        for p in problems[:50]:
            print("CHECK FAILED: " + p)
        return 1
    print("checks passed: every png exactly once, file count matches" + (", none unlisted" if not unlisted else ""))
    return 0


INDEX_HEAD = """<!doctype html>
<html lang="en"><head><meta charset="utf-8"><title>Texture index</title>
<style>
body{font-family:sans-serif;margin:0;display:flex;height:100vh;color:#222}
#side{width:300px;overflow:auto;border-right:1px solid #aaa;padding:8px;font-size:13px;background:#f4f4f4;flex:none}
#side a{display:block;color:#124;text-decoration:none;padding:1px 0;white-space:nowrap;overflow:hidden;text-overflow:ellipsis}
#side a:hover{text-decoration:underline}
#side a.on{font-weight:bold;color:#a20}
#main{flex:1;overflow:auto;padding:8px 12px}
#bar{position:sticky;top:0;background:#fff;padding:6px 0;border-bottom:1px solid #ccc;z-index:1}
#q{width:28em;padding:4px;font-size:14px}
.cat{margin:2px;padding:3px 8px;border:1px solid #888;border-radius:10px;background:#eee;cursor:pointer;font-size:12px}
.cat.on{background:#a20;color:#fff;border-color:#a20}
#grid{display:flex;flex-wrap:wrap;gap:6px;margin-top:8px}
.t{width:150px;border:1px solid #ccc;border-radius:4px;padding:4px;font-size:11px;word-wrap:break-word}
.t img{display:block;width:142px;height:110px;object-fit:contain;image-rendering:pixelated;background:repeating-conic-gradient(#ccc 0 25%,#fff 0 50%) 0 0/16px 16px}
.t b{display:block;font-size:12px;margin-top:3px}
.t span{color:#666}
</style></head><body>
<div id="side"><b>Folders</b><div id="tree"></div></div>
<div id="main"><div id="bar">
<input id="q" type="search" placeholder="search: banjo, characters, hud, jiggy, 0x62A, spiral, 32x32, rgba16" autofocus>
<span id="count"></span><div id="cats"></div></div>
<div id="grid">
"""

INDEX_TAIL = """</div></div>
<script>
var q=document.getElementById('q'),items=Array.prototype.slice.call(document.querySelectorAll('.t')),
count=document.getElementById('count'),tree=document.getElementById('tree'),cats=document.getElementById('cats'),
folder='',cat='';
function f(){var w=q.value.toLowerCase().split(/\\s+/).filter(Boolean),n=0;
items.forEach(function(e){var s=e.getAttribute('data-s'),p=e.getAttribute('data-f'),ok=true;
if(folder&&p!==folder&&p.indexOf(folder+'/')!==0)ok=false;
if(ok&&cat&&p.split('/')[0]!==cat)ok=false;
for(var j=0;ok&&j<w.length;j++){if(s.indexOf(w[j])<0)ok=false;}
e.style.display=ok?'':'none';if(ok)n++;});
count.textContent=n+' of '+items.length+' textures'+(folder?' in '+folder:'');
Array.prototype.forEach.call(tree.querySelectorAll('a'),function(a){a.className=a.getAttribute('data-f')===folder?'on':'';});
Array.prototype.forEach.call(cats.querySelectorAll('.cat'),function(b){b.className='cat'+(b.getAttribute('data-c')===cat?' on':'');});}
var counts={};items.forEach(function(e){var parts=e.getAttribute('data-f').split('/');
for(var i=1;i<=parts.length;i++){var k=parts.slice(0,i).join('/');counts[k]=(counts[k]||0)+1;}});
var keys=Object.keys(counts).sort(function(a,b){return a.toLowerCase()<b.toLowerCase()?-1:1;});
var all=document.createElement('a');all.href='#';all.textContent='Everything ('+items.length+')';all.setAttribute('data-f','');
all.onclick=function(){folder='';f();return false;};tree.appendChild(all);
keys.forEach(function(k){var d=k.split('/').length-1,a=document.createElement('a');a.href='#';
a.style.paddingLeft=(d*14)+'px';a.textContent=k.split('/').pop()+' ('+counts[k]+')';a.setAttribute('data-f',k);
a.onclick=function(){folder=k;f();return false;};tree.appendChild(a);});
var tops=keys.filter(function(k){return k.indexOf('/')<0;});
[''].concat(tops).forEach(function(c){var b=document.createElement('button');b.className='cat';b.setAttribute('data-c',c);
b.textContent=c?c+' ('+counts[c]+')':'All';b.onclick=function(){cat=c;folder='';f();};cats.appendChild(b);});
q.addEventListener('input',f);f();
</script></body></html>
"""


def write_index(out_dir, rows):
    parts = [INDEX_HEAD]
    for r in sorted(rows, key=lambda r: r["path"].lower()):
        href = urllib.parse.quote(r["path"])
        size = "%dx%d" % (r["width"], r["height"])
        maps = r["maps"] or ""
        title = r["folder"].split("/")[-1]
        search = " ".join([r["folder"].replace("/", " "), r["label"], r["asset"], r["hash"], maps, size,
                           str(r["format"])]).lower()
        parts.append(
            '<div class="t" data-f="%s" data-s="%s"><a href="%s" target="_blank"><img loading="lazy" src="%s" alt=""></a>'
            "<b>%s</b><span>%s</span><br><span>%s %s %s</span><br><span>%s</span></div>\n" % (
                html.escape(r["folder"], quote=True), html.escape(search, quote=True), href, href,
                html.escape(title), html.escape(r["folder"]), html.escape(r["asset"]), size,
                html.escape(str(r["format"])), html.escape(maps)))
    parts.append(INDEX_TAIL)
    with open(os.path.join(out_dir, "index.html"), "w", encoding="utf-8") as f:
        f.write("".join(parts))


if __name__ == "__main__":
    sys.exit(main())
