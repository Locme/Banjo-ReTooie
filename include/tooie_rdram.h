#ifndef __TOOIE_RDRAM_H__
#define __TOOIE_RDRAM_H__

#include <cstdint>
#include <cstring>

// Reads and writes of the game's memory by N64 address (0x80000000 and up), for code that walks
// the game's structures. RDRAM is stored a word at a time in host order, so halfwords and bytes
// are found at the address XOR 2 and XOR 3. These replace the copies each feature had of its own.
namespace tooie::rdram {
    // A pointer into the game's 16 MB of RDRAM (KSEG0).
    inline bool valid_ptr(uint32_t p) {
        return p >= 0x80000000u && p < 0x81000000u;
    }

    inline uint32_t read_word(uint8_t* rdram, uint32_t addr) {
        return *reinterpret_cast<uint32_t*>(rdram + (addr - 0x80000000u));
    }

    inline void write_word(uint8_t* rdram, uint32_t addr, uint32_t value) {
        *reinterpret_cast<uint32_t*>(rdram + (addr - 0x80000000u)) = value;
    }

    inline int16_t read_half(uint8_t* rdram, uint32_t addr) {
        return *reinterpret_cast<int16_t*>(rdram + ((addr ^ 2) - 0x80000000u));
    }

    inline uint8_t read_byte(uint8_t* rdram, uint32_t addr) {
        return rdram[(addr ^ 3) - 0x80000000u];
    }

    inline void write_half(uint8_t* rdram, uint32_t addr, uint16_t value) {
        *reinterpret_cast<uint16_t*>(rdram + ((addr ^ 2) - 0x80000000u)) = value;
    }

    inline float read_float(uint8_t* rdram, uint32_t addr) {
        uint32_t bits = read_word(rdram, addr);
        float value;
        std::memcpy(&value, &bits, sizeof(value));
        return value;
    }

    inline void write_float(uint8_t* rdram, uint32_t addr, float value) {
        uint32_t bits;
        std::memcpy(&bits, &value, sizeof(bits));
        write_word(rdram, addr, bits);
    }
}

#endif
