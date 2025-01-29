#include <directxtk/SpriteBatch.h>
#include "GameLoop.hpp"
#include "texture.hpp"
#include "SceneManager.hpp"

//Setup function handling all initialisation of resources
void GameLoop::Setup(HINSTANCE hInstance, int nCmdShow, MW::ComPtr<ID3D11Device>& device, MW::ComPtr<ID3D11DeviceContext>& immediateContext, MW::ComPtr<IDXGISwapChain>& swapChain,
	MW::ComPtr<ID3D11Texture2D>& dsTexture, MW::ComPtr<ID3D11DepthStencilView>& dsView, MW::ComPtr<ID3D11RenderTargetView>& rtv, D3D11_VIEWPORT &viewport, const UINT &width, const UINT &height, HWND &window)
{
	SetupHelper setup;

	setup.Setup(hInstance, nCmdShow, window, device, immediateContext, swapChain, dsTexture, dsView, rtv, width, height);

	setup.SetViewport(width, height, viewport);
}

//Extension of Main
void GameLoop::Run(HINSTANCE hInstance, int nCmdShow)
{
	MW::ComPtr<ID3D11Device> device;
	MW::ComPtr<ID3D11DeviceContext> immediateContext;
	MW::ComPtr<IDXGISwapChain> swapChain;

	MW::ComPtr<ID3D11Texture2D> dsTexture;
	MW::ComPtr<ID3D11DepthStencilView> dsView;
	MW::ComPtr<ID3D11RenderTargetView> rtv;
	

	HWND window;
	D3D11_VIEWPORT viewport;

	int initWidth = 1280;
	int initHeight = 720;

	Setup(hInstance, nCmdShow, device, immediateContext, swapChain, dsTexture, dsView, rtv, viewport, initWidth, initHeight, window);

	Renderer renderer = Renderer(device);

	ShaderResourceTexture toe(device.Get(), "../Application/Resources/Toe.png");

	std::unique_ptr<DX::DX11::SpriteBatch> spriteBatch;
	spriteBatch = std::make_unique<DX::DX11::SpriteBatch>(immediateContext.Get());

	MSG msg = {};

	ID3D11RenderTargetView* rtvCpy = rtv.Get();
	//Render- / main application loop
	//May want to change the condition to a bool variable
	while (!(GetAsyncKeyState(VK_ESCAPE) & 0x8000) && msg.message != WM_QUIT)
	{

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		immediateContext->RSSetViewports(1, &viewport);
		immediateContext->OMSetRenderTargets(1, &rtvCpy, dsView.Get());

		spriteBatch->Begin(DX::DX11::SpriteSortMode_Texture, renderer.GetBlendState().Get(), renderer.GetSamplerState().Get(), nullptr, renderer.GetRasterState().Get(), nullptr, DX::XMMatrixIdentity());
		spriteBatch->End();

		swapChain->Present(0, 0);

	}

	DestroyWindow(window);
}
