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

    /**
     * Gets key based on windows virtual key
     *
     * @param virtualKey Windows virtual key that represents what key object to return
     * @return Key object
     */
    std::shared_ptr<Key> GetKey(const int& virtualKey);

private:

    /**
     * Reads the states of key inputs from the keyboard
     *
     * @return Input message from the windows event system
     */
    MSG ReadWindowsMessage();

private:
    std::map<int, std::shared_ptr<Key>> m_keys;

};

inline std::shared_ptr<Key> Keyboard::GetKey(const int& virtualKey)
{
    return this->m_keys[virtualKey];
}
