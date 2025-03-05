#include "PawnTakeDamage.hpp"
#include <SpEngine/Audio/Sound.hpp>
#include <SpEngine/Math/SpMath.hpp>

void PawnTakeDamage::TakeDamage(float& hp, float damage, bool& isAlive, bool& shouldRender, float& damageTimer, bool& iFrame)
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
        Sound::PlayOnce("pawn_death" + std::to_string(SpMath::RandomInteger(1, 3)) + ".wav", 0.2f);
        isAlive = false;
=======
        Sound::PlayOnce("buh.wav", 0.2f);
>>>>>>> Stashed changes
    }
}

void PawnTakeDamage::SetHealth(float& hp)
{
    hp = 45;
}