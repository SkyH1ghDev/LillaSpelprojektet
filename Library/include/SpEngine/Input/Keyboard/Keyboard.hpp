#pragma once

#include <map>
#include <Windows.h>

#include "Key.hpp"

class Keyboard
{
public:
    Keyboard();
    ~Keyboard() = default;
    Keyboard(const Keyboard& other) = default;
    Keyboard& operator=(const Keyboard& other) = default;
    Keyboard(Keyboard&& other) noexcept = default;
    Keyboard& operator=(Keyboard&& other) noexcept = default;

    [nodiscard]
    MSG ReadWindowsMessage();

    void HandleInput();

private:
    std::map<int, Key> m_keys;

};
