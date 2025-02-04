#include <windows.h>
#include <wrl/client.h>

namespace MW = Microsoft::WRL;

class Window
{
public:
	Window() = default;
	Window(const HINSTANCE& instance, const int& nCmdShow, const UINT& width, const UINT& height);
	~Window() = default;
	
	inline HWND& GetWindowHandle();
	inline UINT GetWidth();
	inline UINT GetHeight();
private:
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	HWND m_window;
	UINT m_width;
	UINT m_height;
};

HWND& Window::GetWindowHandle() 
{
	return this->m_window;
}

UINT Window::GetWidth()
{
	return this->m_width;
}

UINT Window::GetHeight()
{
	return this->m_height;
}

