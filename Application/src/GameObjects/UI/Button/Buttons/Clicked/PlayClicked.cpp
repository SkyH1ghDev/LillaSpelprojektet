#include "PlayClicked.hpp"
#include <SpEngine/Manager/SceneManager.hpp>

void PlayClicked::Clicked()
{
	SceneManager::UnloadScene();
	SceneManager::LoadScene("main");
}
