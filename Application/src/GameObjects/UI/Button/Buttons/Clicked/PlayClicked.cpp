#include "PlayClicked.hpp"
#include <SpEngine/Manager/SceneManager.hpp>
#include <SpEngine/Audio/Sound.hpp>

void PlayClicked::Clicked()
{	
	
	SceneManager::UnloadScene();
	SceneManager::LoadScene("main");
}
