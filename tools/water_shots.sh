#!/bin/bash
# Headless water test: the same water spots with Water Original, Modern and Stylised, side by side.
# Usage: [SPOTS=sm|jrl|all] [STYLES='0 1 2'] [FIRST_SPOT_MS=90000] [OUT=<folder>] tools/water_shots.sh
# Needs the same run folder as headless_boot.sh (RUN_DIR, Xvfb on :99, lavapipe, ImageMagick). Each style is one run
# per map: Banjo is warped in and teleported from spot to spot, with a screenshot at each. Writes
# <OUT>/<spot>.png (Original | Modern | Stylised) and <OUT>/all.png.
# Lavapipe stalls now and then (Game 0 fps): a run whose shots are missing is retried once.
run_dir=${RUN_DIR:-/home/claude/run}
out=${OUT:-$run_dir/water-shots}
spots=${SPOTS:-all}
mkdir -p "$out"
cd "$run_dir" || exit 1

# One map: name, warp, then "spot=x,y,z[/pad]" entries. Banjo is put at each spot in turn, 25 s apart, and shot 18 s
# and 21 s after (the second shot is the one kept; the first is a spare if the picture was mid-wipe). The optional
# pad entry (inputs:ms, as in --pad-script) is held from 8 s after the teleport, to swing the camera round.
declare -A maps
maps[sm]="AF:0@30000|pool=1178,640,471/rx=1:500|across=1178,640,471/rx=-1:1400|turned=1178,640,471/rx=1:1600"
maps[jrl]="1A7:0@30000|harbour=0,0,0"
first_spot_ms=${FIRST_SPOT_MS:-90000}
spot_gap_ms=25000

style_name() { case $1 in 0) echo original ;; 1) echo modern ;; 2) echo stylised ;; esac; }

run_map() {  # map key, style number
    local key=$1 style=$2 spec=${maps[$1]}
    local warp=${spec%%|*} rest=${spec#*|}
    local teleports="" shots="" pad="" names=() i=0
    IFS='|' read -ra entries <<< "$rest"
    for e in "${entries[@]}"; do
        local at=$((first_spot_ms + i * spot_gap_ms))
        local place=${e#*=}
        teleports+="${teleports:+;}${place%%/*}@$at"
        [[ $place == */* ]] && pad+="${pad:+;}$((at + 8000)):${place#*/}"
        shots+="${shots:+,}$((at + 18000)),$((at + 21000))"
        names+=("${e%%=*}")
        i=$((i + 1))
    done
    local secs=$(( (first_spot_ms + i * spot_gap_ms) / 1000 + 40 ))
    for p in $(pgrep -x BanjoTooieN64Re); do kill -9 $p; done
    rm -rf screenshots
    TOOIE_MODERN_WATER=$style TOOIE_WARP=$warp TOOIE_TELEPORT="$teleports" TOOIE_SCREENSHOT_AT="$shots" \
        LP_NUM_THREADS=0 DISPLAY=:99 VK_ICD_FILENAMES=/usr/share/vulkan/icd.d/lvp_icd.json SDL_AUDIODRIVER=dummy \
        timeout -s KILL $secs ./BanjoTooieN64Recomp --game bt ${pad:+--pad-script "$pad"} > "$out/$key-$(style_name $style).log" 2>&1
    # Screenshots are named by time, so in order: two per spot, keep the second.
    local files=($(ls screenshots/*.png 2>/dev/null | sort))
    for j in "${!names[@]}"; do
        local f=${files[$((j * 2 + 1))]:-${files[$((j * 2))]}}
        [ -n "$f" ] && cp "$f" "$out/${names[$j]}-$(style_name $style).png"
    done
    [ ${#files[@]} -ge $((i * 2 - 1)) ]
}

keys=(sm jrl)
[ "$spots" != all ] && keys=($spots)
for key in "${keys[@]}"; do
    for style in ${STYLES:-0 1 2}; do
        run_map $key $style || { echo "$key $(style_name $style): shots missing, retrying"; run_map $key $style; }
    done
    rest=${maps[$key]#*|}
    IFS='|' read -ra entries <<< "$rest"
    for e in "${entries[@]}"; do
        n=${e%%=*}
        montage -label '%t' "$out/$n-original.png" "$out/$n-modern.png" "$out/$n-stylised.png" \
            -tile 3x -geometry 640x360+4+4 "$out/$n.png" 2>/dev/null && echo "$out/$n.png"
    done
done
ls "$out"/*-original.png >/dev/null 2>&1 && montage $(ls "$out"/*.png | grep -v -e '-original\|-modern\|-stylised\|all.png') \
    -tile 1x -geometry +0+4 "$out/all.png" 2>/dev/null
