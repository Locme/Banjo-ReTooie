#!/usr/bin/env python3
"""Sweeps every map with the host profiler and the benchmark recorder running.

Usage: py tools/perf_sweep.py [--maps AF,B8,...] [--out DIR] [--dwell 2] [--resume] [--dry-run]

It starts BanjoReTooie.exe, feeds it console commands on stdin, and watches logs\\console.log. If the game
crashes or hangs, it records the map, copies any crash reports and the benchmark csv, and restarts from the
next map. tools/perf_report.py turns the output folder into a report.
"""
import argparse
import glob
import os
import re
import shutil
import subprocess
import sys
import threading
import time
from datetime import datetime

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
EXE_DIR = os.path.join(REPO, "Release", "Optimized for newer CPUs (2013 and up)")
EXE = os.path.join(EXE_DIR, "BanjoReTooie.exe")
MAP_NAMES = os.path.join(REPO, "src", "game", "map_names.inc")
TEXTURE_SWEEP = os.path.join(REPO, "src", "game", "texture_sweep.cpp")
DEFAULT_OUT_ROOT = r"D:\Projects\Banjo Tooie N64\perf_sweep"
HANG_SECONDS = 120


def parse_maps():
    """Returns [(id, name)] in the sweep order: places first, cutscenes last, skipped maps left out."""
    skipped = {0x158, 0x18B}
    try:
        text = open(TEXTURE_SWEEP, encoding="utf-8", errors="replace").read()
        m = re.search(r"skipped_maps\[\]\s*=\s*\{(.*?)\}", text, re.S)
        if m:
            skipped = {int(x, 16) for x in re.findall(r"0x[0-9A-Fa-f]+", m.group(1))}
    except OSError:
        pass
    places, cutscenes = [], []
    for line in open(MAP_NAMES, encoding="utf-8", errors="replace"):
        m = re.match(r'\s*\{\s*(0x[0-9A-Fa-f]+)\s*,\s*"(.*)"\s*\}', line)
        if not m:
            continue
        mid, name = int(m.group(1), 16), m.group(2)
        if mid in skipped:
            continue
        (cutscenes if name.startswith("Cutscene") else places).append((mid, name))
    return places + cutscenes


SETUP = []  # --setup: console commands run before each run's first map (settings for this pass)


def build_commands(maps, out_dir, run, dwell):
    cmds = list(SETUP) + [f"hostprof start {os.path.join(out_dir, f'profile_run{run}.tsv')}", "bench start"]
    for mid, name in maps:
        h = f"{mid:X}"
        cmds += [
            f"echo SWEEP {h} {name}",
            f"hostprof label {h} load",
            f"warp id {h}",
            "wait control 20",
            f"hostprof label {h}",
            f"echo SWEEP_IN {h}",
            "wait 1s",
        ]
        for yaw in (0, 120, 240):
            cmds += [f"look {yaw} -15", f"wait {dwell}s"]
        cmds += ["look off", "wait 1s"]
    cmds += ["echo SWEEP_DONE", "bench stop", "wait 2s", "hostprof stop", "wait 1s", "quit"]
    return cmds


def config_dirs():
    dirs = [EXE_DIR]
    for env in ("LOCALAPPDATA", "APPDATA"):
        base = os.environ.get(env)
        if base:
            dirs.append(os.path.join(base, "BanjoTooieN64Recomp"))
    return [d for d in dirs if os.path.isdir(d)]


def files_newer_than(t, patterns):
    """Files under the exe and config folders modified after t that match any glob pattern."""
    found = []
    for d in config_dirs():
        for pat in patterns:
            for f in glob.glob(os.path.join(d, "**", pat), recursive=True):
                try:
                    if os.path.isfile(f) and os.path.getmtime(f) >= t:
                        found.append(f)
                except OSError:
                    pass
    return sorted(set(found), key=os.path.getmtime)


def kill_game():
    subprocess.run(["taskkill", "/F", "/IM", "BanjoReTooie.exe"], stdout=subprocess.DEVNULL,
                   stderr=subprocess.DEVNULL)


class Progress:
    """The index in the map list of the first map not yet finished, kept in progress.txt."""

    def __init__(self, path):
        self.path = path

    def read(self):
        try:
            m = re.search(r"next_index=(\d+)", open(self.path).read())
            return int(m.group(1)) if m else 0
        except OSError:
            return 0

    def write(self, index, total, note=""):
        with open(self.path, "w") as f:
            f.write(f"next_index={index}\ntotal={total}\nupdated={datetime.now():%Y-%m-%d %H:%M:%S}\n{note}\n")


def feed(proc, cmds):
    """Writes every command to the game's stdin; the pipe stays open so the game never sees end of input."""
    try:
        for c in cmds:
            proc.stdin.write((c + "\n").encode("utf-8"))
        proc.stdin.flush()
    except OSError:
        pass


def run_once(maps, start_index, out_dir, run, dwell, progress, crashes, timeouts):
    """Runs the game over maps[start_index:]. Returns the index to continue from, or None when done."""
    sub = maps[start_index:]
    cmds = build_commands(sub, out_dir, run, dwell)
    log_path = os.path.join(EXE_DIR, "logs", "console.log")
    log_pos = os.path.getsize(log_path) if os.path.exists(log_path) else 0
    started = time.time()
    out = open(os.path.join(out_dir, f"run{run}.out"), "wb")
    proc = subprocess.Popen([EXE], cwd=EXE_DIR, stdin=subprocess.PIPE, stdout=out, stderr=subprocess.STDOUT)
    threading.Thread(target=feed, args=(proc, cmds), daemon=True).start()
    print(f"run {run}: starting at map index {start_index} ({len(sub)} maps)")

    current = None  # index in maps of the last SWEEP line
    done = False
    last_new = time.time()
    pending = ""
    reason, code = None, None
    while True:
        time.sleep(1)
        if os.path.exists(log_path):
            size = os.path.getsize(log_path)
            if size < log_pos:
                log_pos = 0
            if size > log_pos:
                with open(log_path, "rb") as f:
                    f.seek(log_pos)
                    data = f.read()
                log_pos += len(data)
                pending += data.decode("utf-8", errors="replace")
                lines = pending.split("\n")
                pending = lines.pop()
                for line in lines:
                    m = re.search(r"SWEEP ([0-9A-Fa-f]+) ", line)
                    if m and "SWEEP_IN" not in line and "SWEEP_DONE" not in line:
                        mid = int(m.group(1), 16)
                        for i in range(start_index, len(maps)):
                            if maps[i][0] == mid:
                                current = i
                                break
                        last_new = time.time()
                        progress.write(current, len(maps), f"run={run} in map {mid:X}")
                        print(f"  map {mid:X} ({current + 1}/{len(maps)}) {maps[current][1]}")
                    elif "SWEEP_DONE" in line:
                        done = True
                    elif "MAJOR" in line and current is not None:
                        # Pass over crashes (memory_guard.cpp) caught a bad pointer here: the game went on.
                        mid, name = maps[current]
                        with open(crashes, "a", encoding="utf-8") as c:
                            c.write(f"{datetime.now():%H:%M:%S}\t{mid:X}\t{name}\tpassed over\t{line.strip()[:300]}\n")
                    elif "ERR" in line and "gave up waiting" in line and current is not None:
                        mid, name = maps[current]
                        with open(timeouts, "a", encoding="utf-8") as t:
                            t.write(f"{mid:X}\t{name}\tno control within 20 s\n")
        code = proc.poll()
        if code is not None:
            reason = None if done else "crash"
            break
        if time.time() - last_new > HANG_SECONDS and not done:
            reason = "hang"
            proc.kill()
            proc.wait()
            code = "killed"
            break
    out.close()
    kill_game()

    # The benchmark csv is only complete on a clean stop, but a crash leaves it as far as it got.
    for f in reversed(files_newer_than(started, ["benchmark_*.csv"])):
        shutil.copy2(f, os.path.join(out_dir, f"bench_run{run}.csv"))
        break

    if reason is None:
        return None
    idx = current if current is not None else start_index
    mid, name = maps[idx]
    with open(crashes, "a", encoding="utf-8") as c:
        c.write(f"{datetime.now():%H:%M:%S}\t{mid:X}\t{name}\t{reason}\t{code}\n")
    reports = [f for f in files_newer_than(started, ["*crash*", "*.dmp"])
               if os.path.abspath(f) != os.path.abspath(log_path)]
    if reports:
        dest = os.path.join(out_dir, f"crash_{mid:X}")
        os.makedirs(dest, exist_ok=True)
        for f in reports:
            try:
                shutil.copy2(f, dest)
            except OSError:
                pass
    print(f"  {reason} at map {mid:X} {name} (exit {code}); restarting after it")
    progress.write(idx + 1, len(maps), f"run={run} {reason} at {mid:X}")
    return idx + 1


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--maps", help="comma separated hex map ids; default all")
    ap.add_argument("--out", help="output folder")
    ap.add_argument("--dwell", type=int, default=2, help="seconds per camera angle")
    ap.add_argument("--resume", action="store_true", help="continue from progress.txt in --out")
    ap.add_argument("--setup", help="console commands, ; separated, run at the start of every run (e.g. a preset)")
    ap.add_argument("--teardown", help="console commands, ; separated, run once in a last start of the game after the sweep")
    ap.add_argument("--dry-run", action="store_true", help="print the command list and exit")
    args = ap.parse_args()

    maps = parse_maps()
    if args.maps:
        want = [int(x, 16) for x in args.maps.split(",") if x.strip()]
        names = dict(maps)
        maps = [(m, names.get(m, "?")) for m in want]

    if args.setup:
        SETUP.extend(c.strip() for c in args.setup.split(";") if c.strip())
    out_dir = args.out or os.path.join(DEFAULT_OUT_ROOT, datetime.now().strftime("%Y%m%d-%H%M%S"))
    if args.dry_run:
        print("\n".join(build_commands(maps, out_dir, 1, args.dwell)))
        return 0

    os.makedirs(out_dir, exist_ok=True)
    progress = Progress(os.path.join(out_dir, "progress.txt"))
    index = progress.read() if args.resume else 0
    crashes = os.path.join(out_dir, "crashes.txt")
    timeouts = os.path.join(out_dir, "timeouts.txt")
    run = 1
    if args.resume:
        existing = [int(m.group(1)) for f in glob.glob(os.path.join(out_dir, "run*.out"))
                    if (m := re.search(r"run(\d+)\.out$", f))]
        run = max(existing, default=0) + 1
    kill_game()
    while index is not None and index < len(maps):
        index = run_once(maps, index, out_dir, run, args.dwell, progress, crashes, timeouts)
        run += 1
    progress.write(len(maps), len(maps), "done")
    if args.teardown:
        # Put the settings back in a start of the game of its own, so a crash in the sweep does not leave them changed.
        cmds = [c.strip() for c in args.teardown.split(";") if c.strip()] + ["wait 2s", "quit"]
        proc = subprocess.Popen([EXE], cwd=EXE_DIR, stdin=subprocess.PIPE, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        feed(proc, cmds)
        try:
            proc.wait(timeout=120)
        except subprocess.TimeoutExpired:
            kill_game()
    print(f"sweep finished; output in {out_dir}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
