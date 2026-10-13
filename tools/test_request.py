#!/usr/bin/env python3
"""Record a bug test request for L before any fix is attempted (L's rule, 2026-10-13:
"When it comes to bugs, make the new project ask me to test the issues there before
trying to apply a fix").

Appends a numbered, consistently shaped entry to the "for L to test" list and prints
a short message to post in the thread. Keeping one shape means L can answer quickly
and later threads can grep the file instead of re-reading conversations.

Usage:
  test_request.py --file notes/for-L-to-test.md --title "Beak Barge sound cuts out" \
      --steps "Load Witchyworld|Enter Big Top|Do the Beak Barge pad" \
      --look "Does the barge sound play to the end?" \
      --build "main @ abc1234" [--xbla "4.66"]

  test_request.py --file notes/for-L-to-test.md --answer 7 --result "still broken, video attached"
"""
import argparse
import datetime
import re
import sys


def next_id(text):
    ids = [int(m) for m in re.findall(r"^## T(\d+)\b", text, re.M)]
    return max(ids, default=0) + 1


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--file", required=True)
    ap.add_argument("--title")
    ap.add_argument("--steps", help="steps separated by |")
    ap.add_argument("--look", help="what L should check")
    ap.add_argument("--build", help="branch/commit or release L should run")
    ap.add_argument("--xbla", help="report section of the matching XBLA bug, if any")
    ap.add_argument("--answer", type=int, help="record L's result for test T<n>")
    ap.add_argument("--result")
    a = ap.parse_args()

    try:
        text = open(a.file, encoding="utf-8").read()
    except FileNotFoundError:
        text = ("# For L to test\n\nBug test requests. Rule: no fix is attempted until L "
                "has tested the issue on the N64 build and answered here.\n")
    now = datetime.datetime.now(datetime.timezone.utc).strftime("%Y-%m-%d %H:%M UTC")

    if a.answer:
        pat = re.compile(rf"(^## T{a.answer}\b.*?)(?=^## T|\Z)", re.M | re.S)
        m = pat.search(text)
        if not m:
            print(f"no T{a.answer}", file=sys.stderr)
            return 1
        block = m.group(1).replace("- Status: waiting for L", f"- Status: answered {now}")
        block = block.rstrip() + f"\n- L's result: {a.result}\n\n"
        text = text[:m.start()] + block + text[m.end():]
        open(a.file, "w", encoding="utf-8").write(text)
        print(f"T{a.answer} updated")
        return 0

    if not (a.title and a.steps and a.look and a.build):
        ap.error("--title, --steps, --look and --build are required for a new request")
    n = next_id(text)
    steps = "\n".join(f"  {i}. {s.strip()}" for i, s in enumerate(a.steps.split("|"), 1))
    entry = (f"\n## T{n} {a.title}\n- Asked: {now}\n- Build: {a.build}\n"
             + (f"- XBLA history: report §{a.xbla}\n" if a.xbla else "")
             + f"- Steps:\n{steps}\n- Look for: {a.look}\n- Status: waiting for L\n")
    open(a.file, "a" if text.endswith("\n") else "w", encoding="utf-8").write(
        entry if text.endswith("\n") else text + "\n" + entry)
    print(f"Could you test this on {a.build}? {a.title}.\n{steps}\nWhat I need to know: {a.look}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
