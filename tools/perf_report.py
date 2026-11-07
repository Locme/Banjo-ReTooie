#!/usr/bin/env python3
"""Turns a perf_sweep.py output folder into maps.csv, report.txt and (with Pillow) report.png.

Usage: py tools/perf_report.py <out dir>
"""
import csv
import glob
import os
import re
import statistics
import sys
from collections import defaultdict


def num(s):
    try:
        return float(s)
    except (TypeError, ValueError):
        return None


def med(v):
    v = [x for x in v if x is not None]
    return statistics.median(v) if v else 0.0


def load_map_names():
    """Map id -> name from map_names.inc, for readable tables."""
    path = os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), "src", "game", "map_names.inc")
    names = {}
    try:
        for line in open(path, encoding="utf-8", errors="replace"):
            m = re.match(r'\s*\{\s*0x([0-9A-Fa-f]+)\s*,\s*"(.*)"\s*\}', line)
            if m:
                names[int(m.group(1), 16)] = m.group(2)
    except OSError:
        pass
    return names


def parse_map(s):
    """The csv's map column is hex, with or without a 0x prefix."""
    try:
        return int(str(s).strip(), 16)
    except ValueError:
        return None


# ---------------------------------------------------------------- benchmarks

def read_benchmarks(out):
    """Returns {map id: [row dicts]} with the first second in each map stay dropped."""
    per_map = defaultdict(list)
    for f in sorted(glob.glob(os.path.join(out, "bench_run*.csv"))):
        with open(f, newline="", encoding="utf-8", errors="replace") as fh:
            rows = list(csv.DictReader(fh))
        entered = {}
        for r in rows:
            mid = parse_map(r.get("map"))
            t = num(r.get("seconds"))
            if mid is None or t is None:
                continue
            # A map's clock starts at its first row; rows in the first second are the load.
            if mid not in entered or (entered.get("last") != mid):
                entered[mid] = t
            entered["last"] = mid
            if t - entered[mid] < 1.0:
                continue
            r["_t"] = t
            per_map[mid].append(r)
    return per_map


def summarize_maps(per_map, names):
    result = []
    for mid, rows in per_map.items():
        gpu_cols = sorted({k for r in rows for k in r if k and k.startswith("gpu_") and k.endswith("_ms")
                           and k != "gpu_ms_per_game_frame"})
        compiles = [num(r.get("shader_compiles")) for r in rows]
        compiles = [c for c in compiles if c is not None]
        if compiles:
            mono = all(b >= a for a, b in zip(compiles, compiles[1:]))
            shader = max(compiles) - min(compiles) if mono else sum(compiles)
        else:
            shader = 0
        d = {
            "map": f"{mid:X}",
            "name": names.get(mid, "?"),
            "rows": len(rows),
            "frame_ms": med(num(r.get("frame_ms")) for r in rows),
            "worst_frame_ms": max([num(r.get("worst_frame_ms")) or 0 for r in rows]),
            "gpu_ms_per_game_frame": med(num(r.get("gpu_ms_per_game_frame")) for r in rows),
            "game_cpu_ms": med(num(r.get("game_cpu_ms")) for r in rows),
            "game_fps": med(num(r.get("game_fps")) for r in rows),
            "shader_compiles": shader,
        }
        for c in gpu_cols:
            d[c] = med(num(r.get(c)) for r in rows)
        # The renderer thread's time per game frame, in its five parts (newer benchmark files only).
        for c in ("renderer_draws_ms", "renderer_effects_setup_ms", "renderer_record_ms", "renderer_gpu_wait_ms", "renderer_after_ms"):
            if any(c in r for r in rows):
                d[c] = med(num(r.get(c)) for r in rows)
        if "renderer_draws_ms" in d:
            d["renderer_ms"] = sum(d[c] or 0 for c in ("renderer_draws_ms", "renderer_effects_setup_ms", "renderer_record_ms", "renderer_gpu_wait_ms", "renderer_after_ms"))
        result.append(d)
    return result


def write_maps_csv(out, maps):
    cols = []
    for d in maps:
        for k in d:
            if k not in cols:
                cols.append(k)
    with open(os.path.join(out, "maps.csv"), "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=cols, restval="")
        w.writeheader()
        for d in sorted(maps, key=lambda d: -d["frame_ms"]):
            w.writerow({k: (round(v, 3) if isinstance(v, float) else v) for k, v in d.items()})


def table(rows, cols, heads):
    """Plain text table; rows are lists of already formatted strings."""
    widths = [max(len(h), *(len(r[i]) for r in rows)) if rows else len(h) for i, h in enumerate(heads)]
    lines = ["  ".join(h.ljust(w) if i < 2 else h.rjust(w) for i, (h, w) in enumerate(zip(heads, widths)))]
    for r in rows:
        lines.append("  ".join(c.ljust(w) if i < 2 else c.rjust(w) for i, (c, w) in enumerate(zip(r, widths))))
    return "\n".join(lines)


def maps_section(maps):
    out = ["== Maps, heaviest first by median frame_ms ==", ""]
    heads = ["map", "name", "rows", "frame", "worst", "gpu/gf", "cpu", "rend", "gfps", "shdr"]
    def row(d):
        return [d["map"], d["name"][:38], str(d["rows"]), f"{d['frame_ms']:.2f}", f"{d['worst_frame_ms']:.1f}",
                f"{d['gpu_ms_per_game_frame']:.2f}", f"{d['game_cpu_ms']:.2f}",
                f"{d['renderer_ms']:.2f}" if "renderer_ms" in d else "-", f"{d['game_fps']:.1f}",
                f"{d['shader_compiles']:.0f}"]
    out.append(table([row(d) for d in sorted(maps, key=lambda d: -d["frame_ms"])], None, heads))
    for title, key in (("gpu_ms_per_game_frame", "gpu_ms_per_game_frame"), ("game_cpu_ms", "game_cpu_ms"),
                       ("worst_frame_ms", "worst_frame_ms")):
        out += ["", f"== Top 15 by {title} =="]
        out.append(table([row(d) for d in sorted(maps, key=lambda d: -d[key])[:15]], None, heads))
    gpu_cols = sorted({k for d in maps for k in d if k.startswith("gpu_") and k.endswith("_ms")
                       and k != "gpu_ms_per_game_frame"})
    if gpu_cols:
        out += ["", "== Median per GPU pass (ms), heaviest total first =="]
        h = ["map", "name"] + [c[4:-3] for c in gpu_cols]
        rows = [[d["map"], d["name"][:30]] + [f"{d.get(c, 0):.2f}" for c in gpu_cols]
                for d in sorted(maps, key=lambda d: -sum(d.get(c, 0) for c in gpu_cols))[:30]]
        out.append(table(rows, None, h))
    return "\n".join(out)


# ------------------------------------------------------------------ profiles

def classify(module, func):
    f = func or ""
    m = (module or "").lower()
    if f.startswith("aspMain") or "aspMain" in f:
        return "RSP audio"
    if re.match(r"^(func_[0-9A-Fa-f]{8}|D_[0-9A-Fa-f]{8})", f) or f.endswith("_recomp") \
            or re.search(r"_[0-9A-F]{8}(_[a-z0-9]+)?$", f) or re.search(r"Dll_entrypoint_\d+", f) \
            or "_entrypoint_" in f:
        return "game code"
    lf = f.lower()
    if "rt64" in lf or "plume" in lf or "rt64" in m:
        return "RT64"
    if re.search(r"nvoglv|nvwgf2umx|nvgpucomp|nvd3dum|amd|atid|igd|intel|vulkan-1|d3d12|d3d11|dxgi", m):
        return "driver"
    if "librecomp" in lf or "ultramodern" in lf or "recomp" in lf or "librecomp" in m or "ultramodern" in m:
        return "runtime"
    if "tooie" in lf or "tooie" in m:
        return "our glue"
    if re.search(r"ntdll|kernel32|kernelbase|ucrtbase|msvcp|vcruntime|msvcrt|user32|win32u|gdi32", m):
        return "OS"
    if "banjoretooie" in m:
        # Our own exe with no better clue: runtime support or game glue linked in.
        return "runtime"
    return "other"


def read_profiles(out):
    """Returns list of (samples, label, thread, module, function, group)."""
    rows = []
    for f in sorted(glob.glob(os.path.join(out, "profile_run*.tsv"))):
        for line in open(f, encoding="utf-8", errors="replace"):
            if line.startswith("#") or not line.strip():
                continue
            p = line.rstrip("\r\n").split("\t")
            if len(p) < 5:
                continue
            try:
                n = int(p[0])
            except ValueError:
                continue
            rows.append((n, p[1], p[2], p[3], p[4], classify(p[3], p[4])))
    return rows


def pct(n, total):
    return f"{100.0 * n / total:5.1f}%" if total else "  0.0%"


def profile_section(rows, names):
    out = []
    if not rows:
        return "== Profiles ==\n(no profile_run*.tsv found)"
    total = sum(r[0] for r in rows)
    out += ["== Profile: overall share by group ==", ""]
    g = defaultdict(int)
    for r in rows:
        g[r[5]] += r[0]
    for k, v in sorted(g.items(), key=lambda kv: -kv[1]):
        out.append(f"{k:<12}{v:>10}  {pct(v, total)}")
    out += ["", "== Profile: share by thread (with group split) =="]
    th = defaultdict(lambda: defaultdict(int))
    for r in rows:
        th[r[2]][r[5]] += r[0]
    for t, gg in sorted(th.items(), key=lambda kv: -sum(kv[1].values())):
        s = sum(gg.values())
        split = ", ".join(f"{k} {pct(v, s).strip()}" for k, v in sorted(gg.items(), key=lambda kv: -kv[1])[:4])
        out.append(f"{t:<28}{s:>10}  {pct(s, total)}   {split}")

    game_thread = max(th, key=lambda t: th[t].get("game code", 0))
    gfx_thread = None
    for t in th:
        if re.search(r"gfx|graphics|rt64|render", t, re.I):
            if gfx_thread is None or sum(th[t].values()) > sum(th[gfx_thread].values()):
                gfx_thread = t
    out += ["", f"(game thread taken as '{game_thread}'; gfx thread as '{gfx_thread}')"]

    loading = defaultdict(list)
    per_label = defaultdict(list)
    for r in rows:
        if r[1].endswith(" load"):
            loading[r[1][:-5].strip()].append(r)
        else:
            per_label[r[1]].append(r)

    def top(rs, thread, n):
        agg = defaultdict(int)
        for r in rs:
            if r[2] == thread:
                agg[r[4]] += r[0]
        return sorted(agg.items(), key=lambda kv: -kv[1])[:n]

    out += ["", "== Profile: per map, top functions (samples; 500 = one second of one core) =="]
    def labkey(s):
        v = parse_map(s)
        return (v is None, v if v is not None else 0, s)
    for label in sorted(per_label, key=labkey):
        rs = per_label[label]
        mid = parse_map(label)
        title = f"{label} {names.get(mid, '')}" if mid is not None else label
        out += ["", f"-- {title}  (total {sum(r[0] for r in rs)})"]
        out.append(f"   game thread [{game_thread}]:")
        for fn, n in top(rs, game_thread, 5):
            out.append(f"     {n:>7}  {fn}")
        if gfx_thread:
            out.append(f"   gfx thread [{gfx_thread}]:")
            for fn, n in top(rs, gfx_thread, 3):
                out.append(f"     {n:>7}  {fn}")

    out += ["", "== Profile: top 60 functions overall =="]
    agg = defaultdict(lambda: [0, defaultdict(int), ""])
    for r in rows:
        a = agg[(r[3], r[4])]
        a[0] += r[0]
        a[1][r[2]] += r[0]
        a[2] = r[5]
    out.append(f"{'samples':>9}  {'share':>6}  {'group':<10}  {'thread':<22}  function")
    for (mod, fn), a in sorted(agg.items(), key=lambda kv: -kv[1][0])[:60]:
        t = max(a[1], key=a[1].get)
        out.append(f"{a[0]:>9}  {pct(a[0], total)}  {a[2]:<10}  {t[:22]:<22}  {fn} [{mod}]")

    out += ["", "== Loading (samples under '<map> load' labels) =="]
    if not loading:
        out.append("(none)")
    else:
        lt = sum(r[0] for rs in loading.values() for r in rs)
        out.append(f"total loading samples {lt}")
        out.append("")
        for label in sorted(loading, key=lambda s: -sum(r[0] for r in loading[s])):
            rs = loading[label]
            mid = parse_map(label)
            s = sum(r[0] for r in rs)
            fa = defaultdict(int)
            for r in rs:
                fa[r[4]] += r[0]
            tops = ", ".join(f"{f} {n}" for f, n in sorted(fa.items(), key=lambda kv: -kv[1])[:3])
            out.append(f"{label:>4} {names.get(mid, '')[:30]:<30} {s:>8}   {tops}")
        out += ["", "Top functions while loading, all maps:"]
        fa = defaultdict(int)
        for rs in loading.values():
            for r in rs:
                fa[r[4]] += r[0]
        for fn, n in sorted(fa.items(), key=lambda kv: -kv[1])[:15]:
            out.append(f"  {n:>8}  {pct(n, lt)}  {fn}")
    return "\n".join(out)


# --------------------------------------------------------------------- chart

def write_chart(out, maps):
    try:
        from PIL import Image, ImageDraw
    except ImportError:
        return False
    top = sorted(maps, key=lambda d: -d["frame_ms"])[:30]
    if not top:
        return False
    row_h, left, width = 22, 330, 1000
    img = Image.new("RGB", (width, row_h * len(top) + 50), "white")
    d = ImageDraw.Draw(img)
    d.text((10, 8), "Median frame_ms, 30 heaviest maps", fill="black")
    peak = max(x["frame_ms"] for x in top) or 1
    for i, m in enumerate(top):
        y = 34 + i * row_h
        d.text((10, y + 4), f"{m['map']} {m['name']}"[:50], fill="black")
        w = int((width - left - 80) * m["frame_ms"] / peak)
        d.rectangle([left, y + 2, left + w, y + row_h - 4], fill=(70, 120, 200))
        d.text((left + w + 6, y + 4), f"{m['frame_ms']:.2f}", fill="black")
    img.save(os.path.join(out, "report.png"))
    return True


def main():
    if len(sys.argv) != 2:
        print(__doc__)
        return 2
    out = sys.argv[1]
    names = load_map_names()
    parts = []
    per_map = read_benchmarks(out)
    maps = summarize_maps(per_map, names)
    if maps:
        write_maps_csv(out, maps)
        parts.append(maps_section(maps))
    else:
        parts.append("== Maps ==\n(no bench_run*.csv rows found)")
    parts.append(profile_section(read_profiles(out), names))
    for extra in ("crashes.txt", "timeouts.txt"):
        p = os.path.join(out, extra)
        if os.path.exists(p):
            parts.append(f"== {extra} ==\n" + open(p, encoding="utf-8", errors="replace").read().rstrip())
    text = "\n\n".join(parts) + "\n"
    with open(os.path.join(out, "report.txt"), "w", encoding="utf-8") as f:
        f.write(text)
    chart = write_chart(out, maps) if maps else False
    print(f"wrote report.txt, maps.csv{', report.png' if chart else ''} in {out}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
