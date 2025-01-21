#include "Application.hpp"

void Application::Run(HINSTANCE hInstance, int nCmdShow)
{
	SetupHelper setup;
	if (!setup.SetupWindow(hInstance, nCmdShow))
	{
		throw std::runtime_error("Failed to setup Window");
	}
	
	MSG msg = {};

	while (!(GetAsyncKeyState(VK_ESCAPE) & 0x8000) && msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}
