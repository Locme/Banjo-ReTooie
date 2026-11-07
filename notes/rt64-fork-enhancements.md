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
4. The rest by need: phones (13, 11), the remaining speed-ups, picture and output.

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

### 4. Fewer thread handoffs inside RT64

Count the synchronisation points per frame between RT64's own threads (the Gfx thread, the workload thread, the
present thread) and remove what isn't needed: batch more work per handoff, spin briefly before sleeping where a wait
is usually short, and use lock-free queues where the profile shows SRW lock time (`RtlAcquireSRWLockExclusive` /
`RtlReleaseSRWLockExclusive` on the workload thread).

### 5. A pipeline cache on disk

Save the driver's pipeline cache (`VkPipelineCache`, D3D12's pipeline library) across runs, next to RT64's own
shader cache, so the specialised pipelines a player has met load instead of compiling. Most useful on phones,
where compiling is slowest.

### 6. Parallel draw setup

Spread per-framebuffer work over worker threads: RT64's draw setup and the CPU side of each effect module, instead of
one after another on the workload thread. In Banjo's sweep one such module (texture seams' neighbour search) was
21-41% of that thread's compute, so the gain grows with every effect a game turns on.

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

### 19. Effect modules that update less often

At high frame rates not every view-dependent pass of an effect module needs redrawing each frame: shadow maps,
reflections and the like can update every other frame, or when the camera or the light moves past a threshold.
Give modules a way to say how often they need to run, and support half-resolution passes with an upscale (ambient
occlusion, reflections, volumetrics).

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
that keep work in tile memory), lower-precision formats where the picture is the same, ASTC textures, and a
renderer quality default per device class (internal resolution, MSAA, which effect modules start on). The game sets
its own defaults on top.

## How to check each change

As in the first handover: the replay harness (7) once it exists; until then the same map list swept twice before
and twice after with medians compared, screenshots of the same views diffed against the spread between two runs of
the old build, and old and new code run side by side on the same inputs where results must be exact. Say what was
measured, on what machine, and what wasn't.

## Measurement in the renderer: stutters and slow frames (L, 2026-11-07)

What only RT64 can measure, because only it knows when it compiled a shader, uploaded a texture, waited for the GPU
or read a picture back. The game-side tools that drive sweeps (Banjo's `tools/perf_sweep.py`, Mario Party's
`tools/frame_check/`) read these through the stats API (8) and are not part of the fork.

### 26. Hitch log with causes

Every presented frame's time, and for each frame longer than about twice the median, what happened in it: shader or
pipeline compiles (with which), texture uploads (count and bytes), read-backs to RDRAM, framebuffers created or
resized, GPU waits, and the game's own map change if the game reports one. Written per run as a csv next to the
benchmark. Banjo's sweep could only say a frame was 1.7-2.0 s long on every arrival and guess at why; this says.

### 30. Stutter detection for interpolation

Mario Party's `draw_provenance.cpp` (draws that move only on logic steps, snap, or flash for one frame) and its
frame-check scripts, plus the `recomp-stutter` skill's method, built on the fork's capture (7) so any game gets
them: a list of draws whose motion steps instead of moving smoothly above the game's own rate.
