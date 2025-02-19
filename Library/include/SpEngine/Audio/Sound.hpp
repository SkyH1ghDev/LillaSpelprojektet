#include <SpEngine/Manager/AssetManager.hpp>
#include <vector>

class Sound
{
public:
	Sound() = default;
	~Sound() = default;
	static void PlayOnce(std::string filename, float volume, float pitch = 0, float pan = 0);
	static void SetMusic(std::string filename, float volume);
	static void PlayMusic(bool loop);
	static void PauseMusic();
	static void ResumeMusic();
private:
	inline static std::unique_ptr<DX::SoundEffectInstance> m_music = nullptr;
	static float gameVolume;
};

inline void Sound::PlayOnce(std::string filename, float volume, float pitch, float pan)
{
	AssetManager::GetSFXMap()[filename]->Play(volume, pitch, pan);
}

inline void Sound::PlayMusic(bool loop)
{
	Sound::m_music->Play(loop);
}

inline void Sound::SetMusic(std::string filename, float volume)
{
	Sound::m_music = std::move(AssetManager::GetSFXMap()[filename]->CreateInstance());
	Sound::m_music->SetVolume(volume);
}

inline void Sound::PauseMusic()
{
	Sound::m_music->Pause();
}

inline void Sound::ResumeMusic()
{
	Sound::m_music->Resume();
}