#include "PlayerTakeDamage.hpp"
#include "StatSheet.hpp"
#include "HealthBarManager.hpp"
#include <SpEngine/Audio/Sound.hpp>


void PlayerTakeDamage::TakeDamage(float& hp, float damage, bool& isActive, bool& shouldRender, float& damageTimer, bool& iFrame)
{
    if (!iFrame)
    {
        StatSheet::DecreaseHealth(damage);
        hp = StatSheet::GetCurrentHealth();
        HealthBarManager::DrawHearts();
        StatSheet::CreateEffect(StatType::MoveSpeed, 0.5f, -150);
        if (hp <= 0)
        {
            HealthBarManager::DrawHearts();
            Sound::PlayOnce("aaagh.wav", 0.2f);
            Sound::SetMusic("menu_theme.wav", 0.2f);
            Sound::PlayMusic(true);
        }
        else
        {
            Sound::PlayOnce("ugh.wav", 0.2f);
        }
        iFrame = true;
        damageTimer = 1.0f;
    }
}

void PlayerTakeDamage::SetHealth(float& hp)
{
    hp = StatSheet::GetMaxHealth();
}

