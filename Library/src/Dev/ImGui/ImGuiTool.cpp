#include "ImGuiTool.hpp"
#include "ImGuiHelper.hpp"
#include "ImGuiKeyBindButton.hpp"

#include <psapi.h>
#include <SpEngine/Clock/Clock.hpp>
#include <SpEngine/Input/Input.hpp>
#include <ImGui/imgui.h>
#include <ImGui/imgui_impl_dx11.h>
#include <ImGui/imgui_impl_win32.h>

#include <SpEngine/Manager/AssetManager.hpp>

#include "SceneManager.hpp"


void ImGuiTool::Initialize(const HWND& window, const MW::ComPtr<ID3D11Device>& device, const MW::ComPtr<ID3D11DeviceContext>& context)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
	io.ConfigViewportsNoAutoMerge = true;

    RECT windowRect;
    GetClientRect(window, &windowRect);

    io.DeltaTime = Clock::GetDeltaTime();

	ImGui::StyleColorsDark();

	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(device.Get(), context.Get());
}

void ImGuiTool::Start()
{
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
}

void ImGuiTool::Run()
{
	ImGuiIO& io = ImGui::GetIO();

	if (io.WantCaptureMouse)
	{
		io.MouseDrawCursor = true;
	}
	else
	{
		io.MouseDrawCursor = false;
	}

	io.MouseDown[0] = GetAsyncKeyState(VK_LBUTTON) & 0x8000;
	io.MouseDown[1] = GetAsyncKeyState(VK_RBUTTON) & 0x8000;

	ImGui::ShowDemoWindow();

	// Windows
	ImGuiTabBarFlags mainTabBarFlags = ImGuiTabBarFlags_None;

	ImGui::BeginTabBar("main", mainTabBarFlags);

	if (ImGui::BeginTabItem("AssetManager"))
	{
		AssetManagerTab();
		ImGui::EndTabItem();
	}

	if (ImGui::BeginTabItem("SceneManager"))
	{
		SceneManagerTab();
		ImGui::EndTabItem();
	}

	if (ImGui::BeginTabItem("Statistics"))
	{
		StatisticsTab();
		ImGui::EndTabItem();
	}

	if (ImGui::BeginTabItem("Keyboard & Mouse"))
	{
		KeyBindTab();
		ImGui::EndTabItem();
	}

	ImGui::EndTabBar();


}


void ImGuiTool::End()
{
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());


	ImGui::UpdatePlatformWindows();
	ImGui::RenderPlatformWindowsDefault();
}

void ImGuiTool::Shutdown()
{
	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
}

void ImGuiTool::AssetManagerTab()
{
	constexpr int columnWidth = 128;
	int columnsPerRow = static_cast<int>(ImGui::GetContentRegionAvail().x / columnWidth);

	if (columnsPerRow <= 0)
	{
		return;
	}

	ImGui::BeginTable("test", columnsPerRow);

	std::unordered_map<std::string, std::shared_ptr<ISprite>> texMap = AssetManager::GetTextureMap();

	int rows = std::ceil(static_cast<float>(texMap.size()) / columnsPerRow);

	std::vector<std::string> texMapKeys;
	texMapKeys.reserve(texMap.size());
	std::vector<std::shared_ptr<ISprite>> texMapVals;
	texMapVals.reserve(texMap.size());

	for (auto kv : texMap)
	{
		texMapKeys.push_back(kv.first);
		texMapVals.push_back(kv.second);
	}

	int itemsToDisplay = texMap.size();

	for (int i = 0; i < rows; ++i)
	{
		ImGui::TableNextRow();

		int columns = itemsToDisplay < columnsPerRow ? itemsToDisplay : columnsPerRow;
		for (int j = 0; j < columns; ++j)
		{
			const int columnRowIndex = j + i * columnsPerRow;
			const std::string filename = texMapKeys[columnRowIndex];

			std::shared_ptr<ISprite> sprite = texMapVals[columnRowIndex];
			std::shared_ptr<AnimatedSprite> animatedSprite = std::dynamic_pointer_cast<AnimatedSprite, ISprite>(sprite);

			ImTextureID fileTexture;
			if (animatedSprite == nullptr)
			{
				fileTexture = ImTextureID(std::static_pointer_cast<StaticSprite, ISprite>(sprite)->GetSRV().Get());
			}
			else
			{
				fileTexture = ImTextureID(animatedSprite->GetSprite()->GetSRV().Get());
			}
			
			ImGui::TableSetColumnIndex(j);
			ImGui::Text(filename.c_str());
			ImGui::Image(fileTexture, ImVec2(columnWidth, columnWidth));
			if (ImGui::IsItemHovered(ImGuiHoveredFlags_DelayNone))
			{
				ImGui::SetTooltip(filename.c_str());
			}
		}

		itemsToDisplay -= columns;
	}
	ImGui::EndTable();
}

void ImGuiTool::SceneManagerTab()
{
	std::vector<std::shared_ptr<IScene>> scenes = SceneManager::GetAllScenes();
	static std::vector<std::shared_ptr<IGameObject>> gameObjects = {};

	static int sceneSelectedIndex = 0;
	
	if (scenes.size() <= 0)
	{
		sceneSelectedIndex = 0;
		return;
	}

	static std::string scenePreviewText = "Select Scene...";
	if (ImGui::BeginCombo("Scenes", scenePreviewText.c_str(), ImGuiComboFlags_None))
	{
		for (int i = 0; i < scenes.size(); ++i)
		{
			const bool isSelected = (sceneSelectedIndex == i);

			if (ImGui::Selectable(scenes[i]->GetName().c_str(), isSelected))
			{
				sceneSelectedIndex = i;
			}

			if (isSelected)
			{
				scenePreviewText = scenes[i]->GetName();
				gameObjects = scenes[i]->GetGameObjectVec();
				ImGui::SetItemDefaultFocus();
			}
		}
		ImGui::EndCombo();
	}

	static int gameObjSelectedIndex = 0;

	if (gameObjects.size() <= 0)
	{
		gameObjSelectedIndex = 0;
		return;
	}
	
	static std::string gameObjectPreviewText = "Select GameObject...";
	if (ImGui::BeginCombo("GameObjects", gameObjectPreviewText.c_str(), ImGuiComboFlags_None))
	{
		for (int i = 0; i < gameObjects.size(); ++i)
		{
			const bool isSelected = (gameObjSelectedIndex == i);

			if (ImGui::Selectable(gameObjects.at(i)->GetName().c_str(), isSelected))
			{
				gameObjSelectedIndex = i;
			}

			if (isSelected)
			{
				gameObjectPreviewText = gameObjects.at(i)->GetName() + "##" + std::to_string(gameObjects.at(i)->GetUID());
				ImGui::SetItemDefaultFocus();
			}
		}
		ImGui::EndCombo();
	}

	std::shared_ptr<IGameObject> selectedGameObject = gameObjects.at(gameObjSelectedIndex);
	
	ImGui::Separator();
	ImGui::NewLine();

	std::string positionText = "Position: " + std::to_string(selectedGameObject->GetPosition().x) + ", " + std::to_string(selectedGameObject->GetPosition().y);
	ImGui::Text(positionText.c_str());
}

void ImGuiTool::StatisticsTab()
{
	if (ImGui::CollapsingHeader("Performance"))
	{

		// FPS
		ImGui::SeparatorText("Framerate");

		std::string fpsText = "FPS: " + std::to_string(ImGui::GetIO().Framerate);
		ImGui::Text(fpsText.c_str());

		std::string frameTimeText = "Frame Time: " + std::to_string(ImGui::GetIO().DeltaTime);
		ImGui::Text(frameTimeText.c_str());


		// Memory
		ImGui::SeparatorText("Memory");

		MEMORYSTATUSEX memInfo = {};
		memInfo.dwLength = sizeof(memInfo);
		GlobalMemoryStatusEx(&memInfo);
		DWORDLONG totalPhysMem = memInfo.ullTotalPhys;

		std::string totalPhysicalMemoryText = "Total Physical Memory: " + std::to_string(std::round(static_cast<float>(totalPhysMem) / (1024.0f * 1024.0f * 1024.0f) * 100.0f) / 100.0f) + " GB";
		ImGui::Text(totalPhysicalMemoryText.c_str());

		DWORDLONG totalUsedPhysMem = memInfo.ullTotalPhys - memInfo.ullAvailPhys;

		std::string totalUsedPhysicalMemoryText = "Total Used Physical Memory: " + std::to_string(std::round(static_cast<float>(totalUsedPhysMem) / (1024.0f * 1024.0f * 1024.0f) * 100.0f) / 100.0f) + " GB";
		ImGui::Text(totalUsedPhysicalMemoryText.c_str());

		static std::queue<float> totalPhysMemUsedQueue = {};
		totalPhysMemUsedQueue.push(static_cast<float>(totalUsedPhysMem));

		if (totalPhysMemUsedQueue.size() > 60)
		{
			totalPhysMemUsedQueue.pop();
		}

		std::queue<float> totalPhysMemUsedQueueCopy = totalPhysMemUsedQueue;
		std::vector<float> totalPhysMemUsedVec = {};
		while (totalPhysMemUsedQueueCopy.size() > 0)
		{
			totalPhysMemUsedVec.push_back(totalPhysMemUsedQueueCopy.front());
			totalPhysMemUsedQueueCopy.pop();
		}

		ImGui::PlotLines("Total Used Memory", totalPhysMemUsedVec.data(), 60, 0, nullptr, 0, 16, ImVec2(250, 50));

		PROCESS_MEMORY_COUNTERS_EX pmc;
		GetProcessMemoryInfo(GetCurrentProcess(), (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
		SIZE_T appUsedPhysMem = pmc.PrivateUsage;

		std::string appUsedPhysicalMemoryText = "Applicalication Used Physical Memory: " + std::to_string(std::round(static_cast<float>(appUsedPhysMem) / (1024.0f * 1024.0f * 1024.0f) * 100.0f) / 100.0f) + " GB";
		ImGui::Text(appUsedPhysicalMemoryText.c_str());

		static std::queue<float> appPhysMemUsedQueue = {};
		appPhysMemUsedQueue.push(static_cast<float>(appUsedPhysMem));

		if (appPhysMemUsedQueue.size() > 60)
		{
			appPhysMemUsedQueue.pop();
		}

		std::queue<float> appPhysMemUsedQueueCopy = appPhysMemUsedQueue;
		std::vector<float> appPhysMemUsedVec = {};
		while (appPhysMemUsedQueueCopy.size() > 0)
		{
			appPhysMemUsedVec.push_back(appPhysMemUsedQueueCopy.front());
			appPhysMemUsedQueueCopy.pop();
		}

		ImGui::PlotLines("Application Used Memory", appPhysMemUsedVec.data(), 60, 0, nullptr, 0, 16, ImVec2(250, 50));
	}

	if (ImGui::CollapsingHeader("Mouse"))
	{
		ImGuiIO& io = ImGui::GetIO();

		std::string mousePosText = "Mouse Position: (" + std::to_string(io.MousePos.x) + ", " + std::to_string(io.MousePos.y) + ")";
		ImGui::Text(mousePosText.c_str());

		std::string translatedMousePosText = "Translated Mouse Position: (" + std::to_string(io.MousePos.x / 3) + ", " + std::to_string(io.MousePos.y / 3) + ")";
		ImGui::Text(translatedMousePosText.c_str());
	}
}

void ImGuiTool::KeyBindTab()
{
	
	//
	// TODO: ADD THE FUNCTIONALITY FOR IT TO ACTUALLY ATTACH AND DETACH ACTIONS
	//
	
	static std::vector<ImGuiKeyBindButton> keyBindButtons =
		{
			// Movement
			{"W", "Walk Forward", ImGuiKey_W}, {"A", "Walk Left", ImGuiKey_A}, {"S", "Walk Back", ImGuiKey_S}, {"D", "Walk Right", ImGuiKey_D}
		};
	
	for (ImGuiKeyBindButton& button : keyBindButtons)
	{
		if (ImGui::Button((button.GetKeyName() + "##" + button.GetActionName()).c_str(), ImVec2(150, 20)))
		{
			button.SetPressedState(true);
			button.SetKeyName("Press any key...");
			button.SetImGuiKey(ImGuiKey_None);
		}
	
		ImGui::SameLine();
		ImGui::Text(button.GetActionName().c_str());
		
		if (button.IsPressed())
		{
			for (int i = ImGuiKey_NamedKey_BEGIN; i < ImGuiKey_NamedKey_END; ++i)
			{
				if (ImGuiHelper::GetBindableKeys().contains(i))
				{
					if (ImGui::IsKeyPressed(static_cast<ImGuiKey>(i)))
					{
						ImGuiKeyWrapper keyWrapper = ImGuiHelper::GetKey(static_cast<ImGuiKey>(i));
						button.SetKeyName(keyWrapper.GetString());
						button.SetPressedState(false);

						/*std::shared_ptr<Key> t = Input::GetKey(keyWrapper.GetVKey());
						t->Attach(); */
					}
				}
			}
    	}	
	}
}
