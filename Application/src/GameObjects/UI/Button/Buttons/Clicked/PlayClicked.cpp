#include "PlayClicked.hpp"
#include "HealthBarManager.hpp"
#include "ManaBarManager.hpp"
#include "StatSheet.hpp"
#include <SpEngine/Manager/SceneManager.hpp>
#include <SpEngine/Audio/Sound.hpp>

void PlayClicked::Clicked()
{	
	SceneManager::UnloadScene();
	SceneManager::ResetScene("game");
	SceneManager::LoadScene("game");
	HealthBarManager::DrawHearts();
	ManaBarManager::Reset();
	HealthBarManager::Reset();
	StatSheet::Reset();
	Sound::SetMusic("battle_theme_1.wav", 0.5f);
	Sound::PlayMusic(true);
}
