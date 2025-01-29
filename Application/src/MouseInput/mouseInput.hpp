#pragma once
#include <Windows.h>

class mouseInput {
public:
	mouseInput(HWND hWnd);
	~mouseInput() = default;

	void update();
	float getMousePositionX();
	float getMousePositionY();
	bool IsButtonPressed(int buttonIndex) const;
	int Anybutton();
	
private:
	POINT mousePos;
	HWND hWnd;
	bool buttons[5];
	
	void UpdateButtons();
	
};