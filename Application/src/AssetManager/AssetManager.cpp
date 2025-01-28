#pragma once
#include "AssetManager.hpp"

AssetManager::AssetManager()
{
}

AssetManager::~AssetManager()
{
}

bool AssetManager::ReadFolder(MW::ComPtr<ID3D11Device> &device, std::string path)
{
	for (const auto& entry : FS::directory_iterator(path)) 
	{
		std::string filepath = entry.path().string();
		filepath.at(filepath.find('\\')) = '/';

		ShaderResourceTexture texture(device, filepath);
		textures.push_back(texture);

		textureNames.push_back(filepath);
	}

	return true;
}