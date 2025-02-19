#include <SpEngine/Manager/AssetManager.hpp>

class Sound
{
public:
	Sound() = default;
	~Sound() = default;
	static void Play(std::string filename, float volume, float pitch = 0, float pan = 0);
private:

};

inline void Sound::Play(std::string filename, float volume, float pitch, float pan)
{
	AssetManager::GetSFXMap()[filename]->Play(volume, pitch, pan);
}