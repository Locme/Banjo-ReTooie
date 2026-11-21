#!/usr/bin/env bash
# Build Banjo Re-Tooie as a self-contained Linux x86_64 AppImage.
#
# Usage:
#   tools/build_appimage.sh [cmake-build-dir]
#
# The build dir defaults to build-appimage/, or set TOOIE_BUILD_DIR. An existing
# CMake build is reused and only rebuilt incrementally. The finished AppImage is
# written to dist/ (override with TOOIE_APPIMAGE_OUT).
#
# Needs clang, ninja and the GTK 3 development packages, as the normal Linux
# build does. linuxdeploy, appimagetool and the GTK deployment plugin are
# downloaded once into build-appimage/tools/.
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
ARCH="x86_64"
if [[ "$(uname -m)" != "$ARCH" ]]; then
    echo "build_appimage.sh: only x86_64 is supported, this machine is $(uname -m)." >&2
    exit 1
fi

BUILD_DIR="${1:-${TOOIE_BUILD_DIR:-$ROOT/build-appimage}}"
if [[ "$BUILD_DIR" != /* ]]; then
    BUILD_DIR="$ROOT/$BUILD_DIR"
fi
WORK_DIR="${TOOIE_APPIMAGE_WORK:-$ROOT/build-appimage}"
TOOLS_DIR="${TOOIE_APPIMAGE_TOOLS:-$WORK_DIR/tools}"
OUT_DIR="${TOOIE_APPIMAGE_OUT:-$ROOT/dist}"
APPDIR="$WORK_DIR/AppDir"

# Pinned so a build does not change under us. The hashes are checked after download.
LINUXDEPLOY_VERSION="1-alpha-20251107-1"
LINUXDEPLOY_SHA256="c20cd71e3a4e3b80c3483cef793cda3f4e990aca14014d23c544ca3ce1270b4d"
GTK_PLUGIN_COMMIT="7a3fbc31a9e5075073ff8790f26effbac5f84453"
GTK_PLUGIN_SHA256="b0f4cbc684a0103a9651f0955b635eaea0096b3a66c0f5a2c2aa337960375171"

die() { echo "build_appimage.sh: $*" >&2; exit 1; }

for tool in cmake ninja curl sha256sum; do
    command -v "$tool" >/dev/null || die "$tool is needed but was not found in PATH."
done

# ---- build the game -------------------------------------------------------
GAME="$BUILD_DIR/BanjoReTooie"
if [[ "${TOOIE_SKIP_BUILD:-0}" != "1" ]]; then
    if [[ ! -f "$BUILD_DIR/CMakeCache.txt" ]]; then
        cmake -S "$ROOT" -B "$BUILD_DIR" -G Ninja -DCMAKE_BUILD_TYPE=Release \
            -DCMAKE_C_COMPILER="${CC:-clang}" -DCMAKE_CXX_COMPILER="${CXX:-clang++}"
    fi
    cmake --build "$BUILD_DIR" --target BanjoTooieN64Recomp -j "${JOBS:-$(nproc)}"
fi
[[ -x "$GAME" ]] || die "no executable at $GAME (build it first, or drop TOOIE_SKIP_BUILD)."

# ---- fetch the packaging tools -------------------------------------------
mkdir -p "$TOOLS_DIR"
fetch() { # $1 = URL, $2 = destination, $3 = sha256
    local url="$1" dest="$2" sha="$3"
    if [[ -x "$dest" ]] && echo "$sha  $dest" | sha256sum -c --status; then
        return
    fi
    echo "Downloading $(basename "$dest")"
    curl -fL --retry 3 -o "$dest.part" "$url"
    echo "$sha  $dest.part" | sha256sum -c --status \
        || { rm -f "$dest.part"; die "checksum mismatch for $url"; }
    mv "$dest.part" "$dest"
    chmod +x "$dest"
}

LINUXDEPLOY="$TOOLS_DIR/linuxdeploy-$ARCH.AppImage"
fetch "https://github.com/linuxdeploy/linuxdeploy/releases/download/$LINUXDEPLOY_VERSION/linuxdeploy-$ARCH.AppImage" \
    "$LINUXDEPLOY" "$LINUXDEPLOY_SHA256"
fetch "https://raw.githubusercontent.com/linuxdeploy/linuxdeploy-plugin-gtk/$GTK_PLUGIN_COMMIT/linuxdeploy-plugin-gtk.sh" \
    "$TOOLS_DIR/linuxdeploy-plugin-gtk.sh" "$GTK_PLUGIN_SHA256"

# ---- stage the AppDir -----------------------------------------------------
rm -rf "$APPDIR"
install -Dm755 "$GAME" "$APPDIR/usr/bin/BanjoReTooie"
cp -a "$ROOT/assets" "$APPDIR/usr/bin/assets"
install -Dm644 "$ROOT/recompcontrollerdb.txt" "$APPDIR/usr/bin/recompcontrollerdb.txt"
install -Dm644 "$ROOT/COPYING" "$APPDIR/usr/bin/COPYING"
install -Dm644 "$ROOT/README.md" "$APPDIR/usr/bin/README.md"
install -Dm644 "$ROOT/packaging/linux/banjo-retooie.desktop" \
    "$APPDIR/usr/share/applications/banjo-retooie.desktop"
install -Dm644 "$ROOT/icons/app.png" \
    "$APPDIR/usr/share/icons/hicolor/256x256/apps/banjo-retooie.png"

# ---- linuxdeploy: dependencies, GTK data, AppImage ------------------------
# NO_STRIP keeps the game's symbols (the crash logs use them). Newer glibc
# libraries cannot be stripped by linuxdeploy's bundled binutils anyway.
export NO_STRIP=1
export APPIMAGE_EXTRACT_AND_RUN=1
export DEPLOY_GTK_VERSION=3
export ARCH
export PATH="$TOOLS_DIR:$PATH"

mkdir -p "$OUT_DIR"
# linuxdeploy names the output after the desktop file's Name. Build it in a
# clean folder and find it, so a name change in a future appimagetool does not
# break the script.
STAGE_OUT="$WORK_DIR/output"
rm -rf "$STAGE_OUT"
mkdir -p "$STAGE_OUT"
(
    cd "$STAGE_OUT"
    "$LINUXDEPLOY" \
        --appdir "$APPDIR" \
        --executable "$APPDIR/usr/bin/BanjoReTooie" \
        --desktop-file "$APPDIR/usr/share/applications/banjo-retooie.desktop" \
        --icon-file "$ROOT/icons/app.png" --icon-filename banjo-retooie \
        --custom-apprun "$ROOT/packaging/linux/AppRun" \
        --plugin gtk \
        --output appimage
)
PRODUCED="$(find "$STAGE_OUT" -maxdepth 1 -type f -name '*.AppImage' -print -quit)"
[[ -n "$PRODUCED" ]] || die "linuxdeploy did not produce an AppImage."

VERSION="${TOOIE_VERSION:-}"
if [[ -z "$VERSION" ]]; then
    VERSION="$(sed -n 's/^const std::string version_string = "\(.*\)";/\1/p' "$ROOT/src/main/main.cpp" | head -n1)"
fi
[[ -n "$VERSION" ]] || VERSION="$(git -C "$ROOT" rev-parse --short HEAD 2>/dev/null || echo unknown)"
OUTPUT="$OUT_DIR/BanjoReTooie-$VERSION-linux-$ARCH.AppImage"
mv -f "$PRODUCED" "$OUTPUT"
rm -rf "$STAGE_OUT"
echo "Built $OUTPUT"
