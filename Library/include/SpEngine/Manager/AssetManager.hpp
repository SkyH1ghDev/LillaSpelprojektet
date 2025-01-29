#pragma once
#include <vector>
#include <filesystem>
#include <map>
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

	std::vector<ShaderResourceTexture> m_textures;
	std::map<std::string, int> m_indexMap;
};


