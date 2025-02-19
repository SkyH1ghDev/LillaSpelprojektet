#include "EnemyTakeDamage.hpp"
#include "EnemyManager.hpp"
#include <SpEngine/Audio/Sound.hpp>

void EnemyTakeDamage::TakeDamage(float& hp, float damage, bool& isActive, bool& shouldRender, float& iFrameTimer)
{
    hp -= damage;
    Sound::PlayOnce("knack.wav", 0.2f);
    if (hp <= 0)
    {
        isActive = false;
        shouldRender = false;
        EnemyManager::UpdateEnemies();
        Sound::PlayOnce("buh.wav", 0.2f);
    }
}

void EnemyTakeDamage::SetHealth(float& hp)
{
    hp = 100;
}