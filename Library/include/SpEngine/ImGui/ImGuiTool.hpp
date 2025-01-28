#pragma once

#include <d3d11.h>
#include <wrl/client.h>

#include <ImGui/imgui.h>
#include <ImGui/backends/imgui_impl_win32.h>
#include <ImGui/backends//imgui_impl_dx11.h>

namespace MW = Microsoft::WRL;


class ImGuiTool 
{
public:
	void Initialize(HWND hWnd, MW::ComPtr<ID3D11Device>& device, MW::ComPtr<ID3D11DeviceContext>& immediateContext);
	void Start();
	void End();
	void Shutdown();

private:
	void Run();
	void Test();
};