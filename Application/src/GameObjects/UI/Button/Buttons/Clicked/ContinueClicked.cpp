#include "ContinueClicked.hpp"
#include <SpEngine/Manager/SceneManager.hpp>
#include <SpEngine/Audio/Sound.hpp>

void ContinueClicked::Clicked(int value)
{
	if (SceneManager::GetPreviousSceneID() == "game")
		Sound::SetMusic("battle_theme_1.wav", 0.4f);
	if (SceneManager::GetPreviousSceneID() == "upgrade")
		Sound::SetMusic("prepare.wav", 0.4f);

	SceneManager::UnloadScene();
	SceneManager::LoadScene(SceneManager::GetPreviousSceneID());

	Sound::PlayMusic(true);
}
