# The Banjo-Tooie decomp we have

What is in the `decomp/` folder, written down on 2026-11-19 so the game's functions can be rewritten as our own
code later. `decomp/` is not committed (see Licence) and not ignored either, so leave it out of `git add`.

## What is there

All three are copies of https://github.com/Mr-Wiseguy/banjo-tooie, the community decomp (Mr-Wiseguy, Dominik
Peters, Zenpock and others). The two pull requests are git worktrees of `decomp/banjo-tooie`, so they share
its objects.

| Folder | What | Commit |
|---|---|---|
| `decomp/banjo-tooie` | master | 4c0525a, 2026-11-07, "Matched various functions and files amounting to about 16-17% of the codebase (#58)" |
| `decomp/pr-59-core2-matches` | open pull request #59 by Fake-Guthix, "Core2 matches" | dd6cb6a, 2026-11-11 |
| `decomp/pr-18-decomper` | open pull request #18 by Bl00D4NGEL, "Add decomper.py" | 89733fc, 2025-07-01 |

- **#59** matches the rest of five core2 files (1E79FD0.c 33/33, 1E80A70.c 62/64, 1EAD6C0.c 15/15, 1EC2350.c
  31/32, 1EDD9C0.c 7/7) and adds prototypes it found: 77 files, +1607 -237. It merged cleanly with master on
  2026-11-19.
- **#18** adds `tools/decomper.py`, which runs the m2c decompiler over a file to give a first draft of its C. It
  does not match any functions and conflicts with master.

`lib/bt-decomp` (the submodule) is still at 25033be from 2025-11-29, 237 commits behind master. Our code reads
it only for names and struct layouts; nothing builds it.

## How much is C

Functions written as C against those still left as assembly (`INCLUDE_ASM`), in `src/`. The C counts come from
counting function headers, so they are close but not exact.

| Part | .c files | C (master) | Assembly (master) | C with #59 | Assembly with #59 |
|---|---|---|---|---|---|
| boot | 3 | 8 | 0 | 8 | 0 |
| core1 | 56 | 179 | 314 | 179 | 314 |
| core2 | 197 | 1,290 | 2,270 | 1,376 | 2,186 |
| overlays | 851 | 1,613 | 6,744 | 1,613 | 6,744 |
| **All** | 1,107 | **3,090** | **9,328** | **3,176** | **9,244** |

So about a quarter of the functions are C (master's own figure, by code size, is 16-17%). The overlay files
are grouped by name prefix: ch (456 files, the objects and characters, as in chhoney), bs (105, as in
bsbbarge), su (58), ba (57), gc (32, as in gc/newpause.c, the pause menu), nc (29), gl (25), id (17), fx (17),
db (11), gs (8), vp (6) and a few smaller ones.

For comparison, `RecompiledFuncs/` holds 20,857 functions. The recompiler and the decomp split the ROM
differently, so the two totals do not line up one for one.

## Licence

The decomp repo has no licence file, which leaves all rights with its authors. So its code is not copied into
this repo, and a rewrite has to be our own code written from what the functions do, not their C pasted in.
Reading it for names, flags and struct layouts, as the code already does, is fine. If the authors add a
licence, check it and add it to `docs/THIRD_PARTY.md` before taking anything over.

## Updating it

```
cd decomp/banjo-tooie
git pull
git fetch origin pull/59/head:pr-59-core2-matches pull/18/head:pr-18-decomper --force
```

The worktrees then need `git checkout -f <branch>` inside them, or `git worktree remove` and `add` again. The
decomp's assembly only exists after its `make setup`, which needs a ROM as `baserom.us.z64`; that has not been
run, so there is no ROM data in the folder.
