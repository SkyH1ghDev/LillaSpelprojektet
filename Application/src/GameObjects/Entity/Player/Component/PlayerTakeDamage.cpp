#include "PlayerTakeDamage.hpp"
#include "StatSheet.hpp"
#include <SpEngine/Audio/Sound.hpp>

void PlayerTakeDamage::TakeDamage(float& hp, float damage, bool& isActive, bool& shouldRender, float& iFrameTimer)
{
    if (iFrameTimer <= 0)
    {
        hp -= damage;
        HealthBarManager::RemoveHeart(damage);
        StatSheet::CreateEffect(StatType::MoveSpeed, 1.0f, -150);
        if (hp <= 0)
        {
            Sound::PlayOnce("aaagh.wav", 0.2f);
            Sound::SetMusic("menu_theme_v2.wav", 0.2f);
            Sound::PlayMusic(true);
            isActive = false;
            //shouldRender = false;
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