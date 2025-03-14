#include <SpEngine/Manager/AssetManager.hpp>

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
	static void ResetAudio();
	static void SetSFXVolume(float volume);
	static void SetMusicVolume(float volume);

private:

	inline static std::unique_ptr<DX::SoundEffectInstance> m_music = nullptr;
	static float m_sfxVolume;
	static float m_musicVolume;
};

inline void Sound::PlayOnce(std::string filename, float volume, float pitch, float pan)
{
	AssetManager::GetSFXMap()[filename]->Play(volume * Sound::m_sfxVolume, pitch, pan);
}

inline void Sound::PlayMusic(bool loop)
{
	m_music->Play(loop);
}

inline void Sound::SetMusic(std::string filename, float volume)
{
	m_music = std::move(AssetManager::GetSFXMap()[filename]->CreateInstance());
	m_music->SetVolume(volume * Sound::m_musicVolume);
}

inline void Sound::PauseMusic()
{
	m_music->Pause();
}

inline void Sound::ResumeMusic()
{
	m_music->Resume();
}

inline void Sound::ResetAudio()
{
	AssetManager::ResetAudioEngine();
}

inline void Sound::SetSFXVolume(float volume)
{
	Sound::m_sfxVolume = volume;
}

inline void Sound::SetMusicVolume(float volume)
{
	Sound::m_musicVolume = volume;
}