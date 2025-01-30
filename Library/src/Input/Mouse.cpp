#include "Mouse.hpp"

Mouse::Mouse()
{
	ZeroMemory(this->m_buttons, sizeof(this->m_buttons));
	GetCursorPos(&this->m_mousePos);
}

void Mouse::Update(HWND &hWnd)
{
	GetCursorPos(&this->m_mousePos);
	ScreenToClient(hWnd, &this->m_mousePos);
	UpdateButtons();
}

bool Mouse::IsButtonPressed(int ButtonIndex) const
{
	if (ButtonIndex < 0 || ButtonIndex > 5)
	{
		return false;
	}
	return this->m_buttons[ButtonIndex];
}

void Mouse::UpdateButtons()
{
	this->m_buttons[0] = (GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0;
	this->m_buttons[1] = (GetAsyncKeyState(VK_RBUTTON) & 0x8000) != 0;
	this->m_buttons[2] = (GetAsyncKeyState(VK_MBUTTON) & 0x8000) != 0;
	this->m_buttons[3] = (GetAsyncKeyState(VK_XBUTTON1) & 0x8000) != 0;
	this->m_buttons[4] = (GetAsyncKeyState(VK_XBUTTON2) & 0x8000) != 0;
}

int Mouse::AnyButton()
{
	int ButtonIndex = -1;
	for (int i = 0; i < 5; i++)
	{
		if (this->m_buttons[i])
		{
			ButtonIndex = i;
		}
	}
	return ButtonIndex;
}
