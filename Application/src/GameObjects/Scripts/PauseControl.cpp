#pragma once
#include "PauseControl.hpp"
#include <SpEngine/Manager/SceneManager.hpp>
#include <SpEngine/Audio/Sound.hpp>
#include "DeckManager.hpp"

void PauseControl::OnStart()
{
	Input::GetKey(VK_ESCAPE)->Attach(std::static_pointer_cast<IObserver, Pause>(m_pause));
}

void PauseControl::Update()
{
	if (m_pause->GetPause())
	{
		if (!m_keyHeld)
		{
			if (SceneManager::GetCurrentSceneID() != "upgrade")
			{
				SceneManager::UnloadScene();

				SceneManager::LoadScene("upgrade");

				DeckManager::ResetMenu(UpgradeType::LevelCard);

				Sound::SetMusic("prepare.wav", 0.5f);
				Sound::PlayMusic(true);
			}
			else
			{
				SceneManager::UnloadScene();
				SceneManager::LoadScene(SceneManager::GetPreviousSceneID());
				Sound::SetMusic("battle_theme_1.wav", 0.5f);
				Sound::PlayMusic(true);
			}

			m_keyHeld = true;
		}
	}
	else
		m_keyHeld = false;
}

