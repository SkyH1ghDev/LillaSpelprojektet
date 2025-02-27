#include "QuitClicked.hpp"
#include <SpEngine/Manager/SceneManager.hpp>
#include <SpEngine/Audio/Sound.hpp>
#include "Game.hpp"
#include "HealthBarManager.hpp"
#include "ManaBarManager.hpp"
#include "StatSheet.hpp"

void QuitClicked::Clicked()
{
	SceneManager::UnloadScene();
	SceneManager::LoadScene("start");
	SceneManager::ResetScene("main");
	Sound::SetMusic("menu_theme.wav", 0.2f);
	Sound::PlayMusic(true);
	HealthBarManager::Reset();
	ManaBarManager::Reset();
	StatSheet::Reset();

}
