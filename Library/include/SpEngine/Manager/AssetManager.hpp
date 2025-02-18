#pragma once
#include <filesystem>
#include <SpEngine/Renderer/Sprite.hpp>

#include "SpriteWrapper.hpp"

namespace FS = std::filesystem;
namespace MW = Microsoft::WRL;
//namespace DX = DirectX;

class AssetManager
{
public:
	AssetManager() = default;
	~AssetManager() = default;

	static bool ReadFolder(const MW::ComPtr<ID3D11Device>& device, const std::string& path);
	static SpriteWrapper GetSprite(const std::string& filename);
	static std::unordered_map<std::string, SpriteWrapper> GetTextureMap();


private:

	
	static std::unordered_map<std::string, SpriteWrapper> m_textureMap;
	static std::unordered_map<std::string, int> m_extensionIndex;
	enum fileFormat : std::uint8_t;

};

//Returns Sprite with the matching filename in the hash map
inline SpriteWrapper AssetManager::GetSprite(const std::string& filename)
{
	if (!m_textureMap.contains(filename))
	{
		return m_textureMap["default"];
	}

	// Is not animated
	std::shared_ptr<Sprite> sprite = m_textureMap[filename];
	std::shared_ptr<AnimatedSprite> animatedSprite = std::dynamic_pointer_cast<AnimatedSprite, Sprite>(sprite);
	if (animatedSprite == nullptr)
	{
		return sprite;
	}

	return animatedSprite;
}

inline std::unordered_map<std::string, SpriteWrapper> AssetManager::GetTextureMap()
{
	return m_textureMap;
}

