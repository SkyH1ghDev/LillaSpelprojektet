#pragma once
#include <Windows.h>

class  Mouse {
public:
	Mouse(HWND hWnd);
	~Mouse() = default;

	void Update();
	float GetMousePositionX();
	float GetMousePositionY();
	bool IsButtonPressed(int buttonIndex) const;
	int AnyButton();
	
private:
	POINT MousePos;
	HWND hWnd;
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