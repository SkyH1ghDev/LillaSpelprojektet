#include "GameLoop.hpp"

#include <SpEngine/Manager/SceneManager.hpp>
#include <SpEngine/Manager/GameObjectManager.hpp>

#include <SpEngine/Input/Input.hpp>
#include <SpEngine/Input/Action/ExitHandler.hpp>

#include <SpEngine/Clock/Clock.hpp>


//Setup function handling all initialisation of resources
void GameLoop::Setup(HINSTANCE hInstance, int nCmdShow, MW::ComPtr<ID3D11Device>& device, MW::ComPtr<ID3D11DeviceContext>& immediateContext, MW::ComPtr<IDXGISwapChain>& swapChain,
	MW::ComPtr<ID3D11Texture2D>& dsTexture, MW::ComPtr<ID3D11DepthStencilView>& dsView, MW::ComPtr<ID3D11RenderTargetView>& rtv, D3D11_VIEWPORT &viewport, const UINT &width, const UINT &height, HWND &window)
{
	m_setup.Setup(window, device, immediateContext, swapChain, dsTexture, dsView, rtv, width, height);
	m_setup.SetViewport(width, height, viewport);
}

//Extension of Main
void GameLoop::Run(HINSTANCE hInstance, int nCmdShow)
{
	Window window = Window(hInstance, nCmdShow, 1920, 1080);
	ShowCursor(FALSE);
	Renderer renderer = Renderer(window.GetWindowHandle());

	std::shared_ptr<ExitHandler> exitHandler = std::make_shared<ExitHandler>();

	Input::GetKey(VK_ESCAPE)->Attach(std::static_pointer_cast<IObserver, ExitHandler>(exitHandler));

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
		Clock::Start();
		Input::HandleInput(window.GetWindowHandle());

		// Update for all GameObjects

		for (const auto& gameObject : GameObjectManager::GetGameObjects())
		{
			gameObject->Update();
			gameObject->UpdateScripts();
		}
		GameObjectManager::GetGameObjects().at(2)->SetPosition(DX::XMFLOAT2(Input::GetMousePositionX() * 640 / GetSystemMetrics(SM_CXSCREEN), Input::GetMousePositionY() * 360 / GetSystemMetrics(SM_CYSCREEN)));
		renderer.DrawScene(mainScene);
		renderer.DrawImGui();

		Clock::End();

		//std::cerr << clock.GetFrameRate() << " FPS\n";
	}
	DestroyWindow(window.GetWindowHandle());
}
