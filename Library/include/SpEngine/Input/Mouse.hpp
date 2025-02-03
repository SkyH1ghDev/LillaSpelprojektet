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
	POINT m_mousePos = POINT(0, 0);
	bool m_buttons[5];

	void UpdateButtons();

};

inline float Mouse::GetMousePositionX() //gets the x cordinate of the mouse
{
	return this->m_mousePos.x;
}

inline float Mouse::GetMousePositionY()
{
	return this->m_mousePos.y;
}
