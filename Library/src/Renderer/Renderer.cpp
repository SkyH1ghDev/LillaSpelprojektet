#include <iostream>
#include "Renderer.hpp"

Renderer::Renderer(HWND& window)
{
	SetupPipeline(window);
	this->m_spriteBatch = std::make_unique<DX::DX11::SpriteBatch>(this->m_immediateContext.Get());
	this->m_assetMan.ReadFolder(this->m_device, "../Application/Resources");
	this->InitializeBlendState();
	this->InitializeSamplerState();
	this->InitializeRasterState();
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

MW::ComPtr<ID3D11Device> Renderer::GetDevice()
{
	return this->m_device;
}

MW::ComPtr<ID3D11DeviceContext> Renderer::GetContext()
{
	return this->m_immediateContext;
}

MW::ComPtr<ID3D11RenderTargetView> Renderer::GetRTV()
{
	return this->m_rtv;
}

void Renderer::DrawTexture(ID3D11ShaderResourceView* texture, const DX::XMFLOAT2& position, const RECT* sourceRectangle, DX::FXMVECTOR color, float rotation, const DX::XMFLOAT2& origin, float scale, DX::DX11::SpriteEffects effects, float layerDepth)
{
	this->m_spriteBatch->Begin(DX::DX11::SpriteSortMode_Texture, this->m_blendState.Get(), this->m_samplerState.Get(), nullptr, this->m_rasterState.Get(), nullptr, DX::XMMatrixIdentity());
	this->FinalBindings();
	this->m_spriteBatch->Draw(texture, position, sourceRectangle, color, rotation, origin, scale, effects, layerDepth);
	this->m_spriteBatch->End();

	this->m_swapChain->Present(0, 0);
}

void Renderer::DrawTexture(ID3D11ShaderResourceView* texture, const DX::XMFLOAT2& position, DX::FXMVECTOR color)
{
	this->m_spriteBatch->Begin(DX::DX11::SpriteSortMode_Texture, this->m_blendState.Get(), this->m_samplerState.Get(), nullptr, this->m_rasterState.Get(), nullptr, DX::XMMatrixIdentity());
	this->FinalBindings();
	this->m_spriteBatch->Draw(texture, position, color);
	this->m_spriteBatch->End();

	this->m_swapChain->Present(0, 0);
}

void Renderer::InitializeBlendState()
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

	HRESULT hr = this->m_device->CreateBlendState(&BlendState, &blendStateCpy);
	if (FAILED(hr))
	{
		throw std::runtime_error("Failed to create blend state!");
	}

	this->m_blendState.Attach(blendStateCpy);
}

void Renderer::InitializeSamplerState()
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

	HRESULT hr = this->m_device->CreateSamplerState(&samplerDesc, &samplerStateCpy);
	if (FAILED(hr))
	{
		throw std::runtime_error("Failed to create sampler state!");
	}

	this->m_samplerState.Attach(samplerStateCpy);
}

void Renderer::InitializeRasterState()
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

	HRESULT hr = this->m_device->CreateRasterizerState(&rasterDesc, &rasterStateCpy);
	if (FAILED(hr))
	{
		throw std::runtime_error("Failed to create raster state!");
	}

	this->m_rasterState.Attach(rasterStateCpy);
}

void Renderer::FinalBindings()
{
	float clearColor[4] = { 0, 0, 0, 0 };
	this->m_immediateContext->RSSetViewports(1, &this->m_viewport);
	this->m_immediateContext->OMSetRenderTargets(1, this->m_rtv.GetAddressOf(), this->m_dsView.Get());
	this->m_immediateContext->ClearRenderTargetView(this->m_rtv.Get(), clearColor);
}

void Renderer::SetupPipeline(HWND& window)
{
	this->m_setup.Setup(window, this->m_device, this->m_immediateContext, this->m_swapChain, this->m_dsTexture, this->m_dsView, this->m_rtv, this->m_width, this->m_height);
	this->m_setup.SetViewport(this->m_width, this->m_height, this->m_viewport);
}
