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

    /**
     * Handles the input from the keyboard
     */
    void HandleInput();

private:

    /**
     * Reads the states of key inputs from the keyboard
     *
     * @remark [[nodiscard]]
     * @return Input message from the windows event system
     */
    [[nodiscard]]
    MSG ReadWindowsMessage();

private:
    std::map<int, Key> m_keys;

};
