#pragma once
#include "AssetManager.hpp"

AssetManager::AssetManager()
{
}

AssetManager::~AssetManager()
{
}

//Reads all png and jpg files in folder specified by path string
//All read files are added to the instance of the asset manager
bool AssetManager::ReadFolder(MW::ComPtr<ID3D11Device> &device, std::string path)
{
	int assetIndex = 0;
	for (const auto& entry : FS::directory_iterator(path)) 
	{
		std::string filepath = entry.path().string();
		filepath.at(filepath.find('\\')) = '/';
		size_t folderIndex = filepath.find_last_of('/');
		std::string filename = filepath.substr(folderIndex + 1, filepath.length() - folderIndex);
		std::string extension = filename.substr(filename.find_last_of('.'), 4);

		if (extension == ".jpg" || extension == ".png") 
		{
			ShaderResourceTexture texture(device, filepath);
			this->m_textureMap[filename] = texture;
		}

		assetIndex++;
	}

	return true;
}