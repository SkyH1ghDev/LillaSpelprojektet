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

	bool ReadFolder(const MW::ComPtr<ID3D11Device>& device, const std::string& path);
	Sprite GetSprite(const std::string& filename);
	std::shared_ptr<RECT> getSourceRect(const std::string& filename);

private:

	std::map<std::string, Sprite> m_textureMap;
};

//Returns Sprite with the matching filename in the hash map
inline Sprite AssetManager::GetSprite(const std::string& filename)
{
	return m_textureMap[filename];
}

//Returns Rect from the matching filename in the hash map
inline std::shared_ptr<RECT> AssetManager::getSourceRect(const std::string& filename)
{
	return m_textureMap[filename].GetSourceRectangle();
}

