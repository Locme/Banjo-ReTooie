#!/bin/bash
# Build a call-profiling copy of the game into build-trace/ (Linux/macOS).
# The generated code gets trace_mode = true, so every function counts its
# calls; run it with TOOIE_TRACE=calls.txt (see src/debug/trace.cpp) and
# compare windows with tools/trace_diff.py. Needs the same N64Recomp binary and
# patched ELF as a normal regeneration (BUILDING.md). Nothing here is committed.
set -e
cd "$(dirname "$0")/.."
mkdir -p build-trace/RecompiledFuncs
sed -e 's|^output_func_path = .*|output_func_path = "build-trace/RecompiledFuncs"\ntrace_mode = true|' \
    banjotooie.us.toml > banjotooie.trace.toml
./N64Recomp banjotooie.trace.toml
rm banjotooie.trace.toml
cmake -S . -B build-trace -G Ninja -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_C_COMPILER=${CC:-clang} -DCMAKE_CXX_COMPILER=${CXX:-clang++} \
    -DRECOMP_FUNCS_DIR="$PWD/build-trace/RecompiledFuncs"
cmake --build build-trace --target BanjoTooieN64Recomp
echo "Built build-trace/BanjoReTooie"
