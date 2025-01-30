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

inline float Mouse::GetMousePositionX()
{
	GetCursorPos(&this->m_mousePos);
	return this->m_mousePos.x;
}

inline float Mouse::GetMousePositionY()
{
	GetCursorPos(&this->m_mousePos);
	return this->m_mousePos.y;
}
