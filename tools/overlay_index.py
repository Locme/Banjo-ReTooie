#!/usr/bin/env python3
"""Index the Banjo-Tooie decomp's overlays and symbols so you can look things up
without reading the 16k-line splat yaml or the multi-MB symbol files.

Inputs come from the Mr-Wiseguy/banjo-tooie decomp checkout:
  - the splat yaml (banjotooie.us.yaml or similar; NEEDS VERIFICATION of the name)
  - overlays.us.toml (overlay order, "# Overlay N" comments, entrypoint lists)
  - symbol files: symbol_addrs.us.txt, ovl_symbol_addrs.us.txt, syscall_symbol_addrs.us.txt

Usage:
  overlay_index.py build --yaml Y --toml T [--syms F ...] --out index.json
  overlay_index.py find index.json NAME_OR_ADDR     # overlay name, ROM addr, or symbol
  overlay_index.py list index.json [--grep ch]      # overlays, optionally filtered

Notes that cost the previous port time (see report §2/§3):
  - every overlay runs at vram 0x80800000, so a 0x808xxxxx address alone is ambiguous;
    the ROM address or the overlay name is the real identity.
  - the overlays.us.toml order is NOT the runtime order librecomp uses (it sorts by
    ROM address) and NOT the syscall code order. Use the "rom" field to join.
"""
import argparse
import json
import re
import sys

SEG_NAME = re.compile(r"^\s*-\s*name:\s*(\S+)")
KV = re.compile(r"^\s*(start|vram|type|dir|bss_size):\s*(\S+)")
SYM = re.compile(r"^\s*(\w+)\s*=\s*(0x[0-9A-Fa-f]+)\s*;(.*)$")


def parse_yaml_segments(path):
    segs = []
    cur = None
    for line in open(path, encoding="utf-8"):
        if line.startswith("    subsegments") or line.startswith("      -"):
            continue
        m = SEG_NAME.match(line)
        if m and line.startswith("  - name"):
            cur = {"name": m.group(1)}
            segs.append(cur)
            continue
        m = KV.match(line)
        if m and cur is not None and line.startswith("    ") and not line.startswith("     "):
            cur[m.group(1)] = m.group(2)
    for i, s in enumerate(segs):
        if "start" in s:
            s["start_int"] = int(s["start"], 16) if s["start"].startswith("0x") else int(s["start"])
    starts = [s for s in segs if "start_int" in s]
    for a, b in zip(starts, starts[1:]):
        a["end_int"] = b["start_int"]
    return segs


def parse_toml_order(path):
    order = []
    cur = None
    for line in open(path, encoding="utf-8"):
        m = re.match(r"^\[\[overlay\]\]\s*#\s*Overlay\s+(\d+)", line)
        if m:
            cur = {"toml_index": int(m.group(1)), "name": None, "entrypoints": 0}
            order.append(cur)
            continue
        if cur is None:
            continue
        m = re.match(r'^name\s*=\s*"([^"]+)"', line)
        if m:
            cur["name"] = m.group(1)
        elif re.match(r'^\s*"[^"]*_entrypoint_\d+"', line):
            cur["entrypoints"] += 1
    return order


def parse_syms(paths):
    syms = []
    for p in paths:
        for line in open(p, encoding="utf-8", errors="replace"):
            m = SYM.match(line)
            if m:
                syms.append({"name": m.group(1), "addr": m.group(2).lower(),
                             "note": m.group(3).strip(), "file": p.split("/")[-1]})
    return syms


def build(a):
    segs = parse_yaml_segments(a.yaml)
    order = {o["name"]: o for o in parse_toml_order(a.toml) if o["name"]}
    overlays = []
    for s in segs:
        if s.get("vram", "").lower() == "0x80800000" and s.get("type") == "code":
            o = order.get(s["name"], {})
            overlays.append({
                "name": s["name"],
                "rom": "0x%08X" % s["start_int"],
                "rom_end": "0x%08X" % s.get("end_int", 0),
                "toml_index": o.get("toml_index"),
                "entrypoints": o.get("entrypoints"),
            })
    cores = [{"name": s["name"], "rom": s.get("start"), "vram": s.get("vram")}
             for s in segs if s.get("vram") and s.get("vram").lower() != "0x80800000"
             and s.get("type") == "code"]
    idx = {"overlays": overlays, "cores": cores, "symbols": parse_syms(a.syms or [])}
    json.dump(idx, open(a.out, "w"), indent=1)
    print(f"{len(overlays)} overlays, {len(cores)} core segments, {len(idx['symbols'])} symbols -> {a.out}")


def find(a):
    idx = json.load(open(a.index))
    q = a.query
    hits = 0
    if re.fullmatch(r"(0x)?[0-9A-Fa-f]{6,8}", q):
        v = int(q, 16)
        for o in idx["overlays"]:
            if int(o["rom"], 16) <= v < int(o["rom_end"], 16):
                print(f"overlay {o['name']}: rom {o['rom']}..{o['rom_end']}, offset 0x{v - int(o['rom'], 16):X}")
                hits += 1
        for s in idx["symbols"]:
            if int(s["addr"], 16) == v:
                print(f"symbol {s['name']} = {s['addr']} ({s['file']}) {s['note']}")
                hits += 1
    else:
        pat = re.compile(q, re.I)
        for o in idx["overlays"]:
            if pat.search(o["name"]):
                print(f"overlay {o['name']}: rom {o['rom']}, toml #{o['toml_index']}, {o['entrypoints']} entrypoints")
                hits += 1
        for s in idx["symbols"]:
            if pat.search(s["name"]):
                print(f"symbol {s['name']} = {s['addr']} ({s['file']}) {s['note']}")
                hits += 1
                if hits > 200:
                    print("... (more; narrow the pattern)")
                    break
    return 0 if hits else 1


def list_(a):
    idx = json.load(open(a.index))
    for o in idx["overlays"]:
        if not a.grep or re.search(a.grep, o["name"], re.I):
            print(f"{o['rom']}  #{o['toml_index']}  {o['name']}")


def main():
    ap = argparse.ArgumentParser()
    sp = ap.add_subparsers(dest="cmd", required=True)
    b = sp.add_parser("build")
    b.add_argument("--yaml", required=True)
    b.add_argument("--toml", required=True)
    b.add_argument("--syms", nargs="*")
    b.add_argument("--out", required=True)
    f = sp.add_parser("find")
    f.add_argument("index")
    f.add_argument("query")
    l = sp.add_parser("list")
    l.add_argument("index")
    l.add_argument("--grep")
    a = ap.parse_args()
    return {"build": build, "find": find, "list": list_}[a.cmd](a) or 0


if __name__ == "__main__":
    sys.exit(main())
