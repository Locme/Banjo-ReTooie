# Handover: enhancements and speed-ups for the RT64 fork

The companion to `notes/rt64-fork-handover.md` (the fork itself, its layout, the extension points and the plugin
system). This one lists what to build into the fork once it exists, chosen by L (2026-11-07: "I like all of
these"). Where a number is given it comes from Banjo Re-Tooie's performance sweep of 2026-11-07
(`tools/perf_sweep.py`, `tools/perf_report.py`, the console's `bench` and `hostprof`), on L's PC (RTX 5080, a recent
16-thread CPU, Vulkan) unless it says otherwise.

The same ground rules apply as in the first handover: L's own fork, no AI-written pull requests upstream, every
change checked in every game that uses it, nothing from a ROM in the repo.

## Where a frame goes today (the case for the speed-ups)

Terrydactyland with the Enhanced preset, about 3.7 ms a frame:

- The game's own code: 0.3-0.7 ms (recompiled MIPS; not the renderer's).
- RT64's Gfx thread (display lists, RSP and RDP emulation): the top functions were `TMEMHasher::hash`,
  `RDP::loadBlockOperation`, `RSP::drawIndexedTri`, `RSP::setVertexCommon` and XXH3.
- RT64's workload thread: 1.4 ms preparing draws, 0.4 ms recording, 1.0 ms waiting for the GPU (whose own time was
  0.9 ms): `renderer_*_ms` columns of the benchmark csv.
- Thread handoffs: the frame passes game thread -> Gfx thread -> workload thread -> GPU in turn; even weighted by
  CPU use, wake-ups and waits were the biggest share of the profile.

On this PC that holds frame rates around 250-450 fps, so at 60 fps none of it shows. On phones and weak PCs the
same work decides whether 60 holds at all, so build for those.

## Order to build in

1. Display-list capture and replay (item 7): it makes every other change safe to test.
2. CPU/GPU overlap and the static-world cache (items 1 and 2): where the measured time goes.
3. The automation and stats API (item 8), so each game measures the same way.
4. The rest by need: phones (13, 11, 21, 25), the remaining speed-ups, picture and output.

## Speed

### 1. Overlap the CPU and the GPU

`WorkloadQueue::threadRenderFrame` records a game frame, submits it and waits (`execute(); wait();`) before the
next, so the CPU and GPU never work at once: about 1 ms a frame waited in Terrydactyland, more on slow GPUs. Let
one frame be in flight: two sets of every per-frame resource (command lists, upload buffers, the framebuffer
renderer's scratch, query pools), a fence per set, and waits only where the CPU really needs the GPU's result (a
read-back to RDRAM the game will read). Measure before and after with the same map list, twice each.

### 2. Cache the static world

Most of a level is the same display list every frame, read and turned into draws again each time. Recognise a
display list (or a run of it) by its RDRAM range and a hash of its bytes and of the memory it reads (vertices,
matrices, textures), and reuse what was built for it last time: the draw calls, transformed vertices and tile
setup. Only what changed (Banjo, enemies, effects, anything the CPU writes) is worked out again. Invalidate on any
write to the ranges (RT64 already tracks RDRAM writes for framebuffers). The biggest CPU win found: display-list
work was the Gfx thread's main load, and drawing more of a level (sun shadows' old culling) made it 8 times as
much.

### 3. Cache texture hashes

A texture load hashes its TMEM every frame (`TMEMHasher::hash` called from `rdp_tmem.cpp` and the texture cache).
Keep the last hash per (source address, size, format, palette) and skip hashing when that memory has not been
written since. The TLUT bitset fast path (2026-11-07) made the hash lambda about 5 times cheaper; skipping it is
better still.

### 4. Fewer thread handoffs

Count the synchronisation points per frame (game thread to Gfx thread, Gfx to workload, workload to present) and
remove what isn't needed: batch more work per handoff, spin briefly before sleeping where a wait is usually short,
and use lock-free queues where the profile shows SRW lock time (`RtlAcquireSRWLockExclusive` /
`RtlReleaseSRWLockExclusive` on the workload thread).

### 5. A pipeline cache on disk

Save the driver's pipeline cache (`VkPipelineCache`, D3D12's pipeline library) across runs, next to RT64's own
shader cache, so the specialised pipelines a player has met load instead of compiling. Most useful on phones,
where compiling is slowest.

### 6. Parallel draw setup

Spread per-framebuffer work over worker threads: draw setup and the CPU halves of effects (texture seams'
neighbour search, snow and sand, ground tessellation, effect setup) instead of one after another on the workload
thread. Texture seams alone was 21-41% of that thread's compute in the sweep before and after its hash grid.

### 14. Vertex transform on the GPU

RT64 transforms vertices and does lighting on the CPU (`RSP::setVertexCommon`, `drawIndexedTri` were among the Gfx
thread's top functions). Upload the untransformed vertices and matrices and do it in a compute or vertex shader,
keeping the CPU path for what reads the results back (culling, framebuffer sizing). Where the CPU path stays, use
SIMD (AVX2 on PC, NEON on Android) for the matrix and lighting maths.

### 15. Batch draws

The N64 issues many small draws with the same state. Merge runs of draws with the same pipeline and resources into
one indexed draw (or instanced or indirect draws), so the GPU and the driver see far fewer calls. `DrvPresentBuffers`
and `vkGetInstanceProcAddr` (driver code the symbols could not name) were a large part of the workload thread.

### 16. Fewer allocations in hot paths

`RtlAllocateHeap` / `RtlFreeHeap` showed on the game and workload threads. Per-frame vectors and maps that are
rebuilt every frame should keep their storage (thread-local or per-frame arenas, as texture seams now does), and
nothing per draw should allocate.

### 17. Descriptor and command reuse

Build descriptor sets and command lists for unchanged passes once and reuse them; use descriptor indexing
(bindless textures) so changing a texture is an index, not a new set.

### 18. Read-backs only when needed

RT64 writes framebuffers back to RDRAM so the game can read them. Track whether the game actually reads a written
framebuffer (by address and frame) and skip the read-back, or do it late, when it doesn't: each read-back is a GPU
wait.

### 19. Effects that update less often

Shadow maps, reflections and other view-dependent passes don't all need to be redrawn every frame at high frame
rates: update them every other frame or when the camera or sun moves past a threshold (the far sun shadow map
already works this way: `SunFarRefresh` in `rt64_scene_effects.cpp`). Half-resolution passes with an upscale for AO,
reflections and volumetrics.

### 20. Builds tuned for speed

Profile-guided optimisation of the fork and the game (MSVC `/GENPROFILE` then `/USEPROFILE`, or clang's
`-fprofile-instr-generate` / `-use`), ThinLTO with clang-cl, and per-CPU builds as the port already makes ("newer
CPUs, 2013 and up"). The recompiled game is huge; PGO's hot/cold code layout helps it most. LLVM BOLT does not
support Windows (PE/COFF) binaries.

### 21. Thread placement

Put the game thread, the Gfx thread and the workload thread on the fast cores: on hybrid Intel CPUs keep them off
the efficiency cores (thread priority and `SetThreadInformation` power throttling hints); on Android ask for the big
cores with the Android Dynamic Performance Framework (`APerformanceHint`), which also tells the phone how long a
frame should take so it can clock up before falling behind.

### 22. Dynamic resolution

Hold a target frame time by lowering and raising the internal resolution a step at a time, with the upscaler
filling in. Above all for phones, where heat lowers the clocks during a session.

### 23. Interpolation matching cost

Above the game's rate, RT64 matches objects and matrices between frames to interpolate them. Measure what that
costs per frame and cache matches that held last frame.

## Testing and tools

### 7. Display-list capture and replay

Record each frame's display lists and the RDRAM they read (only the ranges used, compressed) into a file; replay
them through the renderer with no game. Uses: exact pixel comparisons of the same frames from every game after each
change, in seconds; profiling one frame alone; a regression suite in CI that needs no ROM in the repo (captures
stay local, as they hold game data). Build this first.

### 8. One automation and stats API for every game

Frame stats, GPU timers per pass (`GpuSection`), the renderer's CPU parts (`RecordRendererCpuTimes`), screenshots
with and without the menus (`RequestWindowScreenshot`), texture dumping without the debugger
(`SetTextureDumpDirectory`) and frame capture: Banjo has most of these in `rt64-ext`, Mario Party has frame capture.
One API in the fork, the same in every game, so `perf_sweep.py`-style tools work everywhere. Keep the game side's
copy of any struct in step with RT64's (Banjo's overlay had `FrameStats` with 14 GPU sections where RT64 had 17
until 2026-11-07; use a `static_assert`, or don't copy the struct).

### 24. Built-in profiler zones

Tracy (BSD licence) zones around the frame loop, each thread's main stages and every pass, with GPU zones from the
same timestamp queries: a timeline of one frame across threads, which the sampling profiler (`hostprof`, self time
and two callers) can't give.

### 9. Driver and device robustness

Recover from a lost GPU device; handle a lost surface (done for Android in Banjo, 2026-11-07); a clean shutdown
order so nothing is destroyed after the device (Banjo's quit crash in `plume::VulkanGraphicsPipeline`'s destructor,
fixed 2026-11-07 by ending through `quick_exit`, really wants the fork releasing its own statics in order); a table
of driver workarounds by vendor and version.

## Picture and output

### 10. Frame pacing and display output

Variable refresh, the present mode (FIFO, mailbox, immediate), frame-time targets and latency control as one fork
feature for every game; HDR output as a later step.

### 11. Texture pack improvements

Compressed formats (BC7 on PC, ASTC on Android), streaming under a memory budget (Banjo's texture sweep, 926
entrances: the port's own GPU memory settled near 650 MB with about 2,300 cached textures; a phone has far less),
and proper mipmaps for replaced textures.

### 12. Motion vectors and depth for every game

Per-object motion vectors and a reactive mask as a fork feature, so temporal upscalers (FSR, DLSS, Snapdragon GSR)
and future effects work in any game, not only through Banjo's `rt64_object_velocity` and temporal upscaler code.

## Platforms

### 13. A mobile-first path

On Android, switched on by itself: passes arranged for tiled GPUs (fewer full-screen passes, load and store actions
that keep work in tile memory), lower-precision formats where the picture is the same, ASTC textures, and a quality
default per device class. Banjo's Android build sets 30 FPS, Original 2x and the Original effects preset on first
start (`apply_android_defaults_once` in `src/game/config.cpp`); the fork should own the renderer half of that.

### 25. Android power and heat

Besides the performance hint (21): cap the frame rate to what the device holds steadily rather than the most it
reaches cold, watch the thermal status (`AThermal_getCurrentThermalStatus`) and step quality down before the phone
throttles, and stop all GPU work while the app is in the background (done in Banjo, 2026-11-07).

## How to check each change

As in the first handover: the replay harness (7) once it exists; until then the same map list swept twice before
and twice after with medians compared, screenshots of the same views diffed against the spread between two runs of
the old build, and old and new code run side by side on the same inputs where results must be exact. Say what was
measured, on what machine, and what wasn't.
