#pragma once

#include <d3d11.h>
#include <wrl/client.h>

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
