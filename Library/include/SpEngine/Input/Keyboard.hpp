#pragma once

#include <unordered_map>
#include <Windows.h>

#include "Key.hpp"

class Keyboard
{
public:
    Keyboard() = default;
    ~Keyboard() = default;
    Keyboard(const Keyboard& other) = default;
    Keyboard& operator=(const Keyboard& other) = default;
    Keyboard(Keyboard&& other) noexcept = default;
    Keyboard& operator=(Keyboard&& other) noexcept = default;

    /**
     * Handles the input from the keyboard
     */
    static void HandleInput();

    /**
     * Gets key based on windows virtual key
     *
     * @param virtualKey Windows virtual key that represents what key object to return
     * @return Key object
     */
    static std::shared_ptr<Key> GetKey(const int& virtualKey);

private:

    /**
     * Reads the states of key inputs from the keyboard
     *
     * @return Input message from the windows event system
     */
    static MSG ReadWindowsMessage();

private:
    static std::unordered_map<int, std::shared_ptr<Key>> m_keys;

};

inline std::shared_ptr<Key> Keyboard::GetKey(const int& virtualKey)
{
    return m_keys[virtualKey];
}
