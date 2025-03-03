#include "CardClicked.hpp"
#include <SpEngine/Manager/SceneManager.hpp>
#include <SpEngine/Audio/Sound.hpp>
#include "DeckManager.hpp"

void CardClicked::Clicked(int value)
{
	DeckManager::PerformDeckUpgrade(value);
}
