#define _CRTDBG_MAP_ALLOC
#define WIN32_LEAN_AND_MEAN

#include <crtdbg.h>
#include <Windows.h>
#include "Application.hpp"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                      _In_opt_ HINSTANCE hPrevInstance,
                      _In_ LPWSTR    lpCmdLine,
                      _In_ int       nCmdShow)
{

	// Braces to let the application go out of scope before checking memory leaks
	{
		Application application;
		application.Run();
	}

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();

	return 0;
}
