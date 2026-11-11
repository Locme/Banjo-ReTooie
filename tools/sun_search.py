#!/usr/bin/env python3
"""Searches sun positions for the least shadow, one map at a time.

Usage: py tools/sun_search.py --maps AF,1A --out D:\\sun_search [--azimuths ...] [--elevations ...]
                              [--views top,g0,g120,g240] [--exe-dir DIR] [--timeout 60] [--resume]
                              [--choices DIR]

For each map it warps there, frames the top view on the whole level (look overview), and takes a baseline of each
camera view with ray tracing off. Then it turns ray
tracing on and takes the same views with the sun at each (azimuth, elevation) in the grid. Each shot is compared
with its baseline: shadow_frac is the share of lit pixels the sun's shadow darkens, and darkening is how much
darker on average. The four best suns in each map are kept, spread out, with their PNGs and a contact sheet.

The game is driven through its developer console: commands go to its stdin, results are read from
logs\\console.log in the game folder, and screenshots are read from the screenshots folder beside the exe.
A screenshot is matched to its command by order: the Nth "[screenshot] saved" line is the Nth screenshot sent.

Outputs, in --out:
  results.csv   one row per sun and view (status ok, or skipped with the failing view), and one map-level row
                with an empty azimuth (status enclosed, or skipped with the reason in the view column)
  best.csv      the 4 best suns per map with their mean scores, chosen to be spread out
  <map hex>/    the PNGs of those suns and the baselines of each map, and sheet.png: a 2x2 contact
                sheet of their top views with a caption on each tile, and frame_probe.png, the shot
                the top view was framed from
  Choices/      (--choices) for each ok map, the full-size top shots of its kept suns as
                <map hex> <name>\\A az<az> el<el>.png, A being the best

A map counts as done for --resume once its best.csv rows exist or its map-level row is in results.csv.
Needs Pillow and numpy.
"""
import argparse
import csv
import ctypes
import json
import math
import os
import re
import shutil
import subprocess
import sys
import time

import numpy as np
from PIL import Image, ImageDraw, ImageFont

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DEFAULT_EXE_DIR = os.path.join(REPO, "Release", "Optimized for newer CPUs (2013 and up)")
DEFAULT_CHOICES = os.path.join(REPO, "Choices")
MAP_NAMES = os.path.join(REPO, "src", "game", "map_names.inc")

# The camera for each ground view, as console commands. The top view is TOP_CAM.
VIEWS = {
    "g0": "look 0 -25 700",
    "g120": "look 120 -25 700",
    "g240": "look 240 -25 700",
}
VIEW_NAMES = ("top", "g0", "g120", "g240")
DEFAULT_VIEWS = "top,g0,g120,g240"
DEFAULT_AZIMUTHS = "0,45,90,135,180,225,270,315"
DEFAULT_ELEVATIONS = "45,60,75"

TARGET_W = 480            # pictures are shrunk to this width before scoring
SHADOW_RATIO = 0.85       # a pixel counts as shadowed when its light is below this share of the baseline
MIN_LUMA = 0.03           # baseline pixels darker than this are left out of the score
ENCLOSED_AFTER = 2        # the first two suns stand on opposite sides; the enclosed check runs after them
ENCLOSED_DIFF = 1.5 / 255 # when no view changes more than this (mean brightness, 0..1) between them, the sun
                          # does not reach the map (a room or a cave), so its other suns are skipped
KEEP_BEST = 4             # suns kept per map, chosen to be spread out
SEP_AZ = 60.0             # two kept suns are apart when their azimuths differ by at least this much...
SEP_EL = 999.0            # ...or, when closer in azimuth, their elevations differ by this much (off: L wants four directions)
SHEET_TILE_W = 960        # width of each tile of the contact sheet, in pixels
CAPTION_H = 56            # height of the caption bar on each tile

POLL = 0.05               # seconds between log reads
SAVED_EXTRA = 20.0        # seconds to wait for a late "saved" line after its sync (the screen can stall for seconds while ray tracing takes in a whole level)
GAME_QUIT_WAIT = 30       # seconds the game gets to quit after `quit`
BOOT_TIMEOUT = 300        # seconds for the game to start and answer its first sync
WARP_TIMEOUT = 180        # seconds for a warp, which may load file 1 first, then wait for control

GRAPHICS = "graphics.json"
BACKUP = "graphics.json.sunsearch-bak"
RESAMPLE = getattr(Image, "Resampling", Image).LANCZOS

ERR_RE = re.compile(r"^\[[^\]]*\] ERR\b")
SAVED_RE = re.compile(r"\[screenshot\] saved (.*) \(\d+x\d+\)\s*$")
MAP_RE = re.compile(r'\{\s*0x([0-9A-Fa-f]+)\s*,\s*"((?:[^"\\]|\\.)*)"\s*\}')

RESULT_HEADER = ["map", "name", "status", "azimuth", "elevation", "view", "shadow_frac", "darkening"]
BEST_HEADER = ["map", "name", "rank", "azimuth", "elevation", "mean_shadow_frac", "mean_darkening"]


def say(text):
    """Prints a progress line now, not when the buffer fills."""
    print(text, flush=True)


class GameLost(Exception):
    """The game exited, or did not answer a sync in time."""


# ---------------------------------------------------------------- inputs

def load_map_names(path):
    """Returns [(id, name)] from map_names.inc, in file order."""
    maps = []
    with open(path, encoding="utf-8", errors="replace") as f:
        for line in f:
            if line.lstrip().startswith("//"):
                continue
            for m in MAP_RE.finditer(line):
                maps.append((int(m.group(1), 16), m.group(2)))
    return maps


def parse_maps(arg, names):
    """Turns --maps into [(id, name)]. 'all' means every map whose name does not start with Cutscene."""
    if arg.strip().lower() == "all":
        return [(mid, name) for mid, name in names if not name.startswith("Cutscene")]
    lookup = dict(names)
    maps = []
    for part in arg.split(","):
        part = part.strip()
        if part:
            mid = int(part, 16)
            maps.append((mid, lookup.get(mid, "unnamed map")))
    return maps


def parse_views(arg):
    views = [v.strip().lower() for v in arg.split(",") if v.strip()]
    for v in views:
        if v not in VIEW_NAMES:
            sys.exit("unknown view %r (the views are %s)" % (v, ", ".join(VIEW_NAMES)))
    return views


def parse_numbers(arg):
    return [float(x) for x in arg.split(",") if x.strip()]


def fmt(v):
    """Writes a number the way the console and the file names expect (45, not 45.0)."""
    return "%g" % v


# ---------------------------------------------------------------- csv files

def read_csv_rows(path):
    """The data rows of a csv file, without its header. Empty when the file is missing."""
    if not os.path.exists(path):
        return []
    with open(path, newline="", encoding="utf-8") as f:
        rows = list(csv.reader(f))
    return rows[1:] if rows else []


def append_rows(path, header, rows):
    """Appends rows, writing the header first when the file is new."""
    new = not os.path.exists(path) or os.path.getsize(path) == 0
    with open(path, "a", newline="", encoding="utf-8") as f:
        w = csv.writer(f)
        if new:
            w.writerow(header)
        for r in rows:
            w.writerow(r)
        f.flush()


def drop_map_rows(path, header, key):
    """Removes every row of one map, so a map that runs again does not leave duplicate rows."""
    rows = read_csv_rows(path)
    keep = [r for r in rows if r and r[0] != key]
    if len(keep) == len(rows):
        return
    tmp = path + ".tmp"
    with open(tmp, "w", newline="", encoding="utf-8") as f:
        w = csv.writer(f)
        w.writerow(header)
        for r in keep:
            w.writerow(r)
    os.replace(tmp, path)


def load_done(results_path, best_path):
    """Map keys that finished: a best.csv row, or a map-level enclosed or skipped row."""
    done = {r[0] for r in read_csv_rows(best_path) if r}
    for r in read_csv_rows(results_path):
        if len(r) >= 4 and r[3] == "" and r[2] in ("enclosed", "skipped"):
            done.add(r[0])
    return done


# ---------------------------------------------------------------- scoring

def load_small(path, size=None):
    """Loads a PNG as RGB floats in 0..1, shrunk to TARGET_W wide, or to size (w, h) when given."""
    with Image.open(path) as im:
        img = im.convert("RGB")
    if size is None:
        w, h = img.size
        size = (TARGET_W, max(1, round(h * TARGET_W / w)))
    if img.size != size:
        img = img.resize(size, RESAMPLE)
    return np.asarray(img, dtype=np.float32) / 255.0


def luma(arr):
    """Brightness of each pixel, from its red, green and blue."""
    return 0.299 * arr[..., 0] + 0.587 * arr[..., 1] + 0.114 * arr[..., 2]


def make_base(arr):
    """The baseline's brightness and which pixels are valid to score."""
    l = luma(arr)
    return l, l > MIN_LUMA


def score(base_l, valid, shot):
    """Returns (shadow_frac, darkening) of a shot against its baseline."""
    if int(valid.sum()) == 0:
        return 0.0, 0.0
    on_l = luma(shot)
    ratio = on_l[valid] / np.maximum(base_l[valid], 1e-4)
    shadow_frac = float(np.mean(ratio < SHADOW_RATIO))
    darkening = float(np.mean(np.clip(1.0 - ratio, 0.0, 1.0)))
    return shadow_frac, darkening


def angle_gap(a, b):
    """The smallest difference between two azimuths, in degrees (0 to 180)."""
    d = abs(a - b) % 360.0
    return min(d, 360.0 - d)


def pick_distinct(ranked, count=KEEP_BEST):
    """Walks the suns from best to worst and takes a sun only when it is spread out from those taken.

    A sun is far enough from each taken sun when its azimuth is at least SEP_AZ away, or when its elevation
    differs by at least SEP_EL. Fewer than count suns may come back.
    """
    taken = []
    for s in ranked:
        clear = True
        for t in taken:
            if angle_gap(s["az"], t["az"]) >= SEP_AZ:
                continue
            if abs(s["el"] - t["el"]) >= SEP_EL:
                continue
            clear = False
            break
        if clear:
            taken.append(s)
            if len(taken) == count:
                break
    return taken


def load_font():
    """A large default font. Older Pillow has no size argument, so it falls back to the small one."""
    try:
        return ImageFont.load_default(size=28)
    except (TypeError, AttributeError):
        return ImageFont.load_default()


def write_sheet(path, tiles):
    """Writes a 2x2 contact sheet. tiles is a list of (caption, png path), at most four, placed A to D."""
    font = load_font()
    loaded = []
    for caption, src in tiles:
        with Image.open(src) as im:
            img = im.convert("RGB")
        w, h = img.size
        th = max(1, round(h * SHEET_TILE_W / w))
        loaded.append((caption, img.resize((SHEET_TILE_W, th), RESAMPLE)))
    tile_h = max(img.size[1] for _, img in loaded)
    sheet = Image.new("RGB", (2 * SHEET_TILE_W, 2 * tile_h), (0, 0, 0))
    draw = ImageDraw.Draw(sheet)
    slots = [(0, 0), (1, 0), (0, 1), (1, 1)]
    for i, (caption, img) in enumerate(loaded):
        col, row = slots[i]
        x, y = col * SHEET_TILE_W, row * tile_h
        sheet.paste(img, (x, y))
        draw.rectangle([x, y, x + SHEET_TILE_W, y + CAPTION_H], fill=(0, 0, 0))
        draw.text((x + 16, y + 12), caption, fill=(255, 255, 255), font=font)
    sheet.save(path)


# ---------------------------------------------------------------- top view and choices

UNSAFE_NAME_RE = re.compile(r'[\\/:*?"<>|]')
# The top view: the game frames the whole level from above itself (look overview measures it with its collision and
# widens the field of view when the level is too large for play's), with the shadows reaching that far out.
TOP_CAM = "farshadows 6; look overview"


def safe_name(text):
    """Makes text usable as a file or folder name on Windows: bad characters become '-', and trailing dots and spaces go."""
    return UNSAFE_NAME_RE.sub("-", text).rstrip(" .")


def choice_folder(run, key, name):
    """The map's folder in the Choices folder."""
    return os.path.join(run.choices, safe_name("%s %s" % (key, name)))


def copy_choices(run, key, name, best, folder):
    """Writes one picture per kept sun into the map's Choices folder, A to D in rank order: the whole-level top shot
    full size, with the ground views side by side in a strip under it, so the sun can be judged both ways."""
    dest = choice_folder(run, key, name)
    os.makedirs(dest, exist_ok=True)
    for i, s in enumerate(best):
        fname = safe_name("%s az%s el%s.png" % ("ABCD"[i], fmt(s["az"]), fmt(s["el"])))
        shots = s["shots"]
        if "top" not in shots:
            continue
        top = Image.open(os.path.join(folder, os.path.basename(shots["top"]))).convert("RGB")
        ground = [v for v in ("g0", "g120", "g240") if v in shots]
        if not ground:
            top.save(os.path.join(dest, fname))
            continue
        tile_w = top.width // len(ground)
        tiles = []
        for v in ground:
            g = Image.open(os.path.join(folder, os.path.basename(shots[v]))).convert("RGB")
            tiles.append(g.resize((tile_w, round(g.height * tile_w / g.width))))
        strip_h = max(t.height for t in tiles)
        out = Image.new("RGB", (top.width, top.height + strip_h))
        out.paste(top, (0, 0))
        for k, t in enumerate(tiles):
            out.paste(t, (k * tile_w, top.height))
        out.save(os.path.join(dest, fname))
    say("  copied the top shots to %s" % dest)


# ---------------------------------------------------------------- files

def list_pngs(folder):
    """The PNG file names in a folder, or none when it is missing."""
    try:
        return {n for n in os.listdir(folder) if n.lower().endswith(".png")}
    except OSError:
        return set()


def wait_stable(path, timeout):
    """Waits until a file exists, its size has stopped changing and it reads as a whole picture. Returns the path,
    or None. A 4K shot can stall part-written for longer than the size check waits, so the picture is read through too."""
    deadline = time.monotonic() + timeout
    last, same = -1, 0
    while time.monotonic() < deadline:
        try:
            size = os.path.getsize(path)
        except OSError:
            size = -1
        if size > 0 and size == last:
            same += 1
            if same >= 3:
                try:
                    with Image.open(path) as im:
                        im.load()
                    return path
                except (OSError, SyntaxError):
                    same = 0
        else:
            same = 0
        last = size
        time.sleep(POLL * 2)
    return None


def move_file(src, dst):
    """Moves a file, retrying while the game or a virus scanner still holds it."""
    for _ in range(20):
        try:
            shutil.move(src, dst)
            return
        except PermissionError:
            time.sleep(0.1)
    raise OSError("could not move %s" % src)


# ---------------------------------------------------------------- settings file

def backup_graphics(exe_dir):
    """Copies graphics.json aside. A backup left by an earlier run is kept, since it holds the real settings."""
    g = os.path.join(exe_dir, GRAPHICS)
    b = os.path.join(exe_dir, BACKUP)
    if os.path.exists(b):
        say("WARNING: %s is left from an earlier run; it is kept and put back at the end" % BACKUP)
        return
    if not os.path.exists(g):
        say("no %s yet, so there is nothing to back up" % GRAPHICS)
        return
    shutil.copy2(g, b)
    say("backed up %s to %s" % (GRAPHICS, BACKUP))


# The shots are drawn at 4K, whatever the window's size. The window is moved off every screen once the game is up, so
# it stays out of the way: minimized, or fullscreen under other windows, the game presents nothing, and a screenshot
# is taken as a frame is presented.
SHOT_SETTINGS = {"wm_option": "Windowed", "res_option": "2160p"}
OFFSCREEN_SIZE = (1920, 1080)


def apply_shot_settings(exe_dir):
    """Writes SHOT_SETTINGS into graphics.json, after backup_graphics has kept the real one."""
    g = os.path.join(exe_dir, GRAPHICS)
    try:
        with open(g, encoding="utf-8") as f:
            settings = json.load(f)
    except (OSError, ValueError):
        settings = {}
    settings.update(SHOT_SETTINGS)
    with open(g, "w", encoding="utf-8") as f:
        json.dump(settings, f, indent=4, sort_keys=True)
    say("graphics.json for the shots: %s" % ", ".join("%s %s" % kv for kv in SHOT_SETTINGS.items()))


def move_offscreen(pid):
    """Moves the visible windows of the process left of every screen, 16:9 (Windows only). Returns how many it moved."""
    if os.name != "nt":
        return 0
    user32 = ctypes.windll.user32
    found = []
    proc_type = ctypes.WINFUNCTYPE(ctypes.c_bool, ctypes.c_void_p, ctypes.c_void_p)

    def each(hwnd, _):
        owner = ctypes.c_ulong()
        user32.GetWindowThreadProcessId(ctypes.c_void_p(hwnd), ctypes.byref(owner))
        if owner.value == pid and user32.IsWindowVisible(ctypes.c_void_p(hwnd)):
            found.append(hwnd)
        return True

    user32.EnumWindows(proc_type(each), None)
    left = user32.GetSystemMetrics(76)  # SM_XVIRTUALSCREEN: the left edge of all the screens together
    w, h = OFFSCREEN_SIZE
    for hwnd in found:
        # SWP_NOZORDER | SWP_NOACTIVATE
        user32.SetWindowPos(ctypes.c_void_p(hwnd), None, left - w - 200, 0, w, h, 0x0004 | 0x0010)
    return len(found)


def restore_graphics(exe_dir):
    """Puts the backup back over graphics.json, then removes the backup so a later run starts fresh."""
    g = os.path.join(exe_dir, GRAPHICS)
    b = os.path.join(exe_dir, BACKUP)
    if not os.path.exists(b):
        return
    try:
        shutil.copy2(b, g)
        os.remove(b)
        say("put %s back" % GRAPHICS)
    except OSError as e:
        say("could not put %s back (the backup is still at %s): %s" % (GRAPHICS, b, e))


# ---------------------------------------------------------------- game process

class LogTail:
    """Reads new complete lines from the console log, starting again from the top if it is truncated."""

    def __init__(self, path):
        self.path = path
        self.offset = 0
        self.partial = ""

    def read_new(self):
        try:
            size = os.path.getsize(self.path)
        except OSError:
            return []
        if size < self.offset:
            self.offset = 0
            self.partial = ""
        if size == self.offset:
            return []
        try:
            with open(self.path, "rb") as f:
                f.seek(self.offset)
                data = f.read(size - self.offset)
        except OSError:
            return []
        self.offset += len(data)
        parts = (self.partial + data.decode("utf-8", errors="replace")).split("\n")
        self.partial = parts.pop()  # the last part may be a line still being written
        return [p.rstrip("\r") for p in parts]


class Game:
    """The game process, driven through its console."""

    def __init__(self, exe_dir, timeout):
        self.exe_dir = exe_dir
        self.exe = os.path.join(exe_dir, "BanjoReTooie.exe")
        self.log_path = os.path.join(exe_dir, "logs", "console.log")
        self.shots_dir = os.path.join(exe_dir, "screenshots")
        self.timeout = timeout
        self.proc = None
        self.tail = None
        self.sync_no = 0
        self.shots_sent = 0
        self.saved = []        # paths from "[screenshot] saved" lines, in order
        self.last_shots = []   # the saved paths for the screenshots of the last batch

    def start(self):
        """Starts the game and waits for its first sync, so the console is up."""
        os.makedirs(os.path.dirname(self.log_path), exist_ok=True)
        try:
            # The game empties its log at start too. Doing it here means no old lines are read.
            open(self.log_path, "w").close()
        except OSError:
            pass
        self.tail = LogTail(self.log_path)
        self.sync_no = 0
        self.shots_sent = 0
        self.saved = []
        self.proc = subprocess.Popen([self.exe], cwd=self.exe_dir, stdin=subprocess.PIPE)
        say("started the game (pid %d)" % self.proc.pid)
        self.run_batch([], BOOT_TIMEOUT)
        say("the game is up; moved %d window(s) off the screens" % move_offscreen(self.proc.pid))

    def send(self, line):
        """Writes one console command to the game's stdin."""
        if self.proc is None or self.proc.poll() is not None:
            raise GameLost("the game is not running")
        try:
            self.proc.stdin.write((line + "\n").encode("utf-8"))
            self.proc.stdin.flush()
        except OSError:
            raise GameLost("the game closed its input")

    def run_batch(self, cmds, timeout):
        """Sends cmds, then a sync echo, and waits for the echo. Returns the log lines read meanwhile."""
        self.sync_no += 1
        token = "SYNC_%d" % self.sync_no
        before = self.shots_sent
        for c in cmds:
            self.send(c)
            if c.strip() == "screenshot":
                self.shots_sent += 1
        # The saved line of a screenshot can arrive after the next commands, so give it a moment.
        self.send("wait 300ms")
        self.send("echo " + token)
        lines = self.wait_for(token, timeout)
        self.last_shots = self.saved[before:self.shots_sent]
        return lines

    def wait_for(self, token, timeout):
        """Reads the log until the sync token shows up, and until the screenshots of the batch are saved."""
        pat = re.compile(re.escape(token) + r"(?!\d)")
        lines = []
        deadline = time.monotonic() + timeout
        synced_at = None
        while True:
            if self.proc.poll() is not None:
                raise GameLost("the game exited (code %s)" % self.proc.returncode)
            new = self.tail.read_new()
            for line in new:
                m = SAVED_RE.search(line)
                if m:
                    self.saved.append(os.path.normpath(m.group(1).strip()))
            lines.extend(new)
            if synced_at is None and any(pat.search(line) for line in new):
                synced_at = time.monotonic()
            if synced_at is not None:
                if len(self.saved) >= self.shots_sent or time.monotonic() > synced_at + SAVED_EXTRA:
                    return lines
            elif time.monotonic() > deadline:
                raise GameLost("no answer to %s in %d s" % (token, timeout))
            time.sleep(POLL)

    def stop(self, polite=True):
        """Ends the game. A polite stop sends quit and waits up to 30 s before killing it."""
        if self.proc is None:
            return
        if self.proc.poll() is None:
            if polite:
                try:
                    self.send("quit")
                except GameLost:
                    pass
                try:
                    self.proc.wait(timeout=GAME_QUIT_WAIT)
                except subprocess.TimeoutExpired:
                    say("the game did not quit in %d s; killing it" % GAME_QUIT_WAIT)
                    self.proc.kill()
                    self.proc.wait()
            else:
                self.proc.kill()
                self.proc.wait()
        try:
            self.proc.stdin.close()
        except OSError:
            pass
        self.proc = None


# ---------------------------------------------------------------- shots

def take_shot(run, cmds, name, stage, timeout):
    """Runs cmds, then a screenshot. Returns (path in stage, errors). The shot is moved into stage."""
    game = run.game
    for attempt in (1, 2):
        lines = game.run_batch(cmds + ["screenshot"], timeout)
        errors = [l for l in lines if ERR_RE.match(l)]
        if errors:
            return None, errors
        if len(game.last_shots) == 1:
            break
        # Seen once on a room (Mumbo's Skull) from its 19th sun on: the shots stopped coming. Try once more.
        say("  %s: no saved line for the screenshot%s" % (name, ", trying again" if attempt == 1 else ""))
        if attempt == 2:
            return None, ["the screenshot was not saved (no saved line)"]
    src = wait_stable(game.last_shots[0], timeout)
    if src is None:
        return None, ["the screenshot file is missing: %s" % game.last_shots[0]]
    dst = os.path.join(stage, name)
    move_file(src, dst)
    return dst, []


def clean_leftovers(run):
    """Deletes screenshots the run made that were not kept, so the disk does not fill up.

    Only PNGs that appeared since the run started are touched.
    """
    for n in list_pngs(run.game.shots_dir) - run.snapshot:
        try:
            os.remove(os.path.join(run.game.shots_dir, n))
        except OSError:
            pass


def errors_in(lines):
    return [l for l in lines if ERR_RE.match(l)]


# ---------------------------------------------------------------- one map

class Run:
    """Everything one run shares: the game, the options and the output files."""

    def __init__(self, args, views, azs, els, exe_dir):
        self.out = os.path.abspath(args.out)
        self.views = views
        self.azs = azs
        self.els = els
        self.timeout = args.timeout
        self.warp_timeout = max(args.timeout, WARP_TIMEOUT)
        self.results = os.path.join(self.out, "results.csv")
        self.best = os.path.join(self.out, "best.csv")
        self.choices = os.path.abspath(args.choices)
        self.game = Game(exe_dir, args.timeout)
        self.snapshot = list_pngs(self.game.shots_dir)


def write_map_skip(run, mid, name, reason):
    """Records a map that did not finish, with the reason in the view column."""
    key = "%X" % mid
    append_rows(run.results, RESULT_HEADER, [[key, name, "skipped", "", "", reason, "", ""]])
    say("  skipped: %s" % reason)


def run_sun(run, base, stage, cams, az, el):
    """Shoots one sun in every view. Returns a dict with the scores, or ok False when a shot failed."""
    sun = {"az": az, "el": el, "ok": True, "fracs": {}, "darks": {}, "shots": {}, "fail": "", "reason": ""}
    for i, view in enumerate(run.views):
        cmds = []
        if i == 0:
            # The traced light takes a moment to settle after the sun or the camera moves.
            cmds += ["sun %s %s" % (fmt(az), fmt(el)), "wait 1500ms"]
        cmds += [cams[view], "wait 1000ms"]
        name = "%s_az%s_el%s.png" % (view, fmt(az), fmt(el))
        path, errors = take_shot(run, cmds, name, stage, run.timeout)
        if errors:
            sun["ok"] = False
            sun["fail"] = view
            sun["reason"] = errors[0]
            break
        base_l, valid, size = base[view]
        shot = load_small(path, size)
        frac, dark = score(base_l, valid, shot)
        sun["fracs"][view] = frac
        sun["darks"][view] = dark
        sun["shots"][view] = path
    return sun


def run_map(run, mid, name):
    """Runs one map. Returns 'ok', 'enclosed' or 'skipped'. Raises GameLost when the game dies."""
    key = "%X" % mid
    folder = os.path.join(run.out, key)
    stage = os.path.join(folder, "stage")
    shutil.rmtree(folder, ignore_errors=True)
    shutil.rmtree(choice_folder(run, key, name), ignore_errors=True)
    os.makedirs(stage)
    game = run.game

    lines = game.run_batch(["warp id %s" % key, "wait control", "wait 6s"], run.warp_timeout)
    errs = errors_in(lines)
    if errs:
        write_map_skip(run, mid, name, "warp failed: " + errs[0])
        shutil.rmtree(folder, ignore_errors=True)
        clean_leftovers(run)
        return "skipped"

    # The top view is framed on this level before the baselines, so its camera suits the map.
    # The ground views keep the shadows' play distances; the top view, far above, has them reach out with farshadows
    # (in play they fade out 4000 to 7000 units from the camera, so a whole level from above showed none).
    cams = {v: "farshadows off; " + c for v, c in VIEWS.items()}
    cams["top"] = TOP_CAM

    # Baselines: ray tracing off, so the picture has no sun shadows at all.
    base, base_paths = {}, {}
    for view in run.views:
        cmds = [cams[view], "wait 1000ms", "set ray_tracing off", "set sun_shadows 0", "wait 1500ms"]
        path, errors = take_shot(run, cmds, "%s_base.png" % view, stage, run.timeout)
        if errors:
            write_map_skip(run, mid, name, "baseline %s failed: %s" % (view, errors[0]))
            shutil.rmtree(folder, ignore_errors=True)
            clean_leftovers(run)
            return "skipped"
        arr = load_small(path)
        size = (arr.shape[1], arr.shape[0])
        base_l, valid = make_base(arr)
        base[view] = (base_l, valid, size)
        base_paths[view] = path

    # Ray tracing on for the sun shots. The sun is then set in each shot.
    lines = game.run_batch(["set ray_tracing on", "set sun_shadows 0", "wait 1500ms"], run.timeout)
    errs = errors_in(lines)
    if errs:
        write_map_skip(run, mid, name, "ray tracing on failed: " + errs[0])
        shutil.rmtree(folder, ignore_errors=True)
        clean_leftovers(run)
        return "skipped"

    grid = [(az, el) for az in run.azs for el in run.els]
    # Two opposite suns first, for the enclosed check: ray tracing darkens a room's corners whatever the sun, so the
    # shadow against the game's lighting can't tell a room; a sun that changes nothing between opposite sides can.
    first = [(run.azs[0], run.els[0]), ((run.azs[0] + 180) % 360, run.els[0])]
    grid = [g for g in first if g in grid] + [g for g in grid if g not in first]
    suns = []
    enclosed = False
    tried = 0
    for az, el in grid:
        if enclosed:
            break
        tried += 1
        sun = run_sun(run, base, stage, cams, az, el)
        suns.append(sun)
        if sun["ok"]:
            rows = [[key, name, "ok", fmt(az), fmt(el), v, "%.5f" % sun["fracs"][v], "%.5f" % sun["darks"][v]]
                    for v in run.views]
            mean_frac = sum(sun["fracs"].values()) / len(sun["fracs"])
            say("  sun az %s el %s: mean shadow %.4f" % (fmt(az), fmt(el), mean_frac))
        else:
            rows = [[key, name, "skipped", fmt(az), fmt(el), sun["fail"], "", ""]]
            say("  sun az %s el %s: skipped (%s)" % (fmt(az), fmt(el), sun["reason"]))
        append_rows(run.results, RESULT_HEADER, rows)

        if tried == ENCLOSED_AFTER and len(suns) == 2 and all(x["ok"] for x in suns):
            # Ground views only: from above, a room's roof or the outside of its hut is in the sun.
            ground = [v for v in run.views if v != "top"] or run.views
            change = max(float(np.abs(luma(load_small(suns[0]["shots"][v])) - luma(load_small(suns[1]["shots"][v]))).mean())
                         for v in ground)
            say("  opposite suns change the picture by %.4f at most" % change)
            if change < ENCLOSED_DIFF:
                enclosed = True
                say("  map looks enclosed: the other suns are skipped")

    # Back to normal settings for the next map.
    lines = game.run_batch(["sun clear", "look off", "set sun_shadows 0"], run.timeout)
    for l in errors_in(lines):
        say("  (end of map) " + l)

    ok_suns = [s for s in suns if s["ok"]]
    if not ok_suns:
        write_map_skip(run, mid, name, "no sun scored")
        shutil.rmtree(folder, ignore_errors=True)
        clean_leftovers(run)
        return "skipped"

    for s in ok_suns:
        s["score"] = sum(s["fracs"].values()) / len(s["fracs"])
        s["dark"] = sum(s["darks"].values()) / len(s["darks"])
    ranked = sorted(ok_suns, key=lambda s: s["score"])
    best = pick_distinct(ranked)

    best_rows = []
    for rank, s in enumerate(best, 1):
        best_rows.append([key, name, str(rank), fmt(s["az"]), fmt(s["el"]),
                          "%.5f" % s["score"], "%.5f" % s["dark"]])
        for view, path in s["shots"].items():
            move_file(path, os.path.join(folder, os.path.basename(path)))
    append_rows(run.best, BEST_HEADER, best_rows)

    for view, path in base_paths.items():
        move_file(path, os.path.join(folder, os.path.basename(path)))

    # Contact sheet of the top views of the kept suns, A to D in rank order.
    if "top" in run.views:
        tiles = []
        for i, s in enumerate(best):
            caption = "%s  az %s  el %s  shadow %.1f%%" % ("ABCD"[i], fmt(s["az"]), fmt(s["el"]), s["score"] * 100)
            tiles.append((caption, os.path.join(folder, os.path.basename(s["shots"]["top"]))))
        try:
            write_sheet(os.path.join(folder, "sheet.png"), tiles)
        except (OSError, ValueError) as e:
            say("  could not write the contact sheet: %s" % e)

    status = "enclosed" if enclosed else "ok"
    if enclosed:
        mean_frac = sum(s["score"] for s in ok_suns) / len(ok_suns)
        mean_dark = sum(s["dark"] for s in ok_suns) / len(ok_suns)
        append_rows(run.results, RESULT_HEADER,
                    [[key, name, "enclosed", "", "", "all", "%.5f" % mean_frac, "%.5f" % mean_dark]])

    if status == "ok" and "top" in run.views:
        try:
            copy_choices(run, key, name, best, folder)
        except OSError as e:
            say("  could not copy the top shots to Choices: %s" % e)

    shutil.rmtree(stage, ignore_errors=True)
    clean_leftovers(run)
    b = best[0]
    say("map %s %s: %d suns scored, best az %s el %s (mean shadow %.4f)"
        % (key, name, len(ok_suns), fmt(b["az"]), fmt(b["el"]), b["score"]))
    return status


# ---------------------------------------------------------------- main

def main():
    try:
        sys.stdout.reconfigure(errors="replace")
    except AttributeError:
        pass

    ap = argparse.ArgumentParser(description="Search sun positions for the least shadow in each map.")
    ap.add_argument("--maps", required=True, help="comma-separated map ids in hex, or 'all'")
    ap.add_argument("--azimuths", default=DEFAULT_AZIMUTHS, help="sun azimuths in degrees")
    ap.add_argument("--elevations", default=DEFAULT_ELEVATIONS, help="sun elevations in degrees")
    ap.add_argument("--views", default=DEFAULT_VIEWS, help="which views: top, g0, g120, g240")
    ap.add_argument("--out", required=True, help="output folder")
    ap.add_argument("--exe-dir", default=DEFAULT_EXE_DIR, help="folder with BanjoReTooie.exe")
    ap.add_argument("--timeout", type=float, default=60.0, help="seconds per sync (default 60)")
    ap.add_argument("--resume", action="store_true", help="skip maps that already finished")
    ap.add_argument("--choices", default=DEFAULT_CHOICES,
                    help="folder for the top shots of each ok map's kept suns (default <repo>\\Choices)")
    args = ap.parse_args()

    names = load_map_names(MAP_NAMES)
    maps = parse_maps(args.maps, names)
    views = parse_views(args.views)
    azs = parse_numbers(args.azimuths)
    els = parse_numbers(args.elevations)
    exe_dir = os.path.abspath(args.exe_dir)
    if not os.path.isfile(os.path.join(exe_dir, "BanjoReTooie.exe")):
        sys.exit("no BanjoReTooie.exe in %s" % exe_dir)

    run = Run(args, views, azs, els, exe_dir)
    os.makedirs(run.out, exist_ok=True)
    append_rows(run.results, RESULT_HEADER, [])
    append_rows(run.best, BEST_HEADER, [])
    done = load_done(run.results, run.best)

    say("%d maps, views %s, %d azimuths x %d elevations" % (len(maps), ",".join(views), len(azs), len(els)))
    backup_graphics(exe_dir)
    apply_shot_settings(exe_dir)
    try:
        for mid, name in maps:
            key = "%X" % mid
            if args.resume and key in done:
                say("skip %s %s: already done" % (key, name))
                continue
            drop_map_rows(run.results, RESULT_HEADER, key)
            drop_map_rows(run.best, BEST_HEADER, key)
            say("map %s %s" % (key, name))
            # A fresh game for every map: after a few maps a long-running game drew its frames so slowly that the
            # screenshots took over 20 s each (2026-11-10, from the second map on), while a fresh one is quick.
            run.game.start()
            try:
                run_map(run, mid, name)
            except GameLost as e:
                say("the game was lost on map %s: %s" % (key, e))
                run.game.stop(polite=False)
                shutil.rmtree(os.path.join(run.out, key), ignore_errors=True)
                write_map_skip(run, mid, name, "game lost: %s" % e)
                clean_leftovers(run)
                continue
            try:
                run.game.stop()
            except Exception as e:
                say("could not stop the game cleanly: %s" % e)
                run.game.stop(polite=False)
    except GameLost as e:
        say("the run stopped: %s" % e)
    except KeyboardInterrupt:
        say("stopped by Ctrl+C")
    finally:
        try:
            run.game.stop()
        except Exception as e:
            say("could not stop the game cleanly: %s" % e)
        restore_graphics(exe_dir)
        say("done. Results in %s" % run.results)


if __name__ == "__main__":
    main()
