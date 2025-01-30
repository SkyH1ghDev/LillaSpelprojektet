#pragma once
#include <Windows.h>

class  Mouse {
public:
	Mouse();
	~Mouse() = default;

	void Update(HWND &hWnd);
	inline float GetMousePositionX();
	inline float GetMousePositionY();
	bool IsButtonPressed(int buttonIndex) const;
	int AnyButton();
	
private:
	POINT MousePos;
	bool Buttons[5];
	
	void UpdateButtons();
	
};

inline float Mouse::GetMousePositionX()
{
	GetCursorPos(&this->MousePos);
	return this->MousePos.x;
}

inline float Mouse::GetMousePositionY()
{
	GetCursorPos(&this->MousePos);
	return this->MousePos.y;
}