#pragma once
#include <cstdint>

enum KeyState : std::uint8_t
{
    KeyState_NotPressed = 0b0001,
    KeyState_Released = 0b0011,
    KeyState_Pressed = 0b01000,
    KeyState_Held = 0b1100,
};
