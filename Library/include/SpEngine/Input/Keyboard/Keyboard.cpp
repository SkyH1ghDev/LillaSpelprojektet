#include "Keyboard.hpp"

Keyboard::Keyboard()
{
    this->m_keys =
    {
        {VK_ESCAPE, Key()}, {VK_TAB, Key()}, {VK_CAPITAL, Key()}, {VK_LSHIFT, Key()}, {VK_LCONTROL, Key()}, {VK_SPACE, Key()},
		{VK_F1, Key()}, {VK_F2, Key()}, {VK_F3, Key()}, {VK_F4, Key()}, {VK_F5, Key()}, {VK_F6, Key()}, {VK_F7, Key()}, {VK_F8, Key()}, {VK_F9, Key()}, {VK_F10, Key()}, {VK_F11, Key()}, {VK_F12, Key()},

        {'1', Key()}, {'2', Key()}, {'3', Key()}, {'4', Key()}, {'5', Key()}, {'6', Key()}, {'7', Key()}, {'8', Key()}, {'9', Key()}, {'0', Key()},
        {'Q', Key()}, {'W', Key()}, {'E', Key()}, {'R', Key()}, {'T', Key()}, {'Y', Key()}, {'U', Key()}, {'I', Key()}, {'O', Key()}, {'P', Key()}, {'Å', Key()},
        {'A', Key()}, {'S', Key()}, {'D', Key()}, {'F', Key()}, {'G', Key()}, {'H', Key()}, {'J', Key()}, {'K', Key()}, {'L', Key()}, {'Ö', Key()}, {'Ä', Key()},
        {'Z', Key()}, {'X', Key()}, {'C', Key()}, {'V', Key()}, {'B', Key()}, {'N', Key()}, {'M', Key()}
    };
}

MSG Keyboard::ReadWindowsMessage()
{
	MSG msg;

	if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg;
}

void Keyboard::HandleInput()
{
	MSG msg = ReadWindowsMessage();
}

