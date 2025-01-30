#pragma once
#include <SpEngine/Renderer/Sprite.hpp>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

Sprite::Sprite(MW::ComPtr<ID3D11Device> device, std::string filepath)
{
	ID3D11ShaderResourceView* srvCpy;
	ID3D11Texture2D* texture;

	int textureHeight, textureWidth, rgbaChannels;

	unsigned char* imageData = stbi_load(filepath.c_str(), &textureWidth, &textureHeight, &rgbaChannels, 0);

	rgbaChannels = 4;

	m_sourceRect = new RECT();
	m_sourceRect->left = 0;
	m_sourceRect->right = textureWidth;
	m_sourceRect->top = 0;
	m_sourceRect->bottom = textureHeight;

	this->m_origin = DX::XMFLOAT2(textureWidth / 2, textureHeight / 2);

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
	this->m_srv.Attach(srvCpy);

	texture->Release();

	if (FAILED(hr))
		throw("Failed to create Texture Shader Resource View");
}

Sprite::Sprite(const Sprite& other)
{
	RECT* cpyRect = new RECT();
	cpyRect->left = other.m_sourceRect->left;
	cpyRect->right = other.m_sourceRect->right;
	cpyRect->top = other.m_sourceRect->top;
	cpyRect->bottom = other.m_sourceRect->bottom;

	this->m_sourceRect = cpyRect;
	this->m_origin = other.m_origin;
	this->m_srv = other.m_srv;
}

Sprite& Sprite::operator=(const Sprite& other)
{
	RECT* cpyRect = new RECT();
	cpyRect->left = other.m_sourceRect->left;
	cpyRect->right = other.m_sourceRect->right;
	cpyRect->top = other.m_sourceRect->top;
	cpyRect->bottom = other.m_sourceRect->bottom;

	this->m_sourceRect = cpyRect;
	this->m_origin = other.m_origin;
	this->m_srv = other.m_srv;

	return *this;
}

Sprite::~Sprite() 
{
	delete this->m_sourceRect;
}
