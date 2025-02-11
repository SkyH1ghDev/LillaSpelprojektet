#include "ImGuiNew.hpp"

#include <iostream>
#include <SpEngine/Clock/Clock.hpp>
#include <SpEngine/Input/Input.hpp>
#include <ImGui/imgui.h>
#include <ImGui/imgui_impl_dx11.h>
#include <ImGui/imgui_impl_win32.h>


ImGuiNew::~ImGuiNew()
{
	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
}


void ImGuiNew::Initialize(const HWND& window, const MW::ComPtr<ID3D11Device>& device, const MW::ComPtr<ID3D11DeviceContext>& context)
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableSetMousePos;

    RECT windowRect;
    GetClientRect(window, &windowRect);

    io.DeltaTime = Clock::GetDeltaTime();

	ImGui::StyleColorsDark();

	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(device.Get(), context.Get());

	io.DisplaySize = {640, 360};
	io.WantSetMousePos = true;
}

void ImGuiNew::Start()
{
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
}

void ImGuiNew::Run()
{
	ImGui::Begin("Test");
	ImGui::Text("Hello World");
	ImGui::End();

	ImGuiIO& io = ImGui::GetIO();

	io.MousePos = ImVec2(Input::GetMousePositionX(), Input::GetMousePositionY());
	io.MouseDown[0] = GetAsyncKeyState(VK_LBUTTON) & 0x8000;
	io.MouseDown[1] = GetAsyncKeyState(VK_RBUTTON) & 0x8000;

	std::cout << io.MousePos.x << ", " << io.MousePos.y << std::endl;
}


void ImGuiNew::End()
{
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}
