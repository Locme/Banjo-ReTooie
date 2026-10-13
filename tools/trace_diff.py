#!/usr/bin/env python3
"""Compare call counts between windows of a TOOIE_TRACE file.

    tools/trace_diff.py calls.txt A_FROM-A_TO B_FROM-B_TO [--top N]

Windows are numbered as in the file (2 s each). Prints functions called in the
B windows but never in the A windows, then those whose call rate changed the
most. Typical use: A = HUD hidden, B = HUD shown, to find the HUD's draw code.
"""
import sys
from collections import Counter


def read(path):
    windows, cur = {}, None
    for line in open(path):
        if line.startswith("== window"):
            cur = int(line.split()[2])
            windows[cur] = Counter()
        elif cur is not None and line.strip():
            n, name = line.split(None, 1)
            windows[cur][name.strip()] += int(n)
    return windows


def rate(windows, span):
    lo, hi = (int(x) for x in span.split("-"))
    total, count = Counter(), 0
    for w in range(lo, hi + 1):
        if w in windows:
            total.update(windows[w])
            count += 1
    return {k: v / max(count, 1) for k, v in total.items()}


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    top = int(sys.argv[sys.argv.index("--top") + 1]) if "--top" in sys.argv else 40
    if len(args) < 3:
        print(__doc__)
        return 1
    windows = read(args[0])
    a, b = rate(windows, args[1]), rate(windows, args[2])
    only_b = sorted((v, k) for k, v in b.items() if k not in a)
    print("Only in B (calls per window):")
    for v, k in reversed(only_b[-top:]):
        print("  %10.1f  %s" % (v, k))
    print("Largest change (B - A per window):")
    changed = sorted(((b.get(k, 0) - a.get(k, 0)), k) for k in set(a) | set(b) if k in a and k in b)
    for d, k in reversed(changed[-top:]):
        print("  %+10.1f  %s" % (d, k))
    return 0


if __name__ == "__main__":
    sys.exit(main())
