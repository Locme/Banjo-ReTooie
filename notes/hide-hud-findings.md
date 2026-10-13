# 4.84 Hide HUD: findings so far

Starting notes for whoever picks this up (the main thread). Nothing is hooked yet.

- The decomp (`lib/bt-decomp`) names almost none of the HUD or text-box draw
  functions, so the entry points have to be found by profiling the running game:
  warp to Spiral Mountain (`TOOIE_WARP=AF:0@15000`), then look at which recompiled
  functions emit the HUD display-list commands each frame.
- Hooking them needs `[[patches.hook]]` entries (or `ignored` plus a host version)
  and a regeneration with `tools/recomp_loop.py`, which needs the decomp's ELF.
  That ELF is not available in the Sonnet thread's container.
- Host-only alternatives were checked and do not work: RT64 has no 2D/ortho skip
  and `RendererContext` only sees whole display lists, so the HUD can't be split
  from the 3D scene there.
- A toast helper exists for the "HUD hidden" / "HUD shown" notices:
  `tooie::toast::show(const std::string&)` in `include/tooie_toast.h`.
- For a quick RDRAM look in a headless run, `TOOIE_WATCH=addr+len` prints words every 2 s.
