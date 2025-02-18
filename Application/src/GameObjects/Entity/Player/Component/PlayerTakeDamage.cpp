#include "PlayerTakeDamage.hpp"
#include "StatSheet.hpp"

void PlayerTakeDamage::TakeDamage(float& hp, float damage)
{
    hp -= damage;
    HealthBarManager::RemoveHeart(damage);
}

void PlayerTakeDamage::SetHealth(float& hp)
{
    hp = StatSheet::GetMaxHealth();
}