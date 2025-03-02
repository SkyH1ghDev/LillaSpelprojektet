#include "ContinueClicked.hpp"
#include <SpEngine/Manager/SceneManager.hpp>
#include <SpEngine/Audio/Sound.hpp>

void ContinueClicked::Clicked(int value)
{
	SceneManager::UnloadScene();
	SceneManager::LoadScene("game");
	Sound::SetMusic("battle_theme_1.wav", 0.5f);
	Sound::PlayMusic(true);
}
