#pragma once

#include <Windows.h>
#include <d3d11.h>
#include <wrl/client.h>

namespace MW = Microsoft::WRL;

class Renderer
{
public:
	Renderer() = default;
	~Renderer();

	void InitializeBlendState(MW::ComPtr<ID3D11Device>& device);
	void SetBlendState(MW::ComPtr<ID3D11DeviceContext>& immediateContext);
	MW::ComPtr<ID3D11BlendState> GetBlendState();

private:
	MW::ComPtr<ID3D11BlendState> r_blendState;
};