#!/bin/bash
# Headless test run (Linux container): screenshots every 20 s, then a stack dump of all threads.
# Usage: [PAD='<pad script>'] [TOOIE_WATCH=addr,...] tools/headless_boot.sh <seconds> <tag>
# Needs Xvfb on :99 (Xvfb :99 -screen 0 1280x720x24 &), lavapipe, gdb and ImageMagick.
# RUN_DIR holds a copied (not symlinked) exe, assets/, portable.txt and the ROM as bt.n64.us.1.0.z64.
secs=${1:-70}; tag=${2:-run}
cd "${RUN_DIR:-/home/claude/run}" || exit 1
for p in $(pgrep -x BanjoTooieN64Re); do kill -9 $p; done  # never pkill -f: it matches this shell
rm -f $tag-*.png
TOOIE_WATCH=$TOOIE_WATCH DISPLAY=:99 VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.json SDL_AUDIODRIVER=dummy \
    timeout -s KILL $((secs + 30)) ./BanjoTooieN64Recomp --game bt ${PAD:+--pad-script "$PAD"} > $tag.log 2>&1 &
n=$(( secs / 20 ))
for i in $(seq 1 $n); do sleep 20; DISPLAY=:99 import -window root $tag-$i.png; done
pid=$(pgrep -x BanjoTooieN64Re | head -1)
if [ -n "$pid" ]; then gdb -p $pid -batch -ex 'thread apply all bt 25' > $tag-gdb.txt 2>&1; else echo "process exited early"; fi
for p in $(pgrep -x BanjoTooieN64Re); do kill -9 $p; done
grep -v 'font face' $tag.log | tail -15
command -v montage >/dev/null && montage $(ls $tag-[0-9]*.png | sort -t- -k2 -n) -tile 7x -geometry 280x158+2+2 $tag-all.png
# Game threads' recompiled frames: shows where each N64 thread is waiting or spinning.
awk '/^Thread/{t=$0} /func_|_recomp|ultramodern::|syscall_handler|ovl_|_entrypoint|tooie/{print substr(t,1,60)" || "$0}' $tag-gdb.txt 2>/dev/null \
    | grep 'Game Thread' | sed 's/ (unsigned.*//; s/0x0000[0-9a-f]* in //' | head -60
