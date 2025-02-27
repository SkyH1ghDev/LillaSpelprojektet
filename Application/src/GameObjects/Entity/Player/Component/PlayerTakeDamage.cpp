#include "PlayerTakeDamage.hpp"
#include "StatSheet.hpp"
#include <SpEngine/Audio/Sound.hpp>
#include "HealthBarManager.hpp"
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
    SceneManager::UnloadScene();
    SceneManager::LoadScene("death");
    SceneManager::ResetScene("main");

    Sound::PlayOnce("aaagh.wav", 0.2f);
    Sound::SetMusic("menu_theme.wav", 0.2f);
    Sound::PlayMusic(true);

}
