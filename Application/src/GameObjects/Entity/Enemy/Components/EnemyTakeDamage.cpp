#include "EnemyTakeDamage.hpp"
#include "EnemyManager.hpp"

void EnemyTakeDamage::TakeDamage(float& hp, float damage, bool& isActive, bool& shouldRender, float& iFrameTimer)
{
    hp -= damage;
    if (hp <= 0)
    {
        isActive = false;
        shouldRender = false;
        EnemyManager::UpdateEnemies();
    }
}

void EnemyTakeDamage::SetHealth(float& hp)
{
    hp = 100;
}