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


/* TODO: Måste fixa så att GetSprite och GetAnimatedSprite returnerar saker som faktiskt finns i m_textureMap. Ingen fault checking just nu. */

//Returns Sprite with the matching filename in the hash map
inline Sprite AssetManager::GetSprite(const std::string& filename)
{
	return m_textureMap[filename].at(0);
}

inline std::vector<Sprite> AssetManager::GetAnimatedSprite(const std::string& filename)
{
	return m_textureMap[filename];
}
