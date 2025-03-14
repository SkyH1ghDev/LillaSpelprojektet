#if defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#endif

#define WIN32_LEAN_AND_MEAN

#include <crtdbg.h>
#include <Windows.h>
#include <SpEngine/Game/GameLoop.hpp>

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                      _In_opt_ HINSTANCE hPrevInstance,
                      _In_ LPWSTR    lpCmdLine,
                      _In_ int       nCmdShow)
{
	#if defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	#endif
	
	// Braces to let the application go out of scope before checking memory leaks
	{
		GameLoop application;
		application.Run(hInstance, nCmdShow);
	}

	return 0;
}
