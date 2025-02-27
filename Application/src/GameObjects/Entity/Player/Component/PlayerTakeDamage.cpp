#include "PlayerTakeDamage.hpp"
#include "StatSheet.hpp"
#include "Button/Button.hpp"
#include <SpEngine/Audio/Sound.hpp>
#include <SpEngine/Manager/SceneManager.hpp>

void PlayerTakeDamage::TakeDamage(float& hp, float damage, bool& isActive, bool& shouldRender, float& iFrameTimer)
{
    if (iFrameTimer <= 0)
    {
        StatSheet::DecreaseHealth(damage);
        hp = StatSheet::GetCurrentHealth();
        HealthBarManager::RemoveHeart(damage);
        StatSheet::CreateEffect(StatType::MoveSpeed, 0.5f, -150);
        if (hp <= 0)
        {
            PlayerDeath();
        }
        else
        {
            Sound::PlayOnce("ugh.wav", 0.2f);
        }
        iFrameTimer = 1.0;
    }
}

void PlayerTakeDamage::SetHealth(float& hp)
{
    hp = StatSheet::GetMaxHealth();
}

void PlayerTakeDamage::PlayerDeath()
{
    Sound::PlayOnce("aaagh.wav", 0.2f);
    Sound::SetMusic("menu_theme.wav", 0.2f);
    Sound::PlayMusic(true);

    std::shared_ptr<IScene> deathScene = SceneManager::GetScene("main");

    std::shared_ptr<Button> restart = std::make_shared<Button>(ButtonType::Play);
    std::shared_ptr<Button> quit = std::make_shared<Button>(ButtonType::Quit);
    restart->SetupButton();
    quit->SetupButton();
    restart->SetPosition({ 245, 180 });
    quit->SetPosition({ 245, 240 });
    std::shared_ptr<IGameObject> restartButton = restart;
    std::shared_ptr<IGameObject> quitButton = quit;

    
    deathScene->AddGameObject(restartButton);
    deathScene->AddGameObject(quitButton);
}
