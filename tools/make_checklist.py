#!/usr/bin/env python3
"""Generate the roadmap checklist (two boxes per item) from the handoff report.

Reads every "### 4.N Title" heading in Section 4 and the Section 8 mapping table
(rows like "| 4.55 | Short | ... |") and writes a checklist grouped by tier.
Each item gets "Done" (Claude ticks when it is on main) and "Approved by L"
(only L ticks). Existing ticks and notes are kept when --merge points at the
current checklist, so re-running it never loses L's approvals.

Usage:
  make_checklist.py REPORT.md --out notes/roadmap-checklist.md [--merge notes/roadmap-checklist.md]
"""
import argparse
import re
import sys

FEAT = re.compile(r"^###\s+(4\.\d+)\s+(.*)$")
ROW = re.compile(r"^\|\s*(4\.\d+)\s*\|\s*([^|]+?)\s*\|")
TIERS = ["Short", "Mid", "Long", "Stretch", "Free", "Dropped"]


def read_existing(path):
    """Map item number -> list of lines under its heading (boxes and notes)."""
    keep = {}
    cur = None
    try:
        for line in open(path, encoding="utf-8"):
            m = re.match(r"^###\s+(4\.\d+)\b", line)
            if m:
                cur = m.group(1)
                keep[cur] = []
            elif line.startswith("#"):
                cur = None
            elif cur:
                keep[cur].append(line.rstrip("\n"))
    except FileNotFoundError:
        pass
    return keep


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("report")
    ap.add_argument("--out", required=True)
    ap.add_argument("--merge")
    a = ap.parse_args()

    feats, tiers = {}, {}
    for line in open(a.report, encoding="utf-8"):
        m = FEAT.match(line)
        if m and m.group(1) != "4.0":
            feats[m.group(1)] = m.group(2).strip()
        m = ROW.match(line)
        if m:
            tiers[m.group(1)] = m.group(2).split()[0].strip("*")
    old = read_existing(a.merge) if a.merge else {}

    out = ["# Banjo-Tooie N64 recomp: roadmap checklist", "",
           "Every item has two boxes:", "",
           "- **Done**: Claude ticks this only when the work has landed on `main`. Partial work stays unticked, with a note.",
           "- **Approved by L**: only L ticks this, and only when happy. Claude ticks it only when L says to.", "",
           "Numbers are the feature numbers in the handoff report, Section 4.", ""]
    order = TIERS + sorted({t for t in tiers.values()} - set(TIERS)) + ["Unmapped"]
    for tier in order:
        items = [n for n in feats if tiers.get(n, "Unmapped") == tier]
        if not items:
            continue
        out += [f"## {tier}", ""]
        for n in sorted(items, key=lambda s: int(s.split(".")[1])):
            out.append(f"### {n} {feats[n]}")
            body = old.get(n)
            if body and any("[" in l for l in body):
                out += [l for l in body if l.strip()]
            else:
                out += ["- [ ] Done", "- [ ] Approved by L"]
            out.append("")
    open(a.out, "w", encoding="utf-8").write("\n".join(out))
    missing = [n for n in feats if n not in tiers]
    print(f"{len(feats)} items -> {a.out}" + (f"; not in the Section 8 table: {', '.join(missing)}" if missing else ""))
    return 0


if __name__ == "__main__":
    sys.exit(main())
