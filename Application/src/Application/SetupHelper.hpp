#include <Windows.h>
#include <iostream>

class SetupHelper
{
public:
	bool SetupWindow(HINSTANCE instance, int nCmdShow);

private:
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};