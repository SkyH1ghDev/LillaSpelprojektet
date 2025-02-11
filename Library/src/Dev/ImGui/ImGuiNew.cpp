#include "ImGuiNew.hpp"

#include <SpEngine/Clock/Clock.hpp>
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

    RECT windowRect;
    GetClientRect(window, &windowRect);

    int width = windowRect.right - windowRect.left;
    int height = windowRect.bottom - windowRect.top;

    io.DisplaySize = ImVec2(static_cast<float>(width), static_cast<float>(height));
    io.DeltaTime = Clock::GetDeltaTime();

    float scaleX = 640.0f / static_cast<float>(windowRect.right);
    float scaleY = 360.0f / static_cast<float>(windowRect.bottom);

    io.DisplayFramebufferScale = ImVec2(scaleX, scaleY);

	ImGui::StyleColorsDark();

	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(device.Get(), context.Get());
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
}


void ImGuiNew::End()
{
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}
