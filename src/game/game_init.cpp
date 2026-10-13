#include "tooie_game.h"
#include "tooie_cheats.h"
#include "tooie_watchdog.h"

extern "C" void load_overlays(uint32_t rom, int32_t ram_addr, uint32_t size);

// core1 and core2 never arrive through a DMA the runtime can see: the boot
// code and core1 inflate them from compressed ROM straight into RDRAM. Map
// their recompiled functions up front so indirect calls into them resolve.
// (ROM addresses are those of the decompressed image the code was built from.)
void tooie::on_game_init(uint8_t* rdram, recomp_context* ctx) {
    load_overlays(0x01E29B60, 0x80012030, 0x00031350); // core1
    load_overlays(0x01E5AEB0, 0x800815C0, 0x000A5170); // core2
    start_debug_watch(rdram);
    tooie::watchdog::start();
    tooie::cheats::start(rdram);
}
