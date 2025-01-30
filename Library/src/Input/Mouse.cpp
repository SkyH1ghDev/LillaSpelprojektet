#include "Mouse.hpp"

Mouse::Mouse()
{
	ZeroMemory(this->Buttons, sizeof(this->Buttons));
	GetCursorPos(&this->MousePos);
}

void Mouse::Update(HWND &hWnd)
{
	GetCursorPos(&this->MousePos);
	ScreenToClient(hWnd, &this->MousePos);
	UpdateButtons();
}

bool Mouse::IsButtonPressed(int ButtonIndex) const
{
	if (ButtonIndex < 0 || ButtonIndex > 5)
	{
		return false;
	}
	return this->Buttons[ButtonIndex];
}

void Mouse::UpdateButtons()
{
	this->Buttons[0] = (GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0;
	this->Buttons[1] = (GetAsyncKeyState(VK_RBUTTON) & 0x8000) != 0;
	this->Buttons[2] = (GetAsyncKeyState(VK_MBUTTON) & 0x8000) != 0;
	this->Buttons[3] = (GetAsyncKeyState(VK_XBUTTON1) & 0x8000) != 0;
	this->Buttons[4] = (GetAsyncKeyState(VK_XBUTTON2) & 0x8000) != 0;
}

int Mouse::AnyButton()
{
	int ButtonIndex = -1;
	for (int i = 0; i < 5; i++)
	{
		if (this->Buttons[i])
		{
			ButtonIndex = i;
		}
	}
	return ButtonIndex;
}
