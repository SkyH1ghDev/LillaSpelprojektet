#include "StaticSprite.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>
#include <array>


StaticSprite::StaticSprite(const MW::ComPtr<ID3D11Device>& device)
{
	ID3D11ShaderResourceView* srvCpy;
	ID3D11Texture2D* texture;

	constexpr int textureHeight = 128, textureWidth = 128, rgbaChannels = 4, textureSize = textureHeight * textureWidth * rgbaChannels;

	std::array<std::byte, textureSize> imageData;
	std::memset(imageData.data(), 255, textureSize * sizeof(std::byte));

	m_sourceRect = std::make_shared<RECT>();
	m_sourceRect->left = 0;
	m_sourceRect->right = textureWidth;
	m_sourceRect->top = 0;
	m_sourceRect->bottom = textureHeight;

	m_origin = DX::XMFLOAT2(static_cast<float>(textureWidth) / 2, static_cast<float>(textureHeight) / 2);

	D3D11_TEXTURE2D_DESC texture2DDesc;
	texture2DDesc.Width = textureWidth;
	texture2DDesc.Height = textureHeight;
	texture2DDesc.MipLevels = 1;
	texture2DDesc.ArraySize = 1;
	texture2DDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	texture2DDesc.SampleDesc = DXGI_SAMPLE_DESC{ 1, 0 };
	texture2DDesc.Usage = D3D11_USAGE_IMMUTABLE;
	texture2DDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
	texture2DDesc.CPUAccessFlags = 0;
	texture2DDesc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA texture2DData;
	texture2DData.pSysMem = imageData.data();
	texture2DData.SysMemPitch = textureWidth * rgbaChannels;
	texture2DData.SysMemSlicePitch = 0;

	if (FAILED(device->CreateTexture2D(&texture2DDesc, &texture2DData, &texture)))
	{
		throw("Failed to create Texture");
	}

	HRESULT hr = device->CreateShaderResourceView(texture, nullptr, &srvCpy);

	m_srv.Attach(srvCpy);

	texture->Release();

	if (FAILED(hr))
		throw("Failed to create Texture Shader Resource View");
}

StaticSprite::StaticSprite(const MW::ComPtr<ID3D11Device>& device, const std::string& filepath)
{
	ID3D11ShaderResourceView* srvCpy;
	ID3D11Texture2D* texture;

	int textureHeight, textureWidth, rgbaChannels;

	unsigned char* imageData = stbi_load(filepath.c_str(), &textureWidth, &textureHeight, &rgbaChannels, 0);

	rgbaChannels = 4;

	m_sourceRect = std::make_shared<RECT>();
	m_sourceRect->left = 0;
	m_sourceRect->right = textureWidth;
	m_sourceRect->top = 0;
	m_sourceRect->bottom = textureHeight;

	m_origin = DX::XMFLOAT2(static_cast<float>(textureWidth) / 2, static_cast<float>(textureHeight) / 2);

	D3D11_TEXTURE2D_DESC texture2DDesc;
	texture2DDesc.Width = textureWidth;
	texture2DDesc.Height = textureHeight;
	texture2DDesc.MipLevels = 1;
	texture2DDesc.ArraySize = 1;
	texture2DDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	texture2DDesc.SampleDesc = DXGI_SAMPLE_DESC{ 1, 0 };
	texture2DDesc.Usage = D3D11_USAGE_IMMUTABLE;
	texture2DDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
	texture2DDesc.CPUAccessFlags = 0;
	texture2DDesc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA texture2DData;
	texture2DData.pSysMem = imageData;
	texture2DData.SysMemPitch = textureWidth * rgbaChannels;
	texture2DData.SysMemSlicePitch = 0;

	if (FAILED(device->CreateTexture2D(&texture2DDesc, &texture2DData, &texture)))
	{
		stbi_image_free(imageData);
		throw("Failed to create Texture");
	}

	HRESULT hr = device->CreateShaderResourceView(texture, nullptr, &srvCpy);

	stbi_image_free(imageData);
	m_srv.Attach(srvCpy);

	texture->Release();

	if (FAILED(hr))
		throw("Failed to create Texture Shader Resource View");
}

StaticSprite::StaticSprite(const MW::ComPtr<ID3D11Device>& device, const APNG::frame& frame)
{
	ID3D11ShaderResourceView* srvCpy;
	ID3D11Texture2D* texture;

	int rgbaChannels = 4, textureWidth = frame.image.width(), textureHeight = frame.image.height();
	const std::uint8_t* imageData = frame.image.data();

	m_sourceRect = std::make_shared<RECT>();
	m_sourceRect->left = 0;
	m_sourceRect->right = textureWidth;
	m_sourceRect->top = 0;
	m_sourceRect->bottom = textureHeight;

	m_origin = DX::XMFLOAT2(static_cast<float>(textureWidth) / 2, static_cast<float>(textureHeight) / 2);

	D3D11_TEXTURE2D_DESC texture2DDesc;
	texture2DDesc.Width = textureWidth;
	texture2DDesc.Height = textureHeight;
	texture2DDesc.MipLevels = 1;
	texture2DDesc.ArraySize = 1;
	texture2DDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	texture2DDesc.SampleDesc = DXGI_SAMPLE_DESC{ 1, 0 };
	texture2DDesc.Usage = D3D11_USAGE_IMMUTABLE;
	texture2DDesc.BindFlags = D3D11_BIND_SHADER_RESOURCE;
	texture2DDesc.CPUAccessFlags = 0;
	texture2DDesc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA texture2DData;
	texture2DData.pSysMem = imageData;
	texture2DData.SysMemPitch = textureWidth * rgbaChannels;
	texture2DData.SysMemSlicePitch = 0;

	if (FAILED(device->CreateTexture2D(&texture2DDesc, &texture2DData, &texture)))
	{
		throw("Failed to create Texture");
	}

	HRESULT hr = device->CreateShaderResourceView(texture, nullptr, &srvCpy);

	m_srv.Attach(srvCpy);

	texture->Release();

	if (FAILED(hr))
		throw("Failed to create Texture Shader Resource View");
}
