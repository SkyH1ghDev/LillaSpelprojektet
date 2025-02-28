#include "QuitClicked.hpp"
#include <SpEngine/Manager/SceneManager.hpp>
#include <SpEngine/Audio/Sound.hpp>


void QuitClicked::Clicked()
{
	SceneManager::UnloadScene();
	SceneManager::LoadScene("main");
	Sound::SetMusic("menu_theme.wav", 0.2f);
	Sound::PlayMusic(true);

}
