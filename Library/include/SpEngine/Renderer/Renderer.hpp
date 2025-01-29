#pragma once

#include <d3d11.h>
#include <directxtk/SpriteBatch.h>
#include <DirectXMath.h>
#include <wrl/client.h>

namespace MW = Microsoft::WRL;
namespace DX = DirectX;

class Renderer
{
public:
	Renderer(MW::ComPtr<ID3D11Device>& device);
	~Renderer();

	MW::ComPtr<ID3D11BlendState> GetBlendState();
	MW::ComPtr<ID3D11SamplerState> GetSamplerState();
	MW::ComPtr<ID3D11RasterizerState> GetRasterState();

	void DrawTexture(	std::unique_ptr<DX::SpriteBatch>& spriteBatch, 
						ID3D11ShaderResourceView* texture, 
						const DX::XMFLOAT2& position, 
						const RECT* sourceRectangle, 
						DX::FXMVECTOR color = DX::Colors::White, 
						float rotation = 0.0f, 
						const DX::XMFLOAT2& origin = DX::XMFLOAT2(0, 0),
						float scale = 1.0f,
						DX::DX11::SpriteEffects effects = DX::DX11::SpriteEffects_None, 
						float layerDepth = 0.0f);


	void DrawTexture(std::unique_ptr<DX::SpriteBatch>& spriteBatch, ID3D11ShaderResourceView* texture, const DX::XMFLOAT2& position, DX::FXMVECTOR color);

private:
	void InitializeBlendState(MW::ComPtr<ID3D11Device>& device);
	void InitializeSamplerState(MW::ComPtr<ID3D11Device>& device);
	void InitializeRasterState(MW::ComPtr<ID3D11Device>& device);

private:
	MW::ComPtr<ID3D11BlendState> m_blendState;
	MW::ComPtr<ID3D11SamplerState> m_samplerState;
	MW::ComPtr<ID3D11RasterizerState> m_rasterState;
};