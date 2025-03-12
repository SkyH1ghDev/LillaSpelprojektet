#include "QuitClicked.hpp"
#include <SpEngine/Manager/SceneManager.hpp>
#include <SpEngine/Audio/Sound.hpp>
#include "HealthBarManager.hpp"
#include "ManaBarManager.hpp"
#include "StatSheet.hpp"

void QuitClicked::Clicked(int value)
{
    SceneManager::UnloadScene();
    SceneManager::ResetScene("game");
    HealthBarManager::Reset();
    ManaBarManager::Reset();
    StatSheet::Reset();
	SceneManager::LoadScene("main");
	Sound::SetMusic("menu_theme.wav", 0.2f);
	Sound::PlayMusic(true);

}
