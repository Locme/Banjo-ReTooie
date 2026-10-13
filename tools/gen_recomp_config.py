#!/usr/bin/env python3
"""Prepare the recompiler's inputs from the decomp's ELF.

    python3 tools/gen_recomp_config.py [path/to/banjotooie_decompressed.elf]

Writes three things N64Recomp cannot work out by itself:

* overlays.us.txt: every overlay section in the game's overlay order (line N
  is overlay N+1, `*` for the empty ones), from the decomp's overlays.us.toml.
  Each overlay links at 0x80800000 and is moved by the game at load time, so
  its section is relocatable.
* banjotooie.us.elf: a copy of the decomp's ELF with symbol sizes filled in.
  Some hand-written assembly has a second entry point in the middle of a
  function (for example func_800138D0 inside func_800138BC). The decomp gives
  those labels a size of 0, so N64Recomp emits an empty function and a `jal`
  to one finds nothing. Each one is given the size that runs it to the end of
  the function containing it, so it becomes its own complete function.
* manual_funcs in banjotooie.us.toml, between the GENERATED markers, for every
  address in extra_entries.us.txt. Those are jump targets inside another
  function (hand-written float code shares function tails, for example
  `j .L80013B90` into func_80013B7C). Each becomes a function running to the
  end of the function containing it, so the jump is a tail call.
  tools/recomp_loop.py adds to that list.

Needs pyelftools (`pip install pyelftools`).
"""
import os
import re
import sys
from collections import defaultdict

from elftools.elf.elffile import ELFFile

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
OVERLAY_VRAM = 0x80800000
# Microcode boundary markers live in core1 data, not code.
MARKER = re.compile(r"(Text|Data)(Start|End)$")
BEGIN = "# BEGIN GENERATED manual_funcs (tools/gen_recomp_config.py)"
END = "# END GENERATED manual_funcs"


def read_extra_entries():
    """(section name, vram) pairs from extra_entries.us.txt."""
    path = os.path.join(ROOT, "extra_entries.us.txt")
    entries = []
    if os.path.exists(path):
        for line in open(path, encoding="utf-8"):
            line = line.split("#")[0].strip()
            if line:
                section, vram = line.split()
                entries.append((section, int(vram, 16)))
    return entries


def called_unsized(elf_path, sized):
    """Functions that are called but that N64Recomp would emit empty.

    A `jal` to an address with no sized function symbol makes N64Recomp create
    a static function that runs up to the next symbol of any kind. When a
    label already sits at that address (bsrest's first function starts on
    bsrest_TEXT_START, bsledge's func_80800324 has size 0) the function comes
    out empty, so the call does nothing: Banjo kept his walking speed while
    Jamjars talked, because bsrest's "stop moving" function was empty.
    Yields (section index, vram, size) for each, the size running to the next
    sized function or called address in the section, or the section's end.
    """
    with open(elf_path, "rb") as f:
        elf = ELFFile(f)
        labels = defaultdict(set)
        for sym in elf.get_section_by_name(".symtab").iter_symbols():
            shndx = sym["st_shndx"]
            if isinstance(shndx, int) and sym.name:
                labels[shndx].add(sym["st_value"])
        for shndx, section in enumerate(elf.iter_sections()):
            if section["sh_type"] != "SHT_PROGBITS" or not section["sh_flags"] & 4:
                continue  # not code
            data = section.data()
            base, end = section["sh_addr"], section["sh_addr"] + len(data)
            starts = set(start for start, _, _ in sized[shndx])
            called = set()
            for offset in range(0, len(data) - 3, 4):
                word = int.from_bytes(data[offset:offset + 4], "big")
                if word >> 26 == 3:  # jal
                    target = ((base + offset + 4) & 0xF0000000) | ((word & 0x3FFFFFF) << 2)
                    if base <= target < end and target not in starts:
                        called.add(target)
            for target in sorted(called):
                if target not in labels[shndx]:
                    continue  # N64Recomp sizes this one correctly
                if any(start < target < stop for start, stop, _ in sized[shndx]):
                    continue  # inside a function: a mid-function entry, handled above
                after = [start for start in starts if start > target]
                after += [other for other in called if other > target]
                yield shndx, target, min(after + [end]) - target


def main():
    elf_path = sys.argv[1] if len(sys.argv) > 1 else os.path.join(
        ROOT, "lib", "bt-decomp", "build", "us", "banjotooie_decompressed.elf")
    out_path = os.path.join(ROOT, "banjotooie.us.elf")
    patches = []  # (file offset of st_size, new size)
    with open(elf_path, "rb") as f:
        elf = ELFFile(f)
        sections = [s for s in elf.iter_sections()]
        overlays = [s.name for s in sections
                    if s["sh_type"] == "SHT_PROGBITS" and s["sh_addr"] == OVERLAY_VRAM
                    and not s.name.endswith("_header")]

        sized = defaultdict(list)    # section index -> [(start, end, name)]
        zero = []                    # (section index, addr, name, st_size offset)
        symtab = elf.get_section_by_name(".symtab")
        for i, sym in enumerate(symtab.iter_symbols()):
            if sym["st_info"]["type"] != "STT_FUNC":
                continue
            shndx = sym["st_shndx"]
            if not isinstance(shndx, int):
                continue
            addr, size, name = sym["st_value"], sym["st_size"], sym.name
            if size:
                sized[shndx].append((addr, addr + size, name))
            elif not name.startswith(".L") and not MARKER.search(name):
                zero.append((shndx, addr, name,
                             symtab["sh_offset"] + i * symtab["sh_entsize"] + 8))

    # The game numbers overlays from 1 in overlays.us.toml order.
    order = []
    decomp_root = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(elf_path))))
    toml_path = os.path.join(decomp_root, "overlays.us.toml")
    for block in open(toml_path, encoding="utf-8").read().split("[[overlay]]")[1:]:
        m = re.search(r'^name\s*=\s*"([^"]+)"', block, re.M)
        order.append("." + m.group(1) if m and "empty = true" not in block else "*")
    missing = set(n for n in order if n != "*") - set(overlays)
    if missing:
        raise SystemExit("overlays in overlays.us.toml with no ELF section: %s" % sorted(missing)[:5])
    with open(os.path.join(ROOT, "overlays.us.txt"), "w") as f:
        f.write("\n".join(order) + "\n")

    split = []
    unplaced = []
    for shndx, addr, name, size_offset in sorted(zero):
        funcs = sized[shndx]
        if any(start == addr for start, _, _ in funcs):
            continue  # an alias of a sized function, which N64Recomp already has
        container = [(s, e, n) for s, e, n in funcs if s < addr < e]
        if not container:
            unplaced.append((name, addr))
            continue
        _, end, _ = container[0]
        split.append(name)
        patches.append((size_offset, end - addr))

    by_name = {sections[i].name: i for i in range(len(sections))}
    manual = []
    for shndx, vram, size in called_unsized(elf_path, sized):
        section = sections[shndx].name
        manual.append(("func_%08X_%s" % (vram, section.lstrip(".")), section, vram, size))
    for section, vram in read_extra_entries():
        container = [(st, e, n) for st, e, n in sized[by_name[section]] if st < vram < e]
        if not container:
            raise SystemExit("extra entry %s 0x%08X is not inside a function" % (section, vram))
        manual.append(("func_%08X%s" % (vram, "" if section in (".core1", ".core2", ".boot")
                                        else "_" + section.lstrip(".")),
                       section, vram, container[0][1] - vram))

    lines = [BEGIN, "manual_funcs = ["]
    for name, section, vram, size in manual:
        lines.append('    { name = "%s", section = "%s", vram = 0x%08X, size = 0x%X },'
                     % (name, section, vram, size))
    lines += ["]", END]
    toml_path = os.path.join(ROOT, "banjotooie.us.toml")
    text = open(toml_path, encoding="utf-8").read()
    start, stop = text.index(BEGIN), text.index(END) + len(END)
    open(toml_path, "w", encoding="utf-8").write(text[:start] + "\n".join(lines) + text[stop:])

    data = bytearray(open(elf_path, "rb").read())
    for offset, size in patches:
        data[offset:offset + 4] = size.to_bytes(4, "big")
    with open(out_path, "wb") as f:
        f.write(data)

    print("%d overlay sections, %d mid-function entry points given sizes, %d extra entries"
          % (len(overlays), len(split), len(manual)))
    for name, addr in unplaced:
        print("  not placed (no containing function): %s 0x%08X" % (name, addr))


if __name__ == "__main__":
    main()
