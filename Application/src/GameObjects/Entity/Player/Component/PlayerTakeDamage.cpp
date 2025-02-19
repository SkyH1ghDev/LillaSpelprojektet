#include "PlayerTakeDamage.hpp"

void PlayerTakeDamage::TakeDamage(float& hp, float damage)
{
    hp -= damage;
    HealthBarManager::RemoveHeart(damage);
}

void PlayerTakeDamage::SetHealth(float& hp)
{
    hp = 5;
}