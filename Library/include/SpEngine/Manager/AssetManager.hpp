#pragma once
#include <filesystem>
#include <map>
#include <SpEngine/Renderer/Sprite.hpp>

namespace FS = std::filesystem;
namespace MW = Microsoft::WRL;
//namespace DX = DirectX;

class AssetManager
{
public:
	AssetManager() = default;
	~AssetManager() = default;

	bool ReadFolder(MW::ComPtr<ID3D11Device>& device, std::string path);
	Sprite GetSprite(std::string filename);

private:

	std::map<std::string, Sprite> m_textureMap;
};

//Returns Sprite with the matching filename in the hash map
inline Sprite AssetManager::GetSprite(std::string filename)
{
	return m_textureMap[filename];
}

