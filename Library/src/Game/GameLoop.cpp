#include "GameLoop.hpp"

#include <SpEngine/Manager/SceneManager.hpp>
#include <SpEngine/Manager/GameObjectManager.hpp>

#include <SpEngine/Input/Input.hpp>
#include <SpEngine/Input/Action/ExitHandler.hpp>

#include <SpEngine/Clock/Clock.hpp>

#include <SpEngine/Audio/Sound.hpp>


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

	SceneManager::LoadScene("main");


	Sound::SetMusic("battle_theme_1.wav", 0.4f);
	Sound::PlayMusic(true);

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
		std::shared_ptr<IScene> currentScene = SceneManager::GetCurrentScene();

		// Update for all GameObjects

		for (const auto& gameObject : GameObjectManager::GetGameObjects())
		{
			if (gameObject->IsActive())
			{
				gameObject->Update();
				gameObject->UpdateScripts();
			}
		}

		// Update for Collisions

		renderer.Draw(currentScene);

		

		Clock::End();

		
		timer -= Clock::GetDeltaTime();
		if (timer <= 0)
		{
			SceneManager::UnloadScene();
			SceneManager::LoadScene("secondScene");
			timer2 -= Clock::GetDeltaTime();
			if (timer2 <= 0)
			{
				SceneManager::UnloadScene();
				SceneManager::LoadScene("main");
			}
			
		}
		//std::cerr << clock.GetFrameRate() << " FPS\n";
	}
	AssetManager::ResetAudioEngine();
	DestroyWindow(window.GetWindowHandle());
	

}
