#pragma once
#include "SetupHelper.hpp"
class mouseInput {
public:
	mouseInput(HWND hWnd);
	~mouseInput();

	void update();
	float getMousePositionX();
	float getMousePositionY();
	bool IsButtonPressed(int button) const;
	
private:
	POINT mousePos;
	HWND hWnd;
	bool buttons[5];
	
	void UpdateButtons();
};