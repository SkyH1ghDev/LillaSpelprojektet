#pragma once
#include <vector>
#include <wrl/client.h>
#include <string>
#include <filesystem>
#include <iostream>
#include <d3d11.h>
#include "Texture.hpp"

namespace FS = std::filesystem;
namespace MW = Microsoft::WRL;
//namespace DX = DirectX;

class AssetManager
{
public:
	AssetManager();
	~AssetManager();

	bool ReadFolder(MW::ComPtr<ID3D11Device>& device, std::string path);

private:

	std::vector<ShaderResourceTexture> textures;

	//Temporary asset tracking vector
	std::vector<std::string> textureNames;
};


