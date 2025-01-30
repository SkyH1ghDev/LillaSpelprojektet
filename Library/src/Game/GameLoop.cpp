#include "GameLoop.hpp"
#include "Scene/Scenes/GameScene.hpp"
#include "Scene/Factories/GameSceneFactories/GameSceneFactory.hpp"

#include <directxtk/SpriteBatch.h>
#include <SpEngine/Manager/SceneManager.hpp>
#include <SpEngine/Input/Mouse.hpp>
#include <SpEngine/Dev/ImGui/ImGuiTool.hpp>
#include <SpEngine/Manager/AssetManager.hpp>
#include <SpEngine/Input/Keyboard.hpp>
#include <SpEngine/Input/Actions/ExitHandler.hpp>



//Setup function handling all initialisation of resources
void GameLoop::Setup(HINSTANCE hInstance, int nCmdShow, MW::ComPtr<ID3D11Device>& device, MW::ComPtr<ID3D11DeviceContext>& immediateContext, MW::ComPtr<IDXGISwapChain>& swapChain,
	MW::ComPtr<ID3D11Texture2D>& dsTexture, MW::ComPtr<ID3D11DepthStencilView>& dsView, MW::ComPtr<ID3D11RenderTargetView>& rtv, D3D11_VIEWPORT &viewport, const UINT &width, const UINT &height, HWND &window)
{
	this->setup.Setup(hInstance, nCmdShow, window, device, immediateContext, swapChain, dsTexture, dsView, rtv, width, height);
	this->setup.SetViewport(width, height, viewport);

	this->imGui = ImGuiTool(window, device, immediateContext);
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

	int initWidth = 640;
	int initHeight = 360;

	Setup(hInstance, nCmdShow, device, immediateContext, swapChain, dsTexture, dsView, rtv, viewport, initWidth, initHeight, window);

	Renderer renderer = Renderer(device);

	AssetManager ass;
	ass.ReadFolder(device, "../Application/Resources");

	std::unique_ptr<DX::DX11::SpriteBatch> spriteBatch;
	spriteBatch = std::make_unique<DX::DX11::SpriteBatch>(immediateContext.Get());

	MSG msg = {};

	Mouse mi;
	SceneManager sceneManager;
	sceneManager.RegisterScene("game_level_1", []() { return GameSceneFactory::CreateScene(1); });
	sceneManager.LoadScene("game_level_1");


	float clearColour[4] = { 0, 0, 0, 0 };

	Keyboard keyboard;

	std::shared_ptr<ExitHandler> exitHandler = std::make_shared<ExitHandler>();

	keyboard.GetKey(VK_ESCAPE)->Attach(std::static_pointer_cast<IObserver, ExitHandler>(exitHandler));

	//Render- / main application loop
	//May want to change the condition to a bool variable
	while (!exitHandler->ShouldExit())
	{
		mi.Update(window);
		sceneManager.Update();

		std::shared_ptr<IScene> currentScene = sceneManager.GetCurrentScene();

		keyboard.HandleInput();

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		immediateContext->RSSetViewports(1, &viewport);
		immediateContext->OMSetRenderTargets(1, rtv.GetAddressOf(), dsView.Get());
		immediateContext->ClearRenderTargetView(rtv.Get(), clearColour);

		//Running ImGui and all their windows
		imGui.Start();
		imGui.Run(immediateContext, rtv, mi);
		imGui.End();

		spriteBatch->Begin(DX::DX11::SpriteSortMode_Texture, renderer.GetBlendState().Get(), renderer.GetSamplerState().Get(), nullptr, renderer.GetRasterState().Get(), nullptr, DX::XMMatrixIdentity());
		//Temporary sprite drawing code goes here

		//
		spriteBatch->End();


		swapChain->Present(0, 0);
	}

	imGui.Shutdown();
	DestroyWindow(window);
}
