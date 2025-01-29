#pragma once
#include "AssetManager.hpp"

AssetManager::AssetManager()
{
}

AssetManager::~AssetManager()
{
}

//Reads all png and jpg files in folder specified by path string
bool AssetManager::ReadFolder(MW::ComPtr<ID3D11Device> &device, std::string path)
{
	for (const auto& entry : FS::directory_iterator(path)) 
	{
		std::string filepath = entry.path().string();
		std::string extension = filepath.substr(filepath.find_last_of('.'), 4);
		if (extension == ".jpg" || extension == ".png") 
		{
			filepath.at(filepath.find('\\')) = '/';

			ShaderResourceTexture texture(device, filepath);
			textures.push_back(texture);

			textureNames.push_back(filepath);
		}
	}

	return true;
}