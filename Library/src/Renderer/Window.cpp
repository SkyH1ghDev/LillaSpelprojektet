#include <SpEngine/Renderer/Window.hpp>
#include <iostream>

LRESULT CALLBACK Window::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	// sort through and find what code to run for the message given
	switch (message)
	{
		// this message is read when the window is closed
	case WM_DESTROY:
	{
		// close the application entirely
		PostQuitMessage(0);
		return 0;
	}
	default:
		break;
	}

	// Handle any messages the switch statement didn't by using default methodology
	return DefWindowProc(hWnd, message, wParam, lParam);
}

Window::Window(const HINSTANCE& instance, const int& nCmdShow, const UINT& width, const UINT& height) {
	const wchar_t CLASS_NAME[] = L"Test Window Class";

	WNDCLASS wc = { };

	wc.lpfnWndProc = WindowProc;
	wc.hInstance = instance;
	wc.lpszClassName = CLASS_NAME;

	m_width = width;
	m_height = height;

	RegisterClass(&wc);

	this->m_window = CreateWindowEx(0, CLASS_NAME, L"Jonas Krymp", WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX,
		CW_USEDEFAULT, 0, m_width, m_height, nullptr, nullptr, instance, nullptr);

	if (this->m_window == nullptr)
	{
		throw "HWND was nullptr, last error: " + GetLastError();
	}

	ShowWindow(this->m_window, nCmdShow);
}