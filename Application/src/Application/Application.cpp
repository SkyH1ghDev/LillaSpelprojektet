#include "Application.hpp"

//Setup function handling all initialisation of resources
void Application::Setup(HINSTANCE hInstance, int nCmdShow, ID3D11Device*& device, ID3D11DeviceContext*& immediateContext,
	IDXGISwapChain*& swapChain, ID3D11Texture2D*& dsTexture, ID3D11DepthStencilView*& dsView, ID3D11RenderTargetView*& rtv)
{
	SetupHelper setup;
	D3D11_VIEWPORT viewport;
	HWND window;

	setup.Setup(hInstance, nCmdShow, window, device, immediateContext, swapChain, dsTexture, dsView, rtv);

	setup.SetViewport(viewport, 720, 560);
}

//Extension of Main
void Application::Run(HINSTANCE hInstance, int nCmdShow)
{
	ID3D11Device* device;
	ID3D11DeviceContext* immediateContext;
	IDXGISwapChain* swapChain;

	ID3D11Texture2D* dsTexture;
	ID3D11DepthStencilView* dsView;
	ID3D11RenderTargetView* rtv;

	Setup(hInstance, nCmdShow, device, immediateContext, swapChain, dsTexture, dsView, rtv);

	MSG msg = {};


	//Render- / main application loop
	//May want to change the condition to a bool variable
	while (!(GetAsyncKeyState(VK_ESCAPE) & 0x8000) && msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		swapChain->Present(0, 0);
	}

	device->Release();
	immediateContext->Release();
	swapChain->Release();
	dsTexture->Release();
	dsView->Release();
	rtv->Release();
}
