#pragma once
#include <SpEngine/Clock/Clock.hpp>
#include <SpEngine/Assets/Sprite/StaticSprite.hpp>
#include <SpEngine/Assets/Sprite/AnimatedSprite.hpp>

#include <filesystem>
#include <directxtk/Audio.h>

namespace FS = std::filesystem;
namespace MW = Microsoft::WRL;
namespace DX = DirectX;

class AssetManager
{
public:
	AssetManager() = default;
	~AssetManager() = default;

	static bool ReadFolder(const MW::ComPtr<ID3D11Device>& device, const std::string& path);
	static std::shared_ptr<StaticSprite> GetSprite(const std::string& filename);
	static std::unordered_map<std::string, std::shared_ptr<ISprite>> GetTextureMap();

	static std::unordered_map<std::string, std::shared_ptr<DX::SoundEffect>> GetSFXMap();
	static void InitializeAudioEngine();
	static void ResetAudioEngine();

private:
	static std::unordered_map<std::string, std::shared_ptr<ISprite>> m_textureMap;
	static std::unordered_map<std::string, int> m_extensionIndex;
	enum fileFormat : std::uint8_t;

	static std::unique_ptr<DX::AudioEngine> m_audioEngine;
	static std::unordered_map<std::string, std::shared_ptr<DX::SoundEffect>> m_sfxMap;
};

//Returns Sprite with the matching filename in the hash map
inline std::shared_ptr<StaticSprite> AssetManager::GetSprite(const std::string& filename)
{
	if (!m_textureMap.contains(filename))
	{
		return std::static_pointer_cast<StaticSprite, ISprite>(m_textureMap["default"]);
	}

	// Is not animated
	std::shared_ptr<ISprite> sprite = m_textureMap[filename];
	std::shared_ptr<AnimatedSprite> animatedSprite = std::dynamic_pointer_cast<AnimatedSprite, ISprite>(sprite);
	
	if (animatedSprite == nullptr)
	{
		return std::static_pointer_cast<StaticSprite, ISprite>(sprite);
	}

	animatedSprite->UpdateCurrentTime(Clock::GetDeltaTime());
	return animatedSprite->GetSprite();
}

inline std::unordered_map<std::string, std::shared_ptr<ISprite>> AssetManager::GetTextureMap()
{
	return m_textureMap;
}

inline std::unordered_map<std::string, std::shared_ptr<DX::SoundEffect>> AssetManager::GetSFXMap()
{
	return m_sfxMap;
}

