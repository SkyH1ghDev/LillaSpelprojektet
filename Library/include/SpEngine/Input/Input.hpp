#pragma once

#include <unordered_map>
#include <Windows.h>

#include "Key.hpp"

class Input
{
public:
    Input() = default;
    ~Input() = default;
    Input(const Input& other) = default;
    Input& operator=(const Input& other) = default;
    Input(Input&& other) noexcept = default;
    Input& operator=(Input&& other) noexcept = default;

    /**
     * Handles the input from the keyboard
     */
    static void HandleInput(const HWND& hWnd);

    /**
     * Gets key based on windows virtual key
     *
     * @param virtualKey Windows virtual key that represents what key object to return
     * @return Key object
     */
    static std::shared_ptr<Key> GetKey(const int& virtualKey);

    /**
     * Gets the current x-position of the mouse
     *
     * @return Cursor X-position
     */
    static long GetMousePositionX();

    /**
     * Gets the current y-position of the mouse
     *
     * @return Cursor Y-position
     */
    static long GetMousePositionY();

    /**
     * Reads the states of key inputs from the keyboard
     *
     * @return Input message from the windows event system
     */
    static MSG ReadWindowsMessage();

private:
    static std::unordered_map<int, std::shared_ptr<Key>> m_bindableKeys;

    static POINT m_cursorPosition;

};

inline std::shared_ptr<Key> Input::GetKey(const int& virtualKey)
{
    return m_bindableKeys[virtualKey];
}

inline long Input::GetMousePositionX()
{
    return m_cursorPosition.x;
}

inline long Input::GetMousePositionY()
{
    return m_cursorPosition.y;
}
