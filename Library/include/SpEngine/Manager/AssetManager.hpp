#pragma once
#include <filesystem>
#include <SpEngine/Renderer/Sprite.hpp>

namespace FS = std::filesystem;
namespace MW = Microsoft::WRL;
//namespace DX = DirectX;

class AssetManager
{
public:
	AssetManager() = default;
	~AssetManager() = default;

	static bool ReadFolder(const MW::ComPtr<ID3D11Device>& device, const std::string& path);
	static Sprite GetSprite(const std::string& filename);
	static std::vector<Sprite> GetAnimatedSprite(const std::string& filename);


private:

	static std::unordered_map<std::string, std::vector<Sprite>> m_textureMap;
	static std::unordered_map<std::string, int> m_extensionIndex;
	enum fileFormat : std::uint8_t;

};

//Returns Sprite with the matching filename in the hash map
inline Sprite AssetManager::GetSprite(const std::string& filename)
{
	if (m_textureMap.contains(filename))
	{
		return m_textureMap[filename].at(0);
	}

	return m_textureMap["default"].at(0);
}

inline std::vector<Sprite> AssetManager::GetAnimatedSprite(const std::string& filename)
{
	if (m_textureMap.contains(filename))
	{
		return m_textureMap[filename];
	}

	return m_textureMap["default"];
}
