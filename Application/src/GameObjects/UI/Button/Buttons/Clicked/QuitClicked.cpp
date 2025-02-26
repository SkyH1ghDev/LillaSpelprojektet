#include "QuitClicked.hpp"
#include <SpEngine/Manager/SceneManager.hpp>
#include <SpEngine/Audio/Sound.hpp>
#include "Game.hpp"

void QuitClicked::Clicked()
{
	SceneManager::UnloadScene();
	SceneManager::LoadScene("start");
	Sound::SetMusic("menu_theme.wav", 0.2f);
	Sound::PlayMusic(true);

}
