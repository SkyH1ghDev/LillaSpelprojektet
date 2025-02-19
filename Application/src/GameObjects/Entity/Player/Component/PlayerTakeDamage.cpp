#include "PlayerTakeDamage.hpp"
#include "StatSheet.hpp"
#include <SpEngine/Audio/Sound.hpp>

void PlayerTakeDamage::TakeDamage(float& hp, float damage, bool& isActive, bool& shouldRender, float& iFrameTimer)
{
    hp -= damage;
    HealthBarManager::RemoveHeart(damage);

    if (iFrameTimer <= 0)
    {
        hp -= damage;
        HealthBarManager::RemoveHeart(damage);
        Sound::Play("ugh.wav", 0.5f);
        if (hp <= 0)
        {
            Sound::Play("aaagh.wav", 0.5f);
            isActive = false;
            shouldRender = false;
        }
        iFrameTimer = 1.0;
    }
}

void PlayerTakeDamage::SetHealth(float& hp)
{
    hp = StatSheet::GetMaxHealth();
}