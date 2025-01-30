#include <SpEngine/ImGui/ImGuiTool.hpp>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_win32.h>
#include <imgui/imgui_impl_dx11.h>

ImGuiTool::ImGuiTool()
{
}

ImGuiTool::ImGuiTool(HWND window, MW::ComPtr<ID3D11Device>& device, MW::ComPtr<ID3D11DeviceContext>& immediateContext)
{
	if (!this->initialized) {
		Initialized(window, device, immediateContext);
		this->initialized = true;
	}
}

ImGuiTool::~ImGuiTool()
{
}

void ImGuiTool::Start()
{
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
}

void ImGuiTool::End() 
{
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}

void ImGuiTool::Run(MW::ComPtr<ID3D11DeviceContext>& immediateContext, MW::ComPtr<ID3D11RenderTargetView> rtv, const Mouse& mi)
{
	MouseUpdate(mi);
	Test(immediateContext, rtv);
}


void ImGuiTool::Shutdown()
{
	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
}

//Initializes the ImGui
void ImGuiTool::Initialized(HWND window, MW::ComPtr<ID3D11Device>& device, MW::ComPtr<ID3D11DeviceContext>& immediateContext)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	// Setup Platform/Renderer backends
	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(device.Get(), immediateContext.Get());
}

//Updates the mouses presses together with ImGui
void ImGuiTool::MouseUpdate(const Mouse& mi)
{
	ImGuiIO& io = ImGui::GetIO();
	io.MouseDown[0] = mi.IsButtonPressed(0);
	io.MouseDown[1] = mi.IsButtonPressed(1);

}

//Creates a window with a text toggle and a background color changer
void ImGuiTool::Test(MW::ComPtr<ID3D11DeviceContext>& immediateContext, MW::ComPtr<ID3D11RenderTargetView> rtv)
{
	ImGui::SetNextWindowPos(ImVec2(10, 10));  //Window Position
	ImGui::SetNextWindowSize(ImVec2(400, 200));  //Window Size

	ImGui::Begin("ImGuiTool");

	static bool showText = false;

	if (ImGui::Button("Text")) {
		showText = !showText;
	}

	if (showText) {
		ImGui::Text("No Linking Error (yet...)");
	}

	static float color[3] = { 0.0f, 0.0f, 0.0f };
	ImGui::ColorEdit3("Background Color", color);

	immediateContext->ClearRenderTargetView(rtv.Get(), color);
	ImGui::End();

}
