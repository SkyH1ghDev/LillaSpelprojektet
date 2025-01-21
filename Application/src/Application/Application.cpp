#include "Application.hpp"

void Application::Setup(HINSTANCE hInstance, int nCmdShow) 
{
	SetupHelper setup;
	D3D11_VIEWPORT viewport;
	HWND window;

	ID3D11Device* device;
	ID3D11DeviceContext* immediateContext;
	IDXGISwapChain* swapChain;

	ID3D11Texture2D* dsTexture;
	ID3D11DepthStencilView* dsView;
	ID3D11RenderTargetView* rtv;


	if (!setup.SetupWindow(hInstance, nCmdShow, window))
	{
		throw std::runtime_error("Failed to setup Window");
	}

	if (!setup.SetupInterfaces(device, immediateContext, swapChain, 720, 560, window))
	{
		throw std::runtime_error("Failed to setup Interfaces");
	}

	if (!setup.SetupDepthStencil(device, 720, 560, dsTexture, dsView))
	{
		throw std::runtime_error("Failed to setup Depth Stencil View");
	}

	if (!setup.SetupRenderTargetView(device, swapChain, rtv))
	{
		throw std::runtime_error("Failed to setup Render Target View");
	}

	setup.SetViewport(viewport, 720, 560);
}

void Application::Run(HINSTANCE hInstance, int nCmdShow)
{
	Setup(hInstance, nCmdShow);

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
