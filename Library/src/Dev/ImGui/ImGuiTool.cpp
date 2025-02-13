#include "ImGuiTool.hpp"

#include <imgui/imgui.h>
#include <imgui/imgui_impl_win32.h>
#include <imgui/imgui_impl_dx11.h>

#include <SpEngine/Input/Input.hpp>

#include <iostream>

ImGuiTool::ImGuiTool()
{
}

ImGuiTool::ImGuiTool(const HWND& window, const MW::ComPtr<ID3D11Device>& device, const MW::ComPtr<ID3D11DeviceContext>& immediateContext)
{
	if (!this->m_initialized) {
		Initialized(window, device, immediateContext);
		this->m_initialized = true;
	}
}

ImGuiTool::~ImGuiTool()
{
}

void ImGuiTool::Start(const MW::ComPtr<ID3D11DeviceContext>& immediateContext, const MW::ComPtr<ID3D11BlendState>& blendState)
{
	float clearColour[4] = { 0.0f, 0.0f, 0.0f, 0.0f };

	immediateContext->OMSetBlendState(blendState.Get(), clearColour, 0xffffffff);
	immediateContext->ClearRenderTargetView(this->m_rtv.Get(), clearColour);
	immediateContext->OMSetRenderTargets(1, this->m_rtv.GetAddressOf(), nullptr);

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
	ImGui::ShowDemoWindow();
}

void ImGuiTool::End()
{
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}

void ImGuiTool::Run(const MW::ComPtr<ID3D11DeviceContext>& immediateContext, const MW::ComPtr<ID3D11RenderTargetView>& rtv)
{


	MouseUpdate();
	Test(immediateContext, rtv);
}


void ImGuiTool::Shutdown()
{
	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
}

//Initializes the ImGui
void ImGuiTool::Initialized(const HWND& window, const MW::ComPtr<ID3D11Device>& device, const MW::ComPtr<ID3D11DeviceContext>& immediateContext)
{
	D3D11_TEXTURE2D_DESC desc;
	ZeroMemory(&desc, sizeof(desc));
	desc.Width = 1920;
	desc.Height = 1080;
	desc.MipLevels = 1;
	desc.ArraySize = 1;
	desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	desc.SampleDesc.Count = 1;
	desc.Usage = D3D11_USAGE_DEFAULT;
	desc.BindFlags = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;

	HRESULT hr = device->CreateTexture2D(&desc, nullptr, &this->m_texture);

	if (FAILED(hr))
	{
		throw std::exception("Failed to create texture");
	}

	D3D11_RENDER_TARGET_VIEW_DESC rtvDesc;
	ZeroMemory(&rtvDesc, sizeof(rtvDesc));
	rtvDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	rtvDesc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
	rtvDesc.Texture2D.MipSlice = 0;

	hr = device->CreateRenderTargetView(m_texture.Get(), &rtvDesc, &this->m_rtv);

	if (FAILED(hr))
	{
		throw std::exception("Failed to create render target");
	}

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
void ImGuiTool::MouseUpdate()
{

	// TODO: MAKE BETTER :)
	ImGuiIO& io = ImGui::GetIO();
	io.MouseDown[0] = GetAsyncKeyState(VK_LBUTTON) & 0x8000 ? true : false;
	io.MouseDown[1] = GetAsyncKeyState(VK_RBUTTON) & 0x8000 ? true : false;
}

//Creates a window with a text toggle and a background color changer
void ImGuiTool::Test(const MW::ComPtr<ID3D11DeviceContext>& immediateContext, const MW::ComPtr<ID3D11RenderTargetView>& rtv)
{
	ImGui::SetNextWindowPos(ImVec2(0, 0));  //Window Position
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

	ImGui::End();
}
