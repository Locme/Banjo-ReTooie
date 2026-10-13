#!/usr/bin/env python3
"""Print one section of the handoff report instead of reading the whole file.

Saves tokens: the report is long, and most tasks need one feature (for example
"4.55 Twin-stick camera") plus the general rules in 4.0.

Usage:
  report_section.py REPORT.md --list              # every heading with its number
  report_section.py REPORT.md 4.55                # one numbered section
  report_section.py REPORT.md 4.55 --with-rules   # the section plus 4.0 (translation rules)
  report_section.py REPORT.md --grep "draw distance"   # sections whose text matches
"""
import argparse
import re
import sys

HEAD = re.compile(r"^(#{2,4})\s+(\d+(?:\.\d+)*)?\.?\s*(.*)$")


def split_sections(text):
    """Return a list of (level, number, title, body) for every ##..#### heading."""
    out = []
    cur = None
    for line in text.splitlines(keepends=True):
        m = HEAD.match(line)
        if m and not line.startswith("#####"):
            if cur:
                out.append(cur)
            cur = [len(m.group(1)), m.group(2) or "", m.group(3).strip(), line]
        elif cur:
            cur[3] += line
    if cur:
        out.append(cur)
    return out


def section_with_children(secs, number):
    """The heading `number` and every deeper heading under it."""
    res = []
    level = None
    for lvl, num, title, body in secs:
        if level is None:
            if num == number:
                level = lvl
                res.append(body)
        elif lvl > level:
            res.append(body)
        else:
            break
    return "".join(res)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("report")
    ap.add_argument("number", nargs="?")
    ap.add_argument("--list", action="store_true")
    ap.add_argument("--with-rules", action="store_true")
    ap.add_argument("--grep")
    a = ap.parse_args()

    secs = split_sections(open(a.report, encoding="utf-8").read())
    if a.list:
        for lvl, num, title, _ in secs:
            print("  " * (lvl - 2) + (num + " " if num else "") + title)
        return 0
    if a.grep:
        pat = re.compile(a.grep, re.I)
        for lvl, num, title, body in secs:
            if num and pat.search(body):
                print(f"{num} {title}")
        return 0
    if not a.number:
        ap.error("give a section number, --list or --grep")
    text = section_with_children(secs, a.number)
    if not text:
        print(f"no section {a.number}", file=sys.stderr)
        return 1
    if a.with_rules and a.number != "4.0":
        text = section_with_children(secs, "4.0") + "\n" + text
    sys.stdout.write(text)
    return 0


if __name__ == "__main__":
    sys.exit(main())
