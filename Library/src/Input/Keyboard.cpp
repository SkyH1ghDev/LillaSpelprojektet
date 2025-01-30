#include "Keyboard.hpp"

#define KEY_PRESSED 0x80

Keyboard::Keyboard()
{
    this->m_keys =
    {
        {VK_ESCAPE, std::make_shared<Key>()}, {VK_TAB, std::make_shared<Key>()}, {VK_CAPITAL, std::make_shared<Key>()}, {VK_LSHIFT, std::make_shared<Key>()}, {VK_LCONTROL, std::make_shared<Key>()}, {VK_SPACE, std::make_shared<Key>()},
		{VK_F1, std::make_shared<Key>()}, {VK_F2, std::make_shared<Key>()}, {VK_F3, std::make_shared<Key>()}, {VK_F4, std::make_shared<Key>()}, {VK_F5, std::make_shared<Key>()}, {VK_F6, std::make_shared<Key>()}, {VK_F7, std::make_shared<Key>()}, {VK_F8, std::make_shared<Key>()}, {VK_F9, std::make_shared<Key>()}, {VK_F10, std::make_shared<Key>()}, {VK_F11, std::make_shared<Key>()}, {VK_F12, std::make_shared<Key>()},

        {'1', std::make_shared<Key>()}, {'2', std::make_shared<Key>()}, {'3', std::make_shared<Key>()}, {'4', std::make_shared<Key>()}, {'5', std::make_shared<Key>()}, {'6', std::make_shared<Key>()}, {'7', std::make_shared<Key>()}, {'8', std::make_shared<Key>()}, {'9', std::make_shared<Key>()}, {'0', std::make_shared<Key>()},
        {'Q', std::make_shared<Key>()}, {'W', std::make_shared<Key>()}, {'E', std::make_shared<Key>()}, {'R', std::make_shared<Key>()}, {'T', std::make_shared<Key>()}, {'Y', std::make_shared<Key>()}, {'U', std::make_shared<Key>()}, {'I', std::make_shared<Key>()}, {'O', std::make_shared<Key>()}, {'P', std::make_shared<Key>()}, {'Å', std::make_shared<Key>()},
        {'A', std::make_shared<Key>()}, {'S', std::make_shared<Key>()}, {'D', std::make_shared<Key>()}, {'F', std::make_shared<Key>()}, {'G', std::make_shared<Key>()}, {'H', std::make_shared<Key>()}, {'J', std::make_shared<Key>()}, {'K', std::make_shared<Key>()}, {'L', std::make_shared<Key>()}, {'Ö', std::make_shared<Key>()}, {'Ä', std::make_shared<Key>()},
        {'Z', std::make_shared<Key>()}, {'X', std::make_shared<Key>()}, {'C', std::make_shared<Key>()}, {'V', std::make_shared<Key>()}, {'B', std::make_shared<Key>()}, {'N', std::make_shared<Key>()}, {'M', std::make_shared<Key>()}
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

	if (msg.message == WM_QUIT)
	{
		this->m_keys[VK_ESCAPE]->Notify();
	}

	BYTE keyStates[256];
	GetKeyboardState(keyStates);

	for (int i = 0; i < 256; ++i)
	{
		if (keyStates[i] & KEY_PRESSED)
		{
			this->m_keys[i]->Notify();
		}
	}
}

