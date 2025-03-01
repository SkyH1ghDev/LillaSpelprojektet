<<<<<<<< HEAD:Application/src/GameObjects/Entity/Enemy/Components/Bishop/BishopTakeDamage.cpp
#include "BishopTakeDamage.hpp"
#include <SpEngine/Audio/Sound.hpp>

void BishopTakeDamage::TakeDamage(float& hp, float damage, bool& isActive, bool& shouldRender, float& damageTimer, bool& iFrame)
========
#include "RookTakeDamage.hpp"
#include <SpEngine/Audio/Sound.hpp>

void RookTakeDamage::TakeDamage(float& hp, float damage, bool& isActive, bool& shouldRender, float& damageTimer, bool& iFrame)
>>>>>>>> main:Application/src/GameObjects/Entity/Enemies/Rook/Components/RookTakeDamage.cpp
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

<<<<<<<< HEAD:Application/src/GameObjects/Entity/Enemy/Components/Bishop/BishopTakeDamage.cpp
void BishopTakeDamage::SetHealth(float& hp)
========
void RookTakeDamage::SetHealth(float& hp)
>>>>>>>> main:Application/src/GameObjects/Entity/Enemies/Rook/Components/RookTakeDamage.cpp
{
    hp = 100;
}