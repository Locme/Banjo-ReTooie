#!/usr/bin/env python3
"""Takes the same views of the game under several lighting setups, side by side, with the GPU time of each.

Usage: py tools/rt_shots.py --out D:\\rt_shots [--exe-dir DIR] [--configs FILE] [--views sm,jv,...] [--settle-ms 2500]
                            [--bench-s 3] [--no-bench]

For the ray tracing comparison in notes/ray-tracing-impact-plan.md (step 0). For each view it warps to the map, holds
the camera with `look`, then for each setup sets its settings with `set`, waits for the traced light to settle, takes a
screenshot and records a short benchmark. Every setup is shot from the same camera, one after another, so only the
settings differ. The views and setups are below; --configs takes a JSON file of setups instead, in the same shape
({"name": {"setting": value, ...}, ...}, in order).

A setup names only the settings it changes. Every setting any setup names is set for every setup: to the setup's value,
or else to its value in graphics.json as it was before the run, so one setup's change does not carry into the next.

Outputs, in --out:
  <view>/<setup>.png  the shots
  <view>/sheet.png    the setups side by side, each captioned with its name and GPU time per game frame
  results.csv         view, setup, GPU ms per game frame (the benchmark's average), shot path

The game is driven as tools/sun_search.py drives it (its Game class): commands to its stdin, answers read from
logs/console.log, and graphics.json is backed up first and put back at the end. Needs Pillow.
"""
import argparse
import csv
import glob
import json
import os
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import sun_search as ss  # noqa: E402
from PIL import Image, ImageDraw  # noqa: E402

# key, map id, camera commands (one shot per command). After a warp the run waits 7 s, so the level's name is gone. Picked to cover what lighting has to do: sunlit outdoor levels,
# caves and rooms lit by lamps, snow and sand that can blow out, water, metal, and a wide view for far shadows.
VIEWS = [
    ("sm", "AF", ["look 30 -15 700", "look 210 -25 1600"]),        # Spiral Mountain: grass, cliffs, sun
    ("jv", "142", ["look 60 -15 800"]),                            # Jinjo Village: houses, sun
    ("mt", "B8", ["look 0 -15 800", "look 180 -20 1600"]),         # Mayahem Temple: stone, jungle
    ("ggm", "C7", ["look 90 -15 800"]),                            # Glitter Gulch Mine: canyon, lamps
    ("ggm_cave", "D2", ["look 0 -15 600"]),                        # Gloomy Caverns: a cave
    ("ww", "D6", ["look 45 -15 900"]),                             # Witchyworld: lit signs, metal
    ("jrl", "1A7", ["look 0 -15 800"]),                            # Jolly Roger's Lagoon: water, town
    ("jrl_bar", "ED", ["look 180 -35 450"]),                         # Jolly's: a room with lamps
    ("tdl", "112", ["look 0 -15 900", "look 300 -35 2500"]),       # Terrydactyland: a wide view
    ("gi", "101", ["look 0 -10 600"]),                             # Grunty Industries floor 1: metal, inside
    ("hfp", "128", ["look 0 -15 800"]),                            # Hailfire Peaks, Icy Side: snow
    ("ccl", "136", ["look 0 -15 900"]),                            # Cloud Cuckooland: bright, open
]

# Where Banjo stands after each view's warp (`pos` 7 s after it, the same on every run). He is put back there and the
# camera aimed again before every shot: between shots he could drift, and the camera with him (a shot of a wall).
SPOTS = {
    "sm": (177.00, 1799.54, -274.00), "jv": (7603.00, -521.41, 3146.00), "mt": (7186.00, 2299.60, 897.00),
    "ggm": (-3193.92, -8.55, 14.57), "ggm_cave": (304.00, 18.13, 3458.00), "ww": (-6134.00, 49.47, 3443.00),
    "jrl": (-9002.00, 9149.51, -9474.00), "jrl_bar": (199.00, 69.53, 1128.00), "tdl": (-5973.00, 1553.01, -7116.00),
    "gi": (2415.00, 1451.67, -2729.00), "hfp": (606.00, 740.66, -3278.00), "ccl": (-2347.00, 10099.44, 137.00),
}

# Setups in order. "none" is the game's own lighting; "yours" is graphics.json's ray tracing as it is; the others change
# only what they name.
CONFIGS = {
    "none": {"lighting": "None"},
    "yours": {"lighting": "RayTracing"},
    "bounce_relit": {"lighting": "RayTracing", "ssgi": 50, "ray_tracing_relighting": 100,
                     "path_tracing": True, "path_tracing_bounces": 1},
}

SETTLE_MS = 2500  # the denoiser keeps light from frame to frame, so give it time to settle after a change
BENCH_S = 3
SHEET_W = 960
CAPTION_H = 48


def setting_text(value):
    if isinstance(value, bool):
        return "on" if value else "off"
    if isinstance(value, float) and value.is_integer():
        return str(int(value))
    return str(value)


def set_commands(configs, base):
    """For each setup, the `set` lines that bring every named setting to the setup's value or the base value."""
    keys = []
    for c in configs.values():
        for k in c:
            if k not in keys:
                keys.append(k)
    out = {}
    for name, c in configs.items():
        lines = []
        for k in keys:
            if k in c:
                v = c[k]
            elif k in base:
                v = base[k]
            else:
                continue
            lines.append("set %s %s" % (k, setting_text(v)))
        out[name] = lines
    return out


def bench_average(exe_dir, since):
    """The average GPU ms per game frame of the newest benchmark csv written after `since`, leaving out its first row."""
    files = [f for f in glob.glob(os.path.join(exe_dir, "benchmarks", "benchmark_*.csv")) if os.path.getmtime(f) >= since]
    if not files:
        return None
    path = max(files, key=os.path.getmtime)
    values = []
    with open(path, newline="") as f:
        for i, row in enumerate(csv.DictReader(f)):
            if i == 0:
                continue
            try:
                values.append(float(row["gpu_ms_per_game_frame"]))
            except (KeyError, ValueError):
                pass
    return (sum(values) / len(values)) if values else None


def write_sheet(path, tiles):
    """tiles: [(png path or None, caption)]. One row, each tile SHEET_W wide."""
    font = ss.load_font()
    images = []
    for p, cap in tiles:
        im = Image.open(p).convert("RGB") if p else Image.new("RGB", (16, 9), (40, 40, 40))
        h = int(im.height * SHEET_W / im.width)
        images.append((im.resize((SHEET_W, h), ss.RESAMPLE), cap))
    h = max(im.height for im, _ in images) + CAPTION_H
    sheet = Image.new("RGB", (SHEET_W * len(images), h), (20, 20, 20))
    draw = ImageDraw.Draw(sheet)
    for i, (im, cap) in enumerate(images):
        sheet.paste(im, (i * SHEET_W, CAPTION_H))
        draw.text((i * SHEET_W + 12, 10), cap, fill=(240, 240, 240), font=font)
    sheet.save(path)


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--out", required=True)
    ap.add_argument("--exe-dir", default=ss.DEFAULT_EXE_DIR)
    ap.add_argument("--configs")
    ap.add_argument("--views", help="comma-separated view keys (default: all)")
    ap.add_argument("--settle-ms", type=int, default=SETTLE_MS)
    ap.add_argument("--bench-s", type=int, default=BENCH_S)
    ap.add_argument("--no-bench", action="store_true")
    ap.add_argument("--timeout", type=int, default=90)
    args = ap.parse_args()

    configs = CONFIGS
    if args.configs:
        with open(args.configs, encoding="utf-8") as f:
            configs = json.load(f)
    views = VIEWS
    if args.views:
        want = args.views.split(",")
        views = [v for v in VIEWS if v[0] in want]

    exe_dir = os.path.abspath(args.exe_dir)
    os.makedirs(args.out, exist_ok=True)
    with open(os.path.join(exe_dir, ss.GRAPHICS), encoding="utf-8") as f:
        base = json.load(f)
    lines = set_commands(configs, base)
    ss.backup_graphics(exe_dir)
    ss.apply_shot_settings(exe_dir)

    results_path = os.path.join(args.out, "results.csv")
    game = ss.Game(exe_dir, args.timeout)

    class Run:
        pass
    run = Run()
    run.game = game
    try:
        game.start()
        # The same sun every time: the day and night cycle would move it between setups.
        game.run_batch(["set day_night off"], args.timeout)
        # Warm up: the first frames after a start can be drawn before ray tracing has taken hold (its structures are
        # built on the first map), so the first view's first shot came out as if it were off. One map and a wait first,
        # never the first view's own map (warping into the map it is already in left the camera somewhere else).
        warm = "AF" if views[0][1] != "AF" else "142"
        game.run_batch(["warp id %s" % warm, "wait control", "set lighting RayTracing", "wait 10s"], ss.WARP_TIMEOUT)
        with open(results_path, "w", newline="") as rf:
            out = csv.writer(rf)
            out.writerow(["view", "setup", "gpu_ms", "shot"])
            for key, map_id, looks in views:
                ss.say("%s: map %s" % (key, map_id))
                errs = [l for l in game.run_batch(["warp id %s" % map_id, "wait control", "wait 7s"], ss.WARP_TIMEOUT)
                        if ss.ERR_RE.match(l)]
                if errs:
                    ss.say("  warp failed: %s" % errs[0])
                    continue
                for li, look in enumerate(looks):
                    view = key if len(looks) == 1 else "%s_%d" % (key, li + 1)
                    folder = os.path.join(args.out, view)
                    os.makedirs(folder, exist_ok=True)
                    game.run_batch([look, "wait 500ms"], args.timeout)
                    tiles = []
                    for name in configs:
                        spot = SPOTS.get(key)
                        pin = (["goto %.2f %.2f %.2f" % spot, "wait 200ms"] if spot else []) + [look, "wait 300ms"]
                        cmds = pin + lines[name] + ["wait %dms" % args.settle_ms]
                        shot, errors = ss.take_shot(run, cmds, name + ".png", folder, args.timeout)
                        if errors:
                            ss.say("  %s %s: %s" % (view, name, errors[0]))
                        gpu = None
                        if not args.no_bench and shot:
                            since = time.time() - 1
                            game.run_batch(["bench start", "wait %ds" % args.bench_s, "bench stop", "wait 1s"],
                                           args.timeout + args.bench_s)
                            gpu = bench_average(exe_dir, since)
                        out.writerow([view, name, "" if gpu is None else "%.2f" % gpu, shot or ""])
                        rf.flush()
                        ss.say("  %s %s: %s" % (view, name, "%.2f ms" % gpu if gpu is not None else "no time"))
                        tiles.append((shot, name + ("" if gpu is None else "  %.2f ms" % gpu)))
                    write_sheet(os.path.join(folder, "sheet.png"), tiles)
                    game.run_batch(["look off"], args.timeout)
    finally:
        game.stop()
        ss.restore_graphics(exe_dir)


if __name__ == "__main__":
    main()
