#include "mouseInput.hpp"

mouseInput::mouseInput(HWND hWnd)
{
	this->hWnd = hWnd;
	ZeroMemory(this->buttons, sizeof(this->buttons));
}

void mouseInput::update()
{
	float point = GetCursorPos(&this->mousePos);
	ScreenToClient(this->hWnd, &this->mousePos);
}

float mouseInput::getMousePositionX()
{
	return this->mousePos.x;
}

float mouseInput::getMousePositionY()
{
	return this->mousePos.y;
}

bool mouseInput::IsButtonPressed(int buttonIndex) const
{
	if (buttonIndex < 0 || buttonIndex > 5) {
		return false;
	}
	return this->buttons[buttonIndex];
}

void mouseInput::UpdateButtons()
{
	this->buttons[0] = (GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0;
	this->buttons[1] = (GetAsyncKeyState(VK_RBUTTON) & 0x8000) != 0;
	this->buttons[2] = (GetAsyncKeyState(VK_MBUTTON) & 0x8000) != 0;
	this->buttons[3] = (GetAsyncKeyState(VK_XBUTTON1) & 0x8000) != 0;
	this->buttons[4] = (GetAsyncKeyState(VK_XBUTTON2) & 0x8000) != 0;
}
