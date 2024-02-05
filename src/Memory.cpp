#include "Memory.h"
#include <array>
#include <cstdint>
#include <iostream>
#include <cassert>

Memory::Memory() {
    constexpr std::array<uint8_t, 80> font {
        0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
        0x20, 0x60, 0x20, 0x20, 0x70, // 1
        0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
        0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
        0x90, 0x90, 0xF0, 0x10, 0x10, // 4
        0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
        0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
        0xF0, 0x10, 0x20, 0x40, 0x40, // 7
        0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
        0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
        0xF0, 0x90, 0xF0, 0x90, 0x90, // A
        0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
        0xF0, 0x80, 0x80, 0x80, 0xF0, // C
        0xE0, 0x90, 0x90, 0x90, 0xE0, // D
        0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
        0xF0, 0x80, 0xF0, 0x80, 0x80  // F
    };
    constexpr std::size_t fontStartInMemory {0x50};
    std::size_t counter {0x0};

    for (auto byte : font) {
        m_data[fontStartInMemory + counter] = byte; 
        ++counter;
    }
}

uint8_t& Memory::operator[](uint16_t index) {
#ifndef RELEASE
    assert(index >= 0 && index < 4096 && "Memory access out of bounds");
#endif
    return m_data[static_cast<std::size_t>(index)];
}

// DEBUG
void Memory::print() const {
    std::cout << std::hex;
    for (std::size_t i {0}; i < m_data.size(); ++i) {
        std::cout << "Address: " << i << '\t' << "Value: " << static_cast<int>(m_data[i]) << "\n"; 
    }
}
