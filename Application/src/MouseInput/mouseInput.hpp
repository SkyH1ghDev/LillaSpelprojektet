#pragma once
#include <Windows.h>
#include <d3d11.h>
#include <wrl/client.h>
class mouseInput {
public:
	mouseInput(HWND hWnd);
	~mouseInput() = default;

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