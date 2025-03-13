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
	m_game.SetupGame();
	Window window = Window(hInstance, nCmdShow, 1920, 1080);
	ShowCursor(FALSE);
	Renderer renderer = Renderer(window.GetWindowHandle());

	//std::shared_ptr<ExitHandler> exitHandler = std::make_shared<ExitHandler>();

	//Input::GetKey(VK_ESCAPE)->Attach(std::static_pointer_cast<IObserver, ExitHandler>(exitHandler));

	ExitHandler exitHandler;

	Sound::SetMusic("menu_theme.wav", 0.4f);
	Sound::PlayMusic(true);

	// OnStart for all GameObjects

	for (const auto& gameObject : GameObjectManager::GetGameObjects())
	{
		gameObject->OnStart();
	}

	LoadIntro(window, renderer);

	SceneManager::LoadScene("main");

	//Render- / main application loop
	//May want to change the condition to a bool variable
	while (!exitHandler.ShouldExit())
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

		//std::cerr << clock.GetFrameRate() << " FPS\n";
	}
	AssetManager::ResetAudioEngine();
	DestroyWindow(window.GetWindowHandle());
	
}

void GameLoop::LoadIntro(Window window, Renderer& renderer)
{
	SceneManager::LoadScene("intro");
	std::shared_ptr<IScene> currentScene = SceneManager::GetCurrentScene();
	for (int i = 1; i < currentScene->GetGameObjectVec().size(); i++)
	{
		currentScene->GetGameObjectVec()[i]->SetShouldRender(false);
	}
	float time = 0;


	while (true) {
		Clock::Start();
		Input::HandleInput(window.GetWindowHandle());
		std::shared_ptr<IScene> currentScene = SceneManager::GetCurrentScene();
		renderer.Draw(currentScene);
		time += Clock::GetDeltaTime();

		//Transition1
		if (time > 2) {
			currentScene->GetGameObjectVec()[0]->SetShouldRender(false);
			currentScene->GetGameObjectVec()[10]->SetShouldRender(true);
		}
		if (time > 2.1) {
			currentScene->GetGameObjectVec()[10]->SetShouldRender(false);
			currentScene->GetGameObjectVec()[11]->SetShouldRender(true);
		}
		if (time > 5) {
			currentScene->GetGameObjectVec()[11]->SetShouldRender(false);
			currentScene->GetGameObjectVec()[10]->SetShouldRender(true);
		}

		//Scene1
		if (time > 5.1) {
			currentScene->GetGameObjectVec()[10]->SetShouldRender(false);
			currentScene->GetGameObjectVec()[3]->SetShouldRender(true);
		}
		if (time > 8) {
			currentScene->GetGameObjectVec()[3]->SetShouldRender(false);
			currentScene->GetGameObjectVec()[1]->SetShouldRender(true);
		}
		if (time > 8.1) {
			currentScene->GetGameObjectVec()[1]->SetShouldRender(false);
			currentScene->GetGameObjectVec()[4]->SetShouldRender(true);
		}

		//Transition2
		if (time > 11) {
			currentScene->GetGameObjectVec()[4]->SetShouldRender(false);
			currentScene->GetGameObjectVec()[10]->SetShouldRender(true);
		}
		if (time > 11.1) {
			currentScene->GetGameObjectVec()[10]->SetShouldRender(false);
			currentScene->GetGameObjectVec()[12]->SetShouldRender(true);
		}
		if (time > 14) {
			currentScene->GetGameObjectVec()[12]->SetShouldRender(false);
			currentScene->GetGameObjectVec()[10]->SetShouldRender(true);
		}

		//Scene2
		if (time > 14.1) {
			currentScene->GetGameObjectVec()[10]->SetShouldRender(false);
			currentScene->GetGameObjectVec()[5]->SetShouldRender(true);
		}
		if (time > 17) {
			currentScene->GetGameObjectVec()[5]->SetShouldRender(false);
			currentScene->GetGameObjectVec()[2]->SetShouldRender(true);
		}
		if (time > 17.1) {
			currentScene->GetGameObjectVec()[2]->SetShouldRender(false);
			currentScene->GetGameObjectVec()[6]->SetShouldRender(true);
		}
		if (time > 20) {
			currentScene->GetGameObjectVec()[6]->SetShouldRender(false);
			currentScene->GetGameObjectVec()[2]->SetShouldRender(true);
		}
		if (time > 20.1) {
			currentScene->GetGameObjectVec()[2]->SetShouldRender(false);
			currentScene->GetGameObjectVec()[7]->SetShouldRender(true);
		}
		if (time > 23) {
			currentScene->GetGameObjectVec()[7]->SetShouldRender(false);
			currentScene->GetGameObjectVec()[2]->SetShouldRender(true);
		}
		if (time > 23.1) {
			currentScene->GetGameObjectVec()[2]->SetShouldRender(false);
			currentScene->GetGameObjectVec()[8]->SetShouldRender(true);
		}
		if (time > 26) {
			currentScene->GetGameObjectVec()[8]->SetShouldRender(false);
			currentScene->GetGameObjectVec()[2]->SetShouldRender(true);
		}
		if (time > 26.1) {
			currentScene->GetGameObjectVec()[2]->SetShouldRender(false);
			currentScene->GetGameObjectVec()[9]->SetShouldRender(true);
		}

		//Transition3
		if (time > 29) {
			currentScene->GetGameObjectVec()[9]->SetShouldRender(false);
			currentScene->GetGameObjectVec()[10]->SetShouldRender(true);
		}
		if (time > 29.1) {
			currentScene->GetGameObjectVec()[10]->SetShouldRender(false);
			currentScene->GetGameObjectVec()[13]->SetShouldRender(true);
		}
		if (time > 32) {
			currentScene->GetGameObjectVec()[13]->SetShouldRender(false);
			currentScene->GetGameObjectVec()[10]->SetShouldRender(true);
		}
		if (time > 32.1) {
			currentScene->GetGameObjectVec()[10]->SetShouldRender(false);
			currentScene->GetGameObjectVec()[14]->SetShouldRender(true);
		}

		if (time > 35)
			break;

		std::bitset<4> skip = Input::GetKey(VK_SPACE)->GetKeyState();
		if (skip == 1100)
			break;

		Clock::End();
	}
	Clock::End();
	SceneManager::UnloadScene();
}
