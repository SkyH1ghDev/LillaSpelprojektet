#include "Renderer.hpp"

#include <SpEngine/Assets/Game/IGameObject.hpp>
#include <SpEngine/Dev/ImGui/ImGuiTool.hpp>

Renderer::Renderer(HWND& window)
{
	SetupPipeline(window);
	SetupImGui(window, this->m_device, this->m_immediateContext);
	this->m_spriteBatch = std::make_unique<DX::DX11::SpriteBatch>(this->m_immediateContext.Get());
	
	AssetManager::InitializeAudioEngine();
	AssetManager::ReadFolder(this->m_device, "../Application/Resources/Assets");
	AssetManager::ReadAnimations(this->m_device, "../Application/Resources/Animations");

	this->InitializeBlendState();
	this->InitializeSamplerState();
	this->InitializeRasterState();
}

Renderer::~Renderer()
{
	ImGuiTool::Shutdown();
}

void Renderer::DrawScene(const std::shared_ptr<IScene>& sceneToRender)
{
	this->m_spriteBatch->Begin(DX::DX11::SpriteSortMode_FrontToBack, this->m_blendState.Get(), this->m_samplerState.Get(), nullptr, this->m_rasterState.Get(), nullptr, DX::XMMatrixIdentity());
	
	std::vector<std::shared_ptr<IGameObject>> ObjectVec = sceneToRender->GetGameObjectVec();
	int len = ObjectVec.size();
	FinalBindings();

	for (int i = 0; i < len; i++)
	{
		std::shared_ptr<IGameObject> gameObj = ObjectVec.at(i);
		
		if (gameObj->ShouldRender())
		{
			//this->DrawTexture(this->m_assetMan.GetSprite(ObjectVec.at(i)->GetTextureString()).GetSRV().Get(), ObjectVec.at(i)->GetPosition(), DX::Colors::White);

			std::string textureFilepath = gameObj->GetTextureString();
			std::shared_ptr<StaticSprite> sprite = AssetManager::GetSprite(textureFilepath, gameObj->GetAnimationTime());
			
			DX::XMFLOAT2 origin = DX::XMFLOAT2(0, 0);
			DX::XMFLOAT2 originOffset = gameObj->GetOriginOffset();
			
			if (gameObj->IsOriginCentered())
			{
				origin = sprite->GetOrigin();
			}

			origin.x += originOffset.x;
			origin.y += originOffset.y;
			DrawTexture
			(
				sprite->GetSRV().Get(),
				gameObj->GetPosition(),
				sprite->GetSourceRectangle().get(),
				DX::Colors::White,
				gameObj->GetRotationFloat(),
				origin,
				gameObj->GetScaleFloat(),
				DX::DX11::SpriteEffects_None,
				gameObj->GetLayerFloat()
			);
		}
	}

	//this->DrawHitBoxes(ObjectVec);

	this->m_spriteBatch->End();
}

void Renderer::Draw(const std::shared_ptr<IScene>& mainScene)
{
	ImGuiTool::Start();

	DrawScene(mainScene);

	ImGuiTool::Run();
	ImGuiTool::End();

	this->m_swapChain->Present(0, 0);
}

//Debug function
void Renderer::ExperimentalDraw(std::string textureString, const DX::XMFLOAT2& position, DX::FXMVECTOR color)
{
	this->m_spriteBatch->Begin(DX::DX11::SpriteSortMode_Texture, this->m_blendState.Get(), this->m_samplerState.Get(), nullptr, this->m_rasterState.Get(), nullptr, DX::XMMatrixIdentity());
	FinalBindings();
	DrawTexture(AssetManager::GetSprite(textureString, 0)->GetSRV().Get(), position, color);
	this->m_spriteBatch->End();

	this->m_swapChain->Present(0, 0);
}

//Debug function
void Renderer::DrawHitBoxes(std::vector<std::shared_ptr<IGameObject>>& ObjectVec)
{
	int len = ObjectVec.size();
	for (int i = 0; i < len; i++)
	{
		std::shared_ptr<IGameObject> gameObj = ObjectVec.at(i);
		
		if (gameObj->ShouldRender())
		{
			
			std::string textureFilepath = gameObj->GetTextureString();
			std::shared_ptr<StaticSprite> sprite = AssetManager::GetSprite(textureFilepath, 0);
			
			if (ObjectVec.at(i)->GetCollider() != nullptr)
			{
				Collider col = *ObjectVec.at(i)->GetCollider();
				std::vector<DX::XMFLOAT2> positions;
				
				positions.push_back({ col.GetPosition().x, col.GetPosition().y - col.GetRadiusY() });
				positions.push_back({ col.GetPosition().x, col.GetPosition().y + col.GetRadiusY() });
				positions.push_back({ col.GetPosition().x - col.GetRadiusX(), col.GetPosition().y });
				positions.push_back({ col.GetPosition().x + col.GetRadiusX(), col.GetPosition().y });

				positions.push_back({ col.GetPosition().x + col.GetRadiusX() / 1.41f, col.GetPosition().y + col.GetRadiusY() / 1.41f });
				positions.push_back({ col.GetPosition().x + col.GetRadiusX() / 1.41f, col.GetPosition().y - col.GetRadiusY() / 1.41f });
				positions.push_back({ col.GetPosition().x - col.GetRadiusX() / 1.41f, col.GetPosition().y + col.GetRadiusY() / 1.41f });
				positions.push_back({ col.GetPosition().x - col.GetRadiusX() / 1.41f, col.GetPosition().y - col.GetRadiusY() / 1.41f });

				for (int i = 0; i < positions.size(); i++)
				{
					this->DrawTexture
					(
						AssetManager::GetSprite("hitPixel", 0)->GetSRV().Get(),
						positions.at(i),
						AssetManager::GetSprite("hitPixel.png", 0)->GetSourceRectangle().get(),
						DX::Colors::Gold, ObjectVec.at(i)->GetRotationFloat(),
						{ 0, 0 },
						2.0f,
						DX::DX11::SpriteEffects_None,
						1.0f)
					;
				}
			}
		}
	}
}

void Renderer::DrawTexture(ID3D11ShaderResourceView* texture, const DX::XMFLOAT2& position, const RECT* sourceRectangle, DX::FXMVECTOR color, float rotation, const DX::XMFLOAT2& origin, float scale, DX::DX11::SpriteEffects effects, float layerDepth)
{
	this->m_spriteBatch->Draw(texture, position, sourceRectangle, color, rotation, origin, scale, effects, layerDepth);
}

void Renderer::DrawTexture(ID3D11ShaderResourceView* texture, const DX::XMFLOAT2& position, DX::FXMVECTOR color)
{
	this->m_spriteBatch->Draw(texture, position, color);
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
	BlendState.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_MAX; /* Changed from D3D11_BLEND_OP_ADD */
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
	samplerDesc.Filter = D3D11_FILTER_MIN_MAG_MIP_POINT; // Smooth scaling and rotation
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

void Renderer::SetupImGui(HWND& window, const MW::ComPtr<ID3D11Device>& device, const MW::ComPtr<ID3D11DeviceContext>& context)
{
	ImGuiTool::Initialize(window, device, context);
}
