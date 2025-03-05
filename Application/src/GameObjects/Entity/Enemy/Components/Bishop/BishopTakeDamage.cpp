#include "BishopTakeDamage.hpp"
#include <SpEngine/Audio/Sound.hpp>
#include <SpEngine/Math/SpMath.hpp>

void BishopTakeDamage::TakeDamage(float& hp, float damage, bool& isAlive, bool& shouldRender, float& damageTimer, bool& iFrame)
{
    if (isAlive)
        hp -= damage;
    if (hp > 0)
    {
        damageTimer = 0.4;
        iFrame = false;
        Sound::PlayOnce("knack.wav", 0.2f);
    }
    if (hp <= 0 && isAlive)
    {
        Sound::PlayOnce("bishop_death" + std::to_string(SpMath::RandomInteger(1, 2)) + ".wav", 0.2f);
    }
}

void BishopTakeDamage::SetHealth(float& hp)
{
    hp = 100;
}