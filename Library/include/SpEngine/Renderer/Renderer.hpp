#pragma once

#include <SpEngine/Setup/SetupHelper.hpp>

#include <SpEngine/Dev/ImGui/ImGuiTool.hpp>
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

	void DrawScene(const std::shared_ptr<IScene>& mainScene);

	void ExperimentalDraw(std::string textureString, const DX::XMFLOAT2& position, DX::FXMVECTOR color);

private:
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

	void DrawTexture(ID3D11ShaderResourceView* texture, const DX::XMFLOAT2& position, DX::FXMVECTOR color);

	void InitializeBlendState();
	void InitializeSamplerState();
	void InitializeRasterState();

	void FinalBindings();
	void SetupPipeline(HWND& window);
	void ImGui();

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
	AssetManager m_assetMan;
	std::unique_ptr<DX::DX11::SpriteBatch> m_spriteBatch;

	ImGuiTool m_imGui;
};