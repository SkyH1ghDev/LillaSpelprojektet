#include "PlayerTakeDamage.hpp"
#include "StatSheet.hpp"
#include <SpEngine/Audio/Sound.hpp>

void PlayerTakeDamage::TakeDamage(float& hp, float damage, bool& isActive, bool& shouldRender, float& iFrameTimer)
{
    if (iFrameTimer <= 0)
    {
        hp -= damage;
        HealthBarManager::RemoveHeart(damage);
        if (hp <= 0)
        {
            Sound::Play("aaagh.wav", 0.5f);
            isActive = false;
            shouldRender = false;
        }
        else
        {
            Sound::Play("ugh.wav", 0.5f);
        }
        iFrameTimer = 1.0;
    }
}

void PlayerTakeDamage::SetHealth(float& hp)
{
    hp = StatSheet::GetMaxHealth();
}