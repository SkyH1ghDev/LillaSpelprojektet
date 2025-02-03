#pragma once
#include <Windows.h>

class Mouse {
public:
	Mouse();
	~Mouse() = default;

	void Update(HWND &hWnd);
	inline float GetMousePositionX();
	inline float GetMousePositionY();
	bool IsButtonPressed(int buttonIndex) const;
	int AnyButton();

private:
	POINT m_mousePos;
	bool m_buttons[5];

	void UpdateButtons();

};

inline float Mouse::GetMousePositionX() //gets the x cordinate of the mouse
{
	GetCursorPos(&this->m_mousePos); //can be optimized away maybe, with just update before getting
	return this->m_mousePos.x;
}

inline float Mouse::GetMousePositionY()
{
	GetCursorPos(&this->m_mousePos); //gets the y cordinate of the mouse
	return this->m_mousePos.y;
}
