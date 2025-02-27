#include "BishopTakeDamage.hpp"
#include <SpEngine/Audio/Sound.hpp>

void BishopTakeDamage::TakeDamage(float& hp, float damage, bool& isActive, bool& shouldRender, float& iFrameTimer)
{
    hp -= damage;
    Sound::PlayOnce("knack.wav", 0.2f);
    if (hp <= 0 && isActive)
    {
        Sound::PlayOnce("buh.wav", 0.2f);
    }
}

void BishopTakeDamage::SetHealth(float& hp)
{
    hp = 100;
}