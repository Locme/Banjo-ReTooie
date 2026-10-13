#!/usr/bin/env python3
"""Run N64Recomp until it succeeds, fixing the failures that have a known fix.

    python3 tools/recomp_loop.py [path/to/banjotooie_decompressed.elf]

N64Recomp stops at the first function it cannot translate. This loop handles
one failure kind automatically and stops on anything else, printing it:

* "Unhandled branch in F at X to T": a jump into the middle of another
  function. T is added to extra_entries.us.txt, which makes it a function of
  its own (see tools/gen_recomp_config.py), so the jump becomes a tail call.
"""
import os
import re
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
GEN = os.path.join(ROOT, "tools", "gen_recomp_config.py")
RECOMP = os.path.join(ROOT, "N64Recomp.exe" if os.name == "nt" else "N64Recomp")
UNHANDLED = re.compile(r"Unhandled branch in (\S+) at 0x([0-9A-Fa-f]+) to 0x([0-9A-Fa-f]+)")


def section_of(vram, func_name):
    """The ELF section holding an address, from the generator's naming rule."""
    if vram >= 0x80800000:
        return "." + func_name.rsplit("_", 1)[1] if "_" in func_name[5:] else None
    if vram < 0x80012030:
        return ".boot"
    return ".core1" if vram < 0x800815C0 else ".core2"


def main():
    elf_args = sys.argv[1:2]
    for attempt in range(500):
        subprocess.run([sys.executable, GEN, *elf_args], check=True, cwd=ROOT,
                       stdout=subprocess.DEVNULL)
        p = subprocess.run([RECOMP, "banjotooie.us.toml"], cwd=ROOT,
                           capture_output=True, text=True, errors="replace")
        if p.returncode == 0:
            print("N64Recomp succeeded after %d fixes" % attempt)
            return 0
        out = p.stdout + p.stderr
        m = UNHANDLED.search(out)
        if not m:
            print(out[-3000:])
            print("stopped: not a failure this loop knows how to fix")
            return 1
        func, target = m.group(1), int(m.group(3), 16)
        section = section_of(target, func)
        if section is None:
            print(out[-3000:])
            print("stopped: cannot tell which section %s is in" % func)
            return 1
        with open(os.path.join(ROOT, "extra_entries.us.txt"), "a") as f:
            f.write("%s 0x%08X  # from %s\n" % (section, target, func))
        print("added %s 0x%08X (jumped to from %s)" % (section, target, func))
    print("gave up after 500 fixes")
    return 1


if __name__ == "__main__":
    sys.exit(main())
