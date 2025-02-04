#pragma once

#include <d3d11.h>
#include <wrl/client.h>


namespace MW = Microsoft::WRL;

class ImGuiTool
{
public:
	ImGuiTool();
	ImGuiTool(const HWND& window, const MW::ComPtr<ID3D11Device>& device, const MW::ComPtr<ID3D11DeviceContext>& immediateContext);
	~ImGuiTool();
	ImGuiTool(const ImGuiTool& other) = delete;
	ImGuiTool& operator=(const ImGuiTool& other) = delete;
	ImGuiTool(ImGuiTool&& other) = default;
	ImGuiTool& operator=(ImGuiTool&& other) = default;

	void Start();
	void End();
	void Run(const MW::ComPtr<ID3D11DeviceContext>& immediateContext, const MW::ComPtr<ID3D11RenderTargetView>& rtv);
	void Shutdown();

private:
	void Initialized(const HWND& window, const MW::ComPtr<ID3D11Device>& device, const MW::ComPtr<ID3D11DeviceContext>& immediateContext);
	void MouseUpdate();
	void Test(const MW::ComPtr<ID3D11DeviceContext>& immediateContext, const MW::ComPtr<ID3D11RenderTargetView>& rtv);

private:
	bool initialized = false;
};
