#include <iostream>
#include "Renderer.hpp"

Renderer::Renderer(MW::ComPtr<ID3D11Device>& device)
{
	this->InitializeBlendState(device);
	this->InitializeSamplerState(device);
	this->InitializeRasterState(device);
}

Renderer::~Renderer()
{
}

MW::ComPtr<ID3D11BlendState> Renderer::GetBlendState()
{
	return this->m_blendState;
}

MW::ComPtr<ID3D11SamplerState> Renderer::GetSamplerState()
{
	return this->m_samplerState;
}

MW::ComPtr<ID3D11RasterizerState> Renderer::GetRasterState()
{
	return this->m_rasterState;
}

void Renderer::DrawTexture(std::unique_ptr<DX::SpriteBatch>& spriteBatch, ID3D11ShaderResourceView* texture, const DX::XMFLOAT2& position, const RECT* sourceRectangle, DX::FXMVECTOR color, float rotation, const DX::XMFLOAT2& origin, float scale, DX::DX11::SpriteEffects effects, float layerDepth)
{
	spriteBatch->Draw(texture, position, sourceRectangle, color, rotation, origin, scale, effects, layerDepth);
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

	HRESULT hr = device->CreateBlendState(&BlendState, &blendStateCpy);
	if (FAILED(hr))
	{
		throw std::runtime_error("Failed to create blend state!");
	}

	this->m_blendState.Attach(blendStateCpy);
}

void Renderer::InitializeSamplerState(MW::ComPtr<ID3D11Device>& device)
{
	//Creating samplerstate with default stuff
	ID3D11SamplerState* samplerStateCpy;

	D3D11_SAMPLER_DESC samplerDesc;
	samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR; // Smooth scaling and rotation
	samplerDesc.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP; // Clamp to edges of texture
	samplerDesc.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
	samplerDesc.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP; // Not used in 2D, but just safe to set anyway
	samplerDesc.MipLODBias = 0;
	samplerDesc.MaxAnisotropy = 1;
	samplerDesc.ComparisonFunc = D3D11_COMPARISON_NEVER; // Not relevant for SpriteBatch
	samplerDesc.BorderColor[0] = 0;
	samplerDesc.BorderColor[1] = 0;
	samplerDesc.BorderColor[2] = 0;
	samplerDesc.BorderColor[3] = 0;
	samplerDesc.MinLOD = 0;
	samplerDesc.MaxLOD = D3D11_FLOAT32_MAX;

	HRESULT hr = device->CreateSamplerState(&samplerDesc, &samplerStateCpy);
	if (FAILED(hr))
	{
		throw std::runtime_error("Failed to create sampler state!");
	}

	this->m_samplerState.Attach(samplerStateCpy);
}

void Renderer::InitializeRasterState(MW::ComPtr<ID3D11Device>& device)
{
	//Creating rasterstate with default stuff
	ID3D11RasterizerState* rasterStateCpy;

	D3D11_RASTERIZER_DESC rasterDesc;
	rasterDesc.FillMode = D3D11_FILL_SOLID;	//Render normally (no wireframe)
	rasterDesc.CullMode = D3D11_CULL_NONE;	//sprites are coublesided => no culling
	rasterDesc.FrontCounterClockwise = false;	//standard
	rasterDesc.DepthBias = 0;
	rasterDesc.DepthClipEnable = true;	//Clip pixels outside depth range
	rasterDesc.ScissorEnable = false;	//Set TRUE if using scissor rectangles (we dont)

	HRESULT hr = device->CreateRasterizerState(&rasterDesc, &rasterStateCpy);
	if (FAILED(hr))
	{
		throw std::runtime_error("Failed to create raster state!");
	}

	this->m_rasterState.Attach(rasterStateCpy);
}
