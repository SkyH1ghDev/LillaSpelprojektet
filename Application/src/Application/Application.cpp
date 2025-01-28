#include "Application.hpp"
#include <directxtk/SpriteBatch.h>
#include "texture.hpp"
#include "SceneManager.hpp"
#include "GameSceneFactory.hpp"

//Setup function handling all initialisation of resources
void Application::Setup(HINSTANCE hInstance, int nCmdShow, MW::ComPtr<ID3D11Device>& device, MW::ComPtr<ID3D11DeviceContext>& immediateContext, MW::ComPtr<IDXGISwapChain>& swapChain,
	MW::ComPtr<ID3D11Texture2D>& dsTexture, MW::ComPtr<ID3D11DepthStencilView>& dsView, MW::ComPtr<ID3D11RenderTargetView>& rtv, D3D11_VIEWPORT &viewport, const UINT &width, const UINT &height, HWND &window)
{
	SetupHelper setup;

	setup.Setup(hInstance, nCmdShow, window, device, immediateContext, swapChain, dsTexture, dsView, rtv, width, height);

	setup.SetViewport(width, height, viewport);
}

//Extension of Main
void Application::Run(HINSTANCE hInstance, int nCmdShow)
{
	MW::ComPtr<ID3D11Device> device;
	MW::ComPtr<ID3D11DeviceContext> immediateContext;
	MW::ComPtr<IDXGISwapChain> swapChain;

	MW::ComPtr<ID3D11Texture2D> dsTexture;
	MW::ComPtr<ID3D11DepthStencilView> dsView;
	MW::ComPtr<ID3D11RenderTargetView> rtv;

	// Step 1: Create a SceneManager instance
	SceneManager sceneManager;

	// Step 2: Register factories for scenes
	sceneManager.registerScene("game_level_1", GameSceneFactory(1)); // Level 1
	sceneManager.registerScene("game_level_2", GameSceneFactory(2)); // Level 2

	try {
		// Step 3: Create and use scenes
		auto scene1 = sceneManager.createScene("game_level_1");
		scene1->display(); // Output: Game Scene - Level: 1

		auto scene2 = sceneManager.createScene("game_level_2");
		scene2->display(); // Output: Game Scene - Level: 2
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}


	HWND window;
	D3D11_VIEWPORT viewport;

	int initWidth = 1280;
	int initHeight = 720;

	Setup(hInstance, nCmdShow, device, immediateContext, swapChain, dsTexture, dsView, rtv, viewport, initWidth, initHeight, window);

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

		spriteBatch->Begin(DX::DX11::SpriteSortMode_Texture, nullptr, nullptr, nullptr, nullptr, nullptr, DX::XMMatrixIdentity());
		toe.DrawTexture(spriteBatch, DX::XMFLOAT2(initWidth / 2,  initHeight / 2));
		spriteBatch->End();

		swapChain->Present(0, 0);

	}

	DestroyWindow(window);
}
