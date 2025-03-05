#include "RookTakeDamage.hpp"
#include <SpEngine/Audio/Sound.hpp>

void RookTakeDamage::TakeDamage(float& hp, float damage, bool& isAlive, bool& shouldRender, float& damageTimer, bool& iFrame)
{
    if(isAlive)
        hp -= damage;
    if (hp > 0)
    {
        damageTimer = 0.4;
        iFrame = false;
        Sound::PlayOnce("knack.wav", 0.2f);
    }
    if (hp <= 0 && isAlive)
    {
        Sound::PlayOnce("rook_death.wav", 0.2f);
        isAlive = false;
    }
}

void RookTakeDamage::SetHealth(float& hp)
{
    hp = 150;
}