#include <iostream>
#include "Renderer.hpp"

Renderer::~Renderer()
{
}



void Renderer::SetBlendState(MW::ComPtr<ID3D11DeviceContext>& immediateContext)
{
	float blendFactor[4] = {0.0f, 0.0f , 0.0f ,0.0f};
	immediateContext.Get()->OMSetBlendState(m_blendState.Get(), blendFactor, 0xFFFFFFFF);
}

MW::ComPtr<ID3D11BlendState> Renderer::GetBlendState()
{
	return this->m_blendState;
}

void Renderer::InitializeBlendState(MW::ComPtr<ID3D11Device>& device)
{
	//Creating blendstate with default stuff
	ID3D11BlendState* blendStateCpy;

	D3D11_BLEND_DESC BlendState;
	ZeroMemory(&BlendState, sizeof(BlendState));
	BlendState.RenderTarget[0].BlendEnable = true;	//Enable blenging
	BlendState.RenderTarget[0].SrcBlend = D3D11_BLEND_SRC_ALPHA;	//Use source alpha
	BlendState.RenderTarget[0].DestBlend = D3D11_BLEND_INV_SRC_ALPHA; //Use 1 - source alpha
	BlendState.RenderTarget[0].BlendOp = D3D11_BLEND_OP_ADD;	//Add source and destination
	BlendState.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;    // No blending for alpha
	BlendState.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;  // Keep alpha as is
	BlendState.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
	BlendState.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;

	HRESULT hr = device.Get()->CreateBlendState(&BlendState, &blendStateCpy);
	if (FAILED(hr))
	{
		throw std::runtime_error("Failed to create blend state!");
	}

	this->m_blendState.Attach(blendStateCpy);
}
