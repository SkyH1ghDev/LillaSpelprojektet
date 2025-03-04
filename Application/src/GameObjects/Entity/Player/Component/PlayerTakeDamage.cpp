#include "PlayerTakeDamage.hpp"
#include "StatSheet.hpp"
#include "HealthBarManager.hpp"
#include <SpEngine/Audio/Sound.hpp>


void PlayerTakeDamage::TakeDamage(float& hp, float damage, bool& isAlive, bool& shouldRender, float& damageTimer, bool& iFrame)
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

