#pragma once

#include <SpEngine/Setup/SetupHelper.hpp>
#include <SpEngine/Manager/AssetManager.hpp>
#include <SpEngine/Assets/IScene.hpp>

#include <d3d11.h>
#include <directxtk/SpriteBatch.h>
#include <DirectXMath.h>
#include <wrl/client.h>

namespace MW = Microsoft::WRL;
namespace DX = DirectX;

class Renderer
{
public:
	Renderer(HWND& window);
	~Renderer();

	MW::ComPtr<ID3D11BlendState> GetBlendState();
	MW::ComPtr<ID3D11SamplerState> GetSamplerState();
	MW::ComPtr<ID3D11RasterizerState> GetRasterState();

	MW::ComPtr<ID3D11Device> GetDevice();
	MW::ComPtr<ID3D11DeviceContext> GetContext();
	MW::ComPtr<ID3D11RenderTargetView> GetRTV();
	MW::ComPtr<IDXGISwapChain> GetSwapChain();

	/**
	 * Draw using a scene
	 *
	 * @param[IN] mainScene IScene
	 */
	void DrawScene(const std::shared_ptr<IScene>& mainScene);

	/**
	 * Draw using a scene
	 *
	 * @param[IN] mainScene IScene
	 */
	void Draw(const std::shared_ptr<IScene>& mainScene);

	/**
	 * Emxperementing with draw, for testing purposes NOT application
	 *
	 * @param[IN] textureString std string
	 * @param[IN] position DirectX11 XMFLOAT2
	 * @param[IN] color DirectX11 FXMVECTOR
	 * @param[OUT] rendered image
	 */
	void ExperimentalDraw(std::string textureString, const DX::XMFLOAT2& position, DX::FXMVECTOR color);

	/**
	 * Emxperementing with hitbox stuff
	 * 
	 */
	void DrawHitBoxes(std::vector<std::shared_ptr<IGameObject>>& ObjectVec);

private:
	/**
	 * Big draw function for a more detailed spritebatch draw call
	 *
	 * @param[IN] texture DirectX11 ShaderResourceView
	 * @param[IN] position DirectX11 XMFLOAT2
	 * @param[IN] sourceRectangle DirectX11 RECT*
	 * @param[IN] color DirectX11 FXMVECTOR
	 * @param[IN] rotation DirectX11 float
	 * @param[IN] origin DirectX11 XMFLOAT2
	 * @param[IN] scale DirectX11 float
	 * @param[IN] effects DirectX11 SpriteEffects
	 * @param[IN] layerDepth DirectX11 float
	 */
	void DrawTexture(
		ID3D11ShaderResourceView* texture,
		const DX::XMFLOAT2& position,
		const RECT* sourceRectangle,
		DX::FXMVECTOR color = DX::Colors::White,
		float rotation = 0.0f,
		const DX::XMFLOAT2& origin = DX::XMFLOAT2(0, 0),
		float scale = 1.0f,
		DX::DX11::SpriteEffects effects = DX::DX11::SpriteEffects_None,
		float layerDepth = 0.0f);

	/**
	 * Small draw function for a less detailed spritebatch draw call
	 *
	 * @param[IN] texture DirectX11 ShaderResourceView
	 * @param[IN] position DirectX11 XMFLOAT2
	 * @param[IN] color DirectX11 FXMVECTOR
	 */
	void DrawTexture(ID3D11ShaderResourceView* texture, const DX::XMFLOAT2& position, DX::FXMVECTOR color);

	void InitializeBlendState();
	void InitializeSamplerState();
	void InitializeRasterState();

	/**
	 * Does the final things before rendering
	 */
	void FinalBindings();
	void SetupPipeline(HWND& window);
	void SetupImGui(HWND& window, const MW::ComPtr<ID3D11Device>& device, const MW::ComPtr<ID3D11DeviceContext>& context);

private:
	MW::ComPtr<ID3D11BlendState> m_blendState;
	MW::ComPtr<ID3D11SamplerState> m_samplerState;
	MW::ComPtr<ID3D11RasterizerState> m_rasterState;

	MW::ComPtr<ID3D11Device> m_device;
	MW::ComPtr<ID3D11DeviceContext> m_immediateContext;
	MW::ComPtr<IDXGISwapChain> m_swapChain;
	MW::ComPtr<ID3D11Texture2D> m_dsTexture;
	MW::ComPtr<ID3D11DepthStencilView> m_dsView;
	MW::ComPtr<ID3D11RenderTargetView> m_rtv;
	D3D11_VIEWPORT m_viewport;

	int m_width = 640;
	int m_height = 360;
	SetupHelper m_setup;
	std::unique_ptr<DX::DX11::SpriteBatch> m_spriteBatch;
};


inline MW::ComPtr<ID3D11BlendState> Renderer::GetBlendState()
{
	return this->m_blendState;
}

inline MW::ComPtr<ID3D11SamplerState> Renderer::GetSamplerState()
{
	return this->m_samplerState;
}

inline MW::ComPtr<ID3D11RasterizerState> Renderer::GetRasterState()
{
	return this->m_rasterState;
}

inline MW::ComPtr<ID3D11Device> Renderer::GetDevice()
{
	return this->m_device;
}

inline MW::ComPtr<ID3D11DeviceContext> Renderer::GetContext()
{
	return this->m_immediateContext;
}

inline MW::ComPtr<ID3D11RenderTargetView> Renderer::GetRTV()
{
	return this->m_rtv;
}

inline MW::ComPtr<IDXGISwapChain> Renderer::GetSwapChain()
{
	return this->m_swapChain;
}
