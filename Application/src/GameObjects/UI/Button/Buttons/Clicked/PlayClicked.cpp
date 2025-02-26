#include "PlayClicked.hpp"
#include <SpEngine/Manager/SceneManager.hpp>
#include <SpEngine/Audio/Sound.hpp>

void PlayClicked::Clicked()
{	
	
	SceneManager::UnloadScene();
	SceneManager::LoadScene("main");
	Sound::SetMusic("battle_theme_1.wav", 0.5f);
	Sound::PlayMusic(true);
}
