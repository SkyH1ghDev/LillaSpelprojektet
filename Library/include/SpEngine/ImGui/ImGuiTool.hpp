#pragma once

#include <d3d11.h>
#include <wrl/client.h>
#include <SpEngine/Input/Mouse.hpp>

namespace MW = Microsoft::WRL;

class ImGuiTool
{
public:
	ImGuiTool();
	ImGuiTool(HWND window, MW::ComPtr<ID3D11Device>& device, MW::ComPtr<ID3D11DeviceContext>& immediateContext);
	~ImGuiTool();
	ImGuiTool(const ImGuiTool& other) = delete;
	ImGuiTool& operator=(const ImGuiTool& other) = delete;
	ImGuiTool(ImGuiTool&& other) = default;
	ImGuiTool& operator=(ImGuiTool&& other) = default;

	void Start();
	void End();
	void Run(MW::ComPtr<ID3D11DeviceContext>& immediateContext, MW::ComPtr<ID3D11RenderTargetView> rtv, const Mouse& mi);
	void Shutdown();

private:
	void Initialized(HWND window, MW::ComPtr<ID3D11Device>& device, MW::ComPtr<ID3D11DeviceContext>& immediateContext);
	void MouseUpdate(const Mouse& mi);
	void Test(MW::ComPtr<ID3D11DeviceContext>& immediateContext, MW::ComPtr<ID3D11RenderTargetView> rtv);

private:
	bool initialized = false;
};
