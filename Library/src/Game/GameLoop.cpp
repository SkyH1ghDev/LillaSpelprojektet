#include "GameLoop.hpp"

#include <SpEngine/Manager/SceneManager.hpp>
#include <SpEngine/Manager/AssetManager.hpp>
#include <SpEngine/Manager/GameObjectManager.hpp>

#include <SpEngine/Input/Mouse.hpp>
#include <SpEngine/Input/Keyboard.hpp>
#include <SpEngine/Input/KeyAction/ExitHandler.hpp>

#include <SpEngine/Renderer/Renderer.hpp>

#include <SpEngine/Clock/Clock.hpp>


//Setup function handling all initialisation of resources
void GameLoop::Setup(HINSTANCE hInstance, int nCmdShow, MW::ComPtr<ID3D11Device>& device, MW::ComPtr<ID3D11DeviceContext>& immediateContext, MW::ComPtr<IDXGISwapChain>& swapChain,
	MW::ComPtr<ID3D11Texture2D>& dsTexture, MW::ComPtr<ID3D11DepthStencilView>& dsView, MW::ComPtr<ID3D11RenderTargetView>& rtv, D3D11_VIEWPORT &viewport, const UINT &width, const UINT &height, HWND &window)
{
	m_setup.Setup(hInstance, nCmdShow, window, device, immediateContext, swapChain, dsTexture, dsView, rtv, width, height);
	m_setup.SetViewport(width, height, viewport);

	m_imGui = ImGuiTool(window, device, immediateContext);
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

	std::unique_ptr<DX::DX11::SpriteBatch> spriteBatch = std::make_unique<DX::DX11::SpriteBatch>(immediateContext.Get());

	Mouse mi;

	float clearColour[4] = { 0, 0, 0, 0 };

	Keyboard keyboard;

	Clock clock;

	std::shared_ptr<ExitHandler> exitHandler = std::make_shared<ExitHandler>();

	keyboard.GetKey(VK_ESCAPE)->Attach(std::static_pointer_cast<IObserver, ExitHandler>(exitHandler));

	std::shared_ptr<IScene> mainScene = SceneManager::GetScene("main");

	// OnStart for all GameObjects

	for (const auto& gameObject : GameObjectManager::GetGameObjects())
	{
		gameObject->OnStart();
	}

	//Render- / main application loop
	//May want to change the condition to a bool variable
	while (!exitHandler->ShouldExit())
	{
		clock.Start();

		mi.Update(window);

		keyboard.HandleInput();

		// Update for all GameObjects

		for (const auto& gameObject : GameObjectManager::GetGameObjects())
		{
			gameObject->Update();
		}

		immediateContext->RSSetViewports(1, &viewport);
		immediateContext->OMSetRenderTargets(1, rtv.GetAddressOf(), dsView.Get());
		immediateContext->ClearRenderTargetView(rtv.Get(), clearColour);

		//Running ImGui and all their windows
		m_imGui.Start();
		m_imGui.Run(immediateContext, rtv, mi);
		m_imGui.End();

		spriteBatch->Begin(DX::DX11::SpriteSortMode_Texture, renderer.GetBlendState().Get(), renderer.GetSamplerState().Get(), nullptr, renderer.GetRasterState().Get(), nullptr, DX::XMMatrixIdentity());
		//Temporary sprite drawing code goes here
		renderer.DrawTexture(spriteBatch, ass.GetSprite("Toe.png").GetSRV().Get(), DX::XMFLOAT2(mi.GetMousePositionX(), mi.GetMousePositionX()), DX::Colors::White);
		//
		spriteBatch->End();


		swapChain->Present(0, 0);

		clock.End();

		std::cerr << clock.GetFrameRate() << " FPS\n";
	}

	m_imGui.Shutdown();
	DestroyWindow(window);
}
