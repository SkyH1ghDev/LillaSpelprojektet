#pragma once
#include <SpEngine/Renderer/Texture.hpp>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>

ShaderResourceTexture::ShaderResourceTexture(MW::ComPtr<ID3D11Device> device, std::string filepath)
{
	ID3D11ShaderResourceView* srvCpy;
	ID3D11Texture2D* texture;

	int textureHeight, textureWidth, rgbaChannels;

	unsigned char* imageData = stbi_load(filepath.c_str(), &textureWidth, &textureHeight, &rgbaChannels, 0);

	rgbaChannels = 4;

	this->m_height = textureHeight;
	this->m_width = textureWidth;

	m_rect.left = 0;
	m_rect.right = this->m_width;
	m_rect.top = 0;
	m_rect.bottom = this->m_height;

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

ShaderResourceTexture::~ShaderResourceTexture()
{
}
