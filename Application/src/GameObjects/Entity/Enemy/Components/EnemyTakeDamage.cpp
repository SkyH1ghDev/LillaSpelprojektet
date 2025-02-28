#include "EnemyTakeDamage.hpp"
#include <SpEngine/Audio/Sound.hpp>

void EnemyTakeDamage::TakeDamage(float& hp, float damage, bool& isActive, bool& shouldRender, float& damageTimer, bool& iFrame)
{
    hp -= damage;
    if (hp > 0)
    {
        damageTimer = 0.4;
        iFrame = false;
        Sound::PlayOnce("knack.wav", 0.2f);
    }
    if (hp <= 0 && isActive)
    {
        Sound::PlayOnce("buh.wav", 0.2f);
    }
}

void EnemyTakeDamage::SetHealth(float& hp)
{
    hp = 100;
}