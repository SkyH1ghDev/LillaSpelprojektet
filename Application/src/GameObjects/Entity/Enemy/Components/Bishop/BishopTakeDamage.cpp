#include "BishopTakeDamage.hpp"
#include <SpEngine/Audio/Sound.hpp>

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
<<<<<<< Updated upstream
        Sound::PlayOnce("bishop_death.wav", 0.2f);
        isAlive = false;
=======
        Sound::PlayOnce("buh.wav", 0.2f);
>>>>>>> Stashed changes
    }
}

void BishopTakeDamage::SetHealth(float& hp)
{
    hp = 100;
}