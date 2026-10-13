# Patches to submodules

CMake applies these to the submodule checkouts when it configures the build,
so the submodules stay pinned to their upstream commits.

## N64ModernRuntime.patch

* **Thread queue** (`ultramodern/src/threadqueue.cpp`): `thread_queue_remove`
  never moved past the head of the queue, so removing any other thread looped
  forever. `thread_queue_insert` could insert a thread that was already queued,
  linking the list into a cycle. Banjo-Tooie hit both during boot.
* **RDP freeze bit** (`librecomp/src/dp.cpp`, `ultramodern/src/events.cpp`):
  Banjo-Tooie paces frames with `DPC_STATUS_FREEZE`. A real RDP does no work
  while frozen, so a display list submitted then cannot finish before the game
  unfreezes it. The host renders at once, so the runtime now holds the "RDP
  done" message until the freeze is cleared. Without this the game lost track
  of its frames and stopped on the first one.

To change a patch: edit the files in `lib/N64ModernRuntime`, then
`git -C lib/N64ModernRuntime diff > lib-patches/N64ModernRuntime.patch`.
