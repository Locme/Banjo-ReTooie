#!/usr/bin/env python3
"""Check a user-supplied Banjo-Tooie ROM and convert it to big-endian .z64.

Never downloads anything and never prints ROM bytes beyond the header fields.

Usage:
  rom_check.py ROM                 # identify byte order, size, name, ID, hashes
  rom_check.py ROM --out baserom.us.z64   # also write a .z64 (big-endian) copy

Expected NTSC-U 1.0 dump (from the decomp and the existing BT recomps):
  .z64 SHA-1   af1a89e12b638b8d82cc4c085c8e01d4cba03fb3
  .z64 SHA-256 9ec37fba6890362eba86fb855697a9cff1519275531b172083a1a6a045483583
  size 33,554,432 bytes, internal name "BANJO TOOIE", cartridge ID "NB7E"
"""
import argparse
import hashlib
import sys

SHA1 = "af1a89e12b638b8d82cc4c085c8e01d4cba03fb3"
SHA256 = "9ec37fba6890362eba86fb855697a9cff1519275531b172083a1a6a045483583"
SIZE = 32 * 1024 * 1024

MAGIC = {
    bytes.fromhex("80371240"): "z64",  # big-endian, what N64Recomp wants
    bytes.fromhex("37804012"): "v64",  # byte-swapped (16-bit)
    bytes.fromhex("40123780"): "n64",  # little-endian (32-bit)
}


def to_z64(data, kind):
    b = bytearray(data)
    if kind == "v64":
        b[0::2], b[1::2] = data[1::2], data[0::2]
    elif kind == "n64":
        b[0::4], b[1::4], b[2::4], b[3::4] = data[3::4], data[2::4], data[1::4], data[0::4]
    return bytes(b)


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("rom")
    ap.add_argument("--out")
    a = ap.parse_args()

    data = open(a.rom, "rb").read()
    kind = MAGIC.get(data[:4])
    if kind is None:
        print(f"unknown header {data[:4].hex()}: not an N64 ROM, or already compressed/patched")
        return 2
    z = to_z64(data, kind)
    name = z[0x20:0x34].decode("ascii", "replace").rstrip(" \0")
    cart = z[0x3B:0x3F].decode("ascii", "replace")
    s1 = hashlib.sha1(z).hexdigest()
    s256 = hashlib.sha256(z).hexdigest()
    print(f"byte order : {kind}" + ("" if kind == "z64" else " (will convert to z64)"))
    print(f"size       : {len(z)} bytes" + ("" if len(z) == SIZE else f"  (expected {SIZE})"))
    print(f"name / id  : {name!r} / {cart!r}")
    print(f"sha1 (z64) : {s1}  {'OK' if s1 == SHA1 else 'MISMATCH'}")
    print(f"sha256(z64): {s256}  {'OK' if s256 == SHA256 else 'MISMATCH'}")
    if s1 != SHA1:
        print("This is not the NTSC-U 1.0 dump the decomp and configs expect. "
              "PAL/JP need their own symbol maps; a patched or hacked ROM will not work.")
    if a.out:
        open(a.out, "wb").write(z)
        print(f"wrote {a.out}")
    return 0 if s1 == SHA1 else 1


if __name__ == "__main__":
    sys.exit(main())
