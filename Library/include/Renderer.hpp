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

	void InitializeRenderer(MW::ComPtr<ID3D11Device>& device);
	void SetBlendState(MW::ComPtr<ID3D11DeviceContext>& immediateContext);
	MW::ComPtr<ID3D11BlendState> GetBlendState();

public:

private:
	void InitializeBlendState(MW::ComPtr<ID3D11Device>& device);
	void InitializeSamplerState(MW::ComPtr<ID3D11Device>& device);

private:
	MW::ComPtr<ID3D11BlendState> m_blendState;
	MW::ComPtr<ID3D11SamplerState> m_samplerState;
};