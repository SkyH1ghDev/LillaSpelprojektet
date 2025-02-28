#include "PlayClicked.hpp"
#include "HealthBarManager.hpp"
#include "ManaBarManager.hpp"
#include <SpEngine/Manager/SceneManager.hpp>
#include <SpEngine/Audio/Sound.hpp>

void PlayClicked::Clicked()
{	
	SceneManager::UnloadScene();
	SceneManager::ResetScene("main");
	SceneManager::LoadScene("main");
	HealthBarManager::DrawHearts();
	ManaBarManager::Reset();
	Sound::SetMusic("battle_theme_1.wav", 0.5f);
	Sound::PlayMusic(true);
}
