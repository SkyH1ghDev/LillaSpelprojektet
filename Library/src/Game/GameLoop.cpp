#include "GameLoop.hpp"

#include <SpEngine/Manager/SceneManager.hpp>
#include <SpEngine/Manager/AssetManager.hpp>
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

	m_imGui = ImGuiTool(window, device, immediateContext);
}

void GameLoop::SetupImGui(MW::ComPtr<ID3D11Device>& device, MW::ComPtr<ID3D11DeviceContext>& immediateContext, HWND& window)
{
	m_imGui = ImGuiTool(window, device, immediateContext);
}

//Extension of Main
void GameLoop::Run(HINSTANCE hInstance, int nCmdShow)
{
	Window window = Window(hInstance, nCmdShow, 640, 360);

	Renderer renderer = Renderer(window.GetWindowHandle());
	MW::ComPtr<ID3D11Device> device = renderer.GetDevice();
	MW::ComPtr<ID3D11DeviceContext> immediateContext = renderer.GetContext();
	MW::ComPtr<ID3D11RenderTargetView> rtv = renderer.GetRTV();

	SetupImGui(device, immediateContext, window.GetWindowHandle());

	AssetManager ass;
	ass.ReadFolder(device, "../Application/Resources");

	Clock clock;

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
		clock.Start();

		Input::HandleInput(window.GetWindowHandle());

		// Update for all GameObjects

		for (const auto& gameObject : GameObjectManager::GetGameObjects())
		{
			gameObject->Update();
		}

		//Running ImGui and all their windows
		m_imGui.Start();
		m_imGui.Run(immediateContext, rtv);
		m_imGui.End();
		std::vector<std::shared_ptr<IGameObject>> ObjectVec = mainScene->GetGameObjectVec();

		renderer.DrawTexture(ass.GetSprite(ObjectVec.at(0)->GetTextureString()).GetSRV().Get(), DX::XMFLOAT2(ObjectVec.at(0)->GetPosition().x, ObjectVec.at(0)->GetPosition().y), DX::Colors::White);

		clock.End();

		//std::cerr << clock.GetFrameRate() << " FPS\n";
	}

	m_imGui.Shutdown();
	DestroyWindow(window.GetWindowHandle());
}
