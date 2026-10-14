// Functions the recompiled code and the runtime expect the project to provide.

#include <cstdio>
#include <string>

#include "recomp.h"
#include "librecomp/helpers.hpp"
#include "recompui/recompui.h"
#include "ultramodern/ultramodern.hpp"
#include "ultramodern/error_handling.hpp"

extern "C" void recomp_puts(uint8_t* rdram, recomp_context* ctx) {
    PTR(char) str = _arg<0, PTR(char)>(rdram, ctx);
    u32 length = _arg<1, u32>(rdram, ctx);
    for (u32 i = 0; i < length; i++) {
        fputc(MEM_B(i, (gpr)str), stdout);
    }
}

extern "C" void recomp_exit(uint8_t* /*rdram*/, recomp_context* /*ctx*/) {
    ultramodern::quit();
}

extern "C" void recomp_error(uint8_t* rdram, recomp_context* ctx) {
    std::string str{};
    PTR(u8) str_ptr = _arg<0, PTR(u8)>(rdram, ctx);
    for (size_t i = 0; MEM_B(str_ptr, i) != '\x00'; i++) {
        str += (char)MEM_B(str_ptr, i);
    }
    recompui::message_box(str.c_str());
    ultramodern::error_handling::quick_exit(__FILE__, __LINE__, __FUNCTION__);
}
