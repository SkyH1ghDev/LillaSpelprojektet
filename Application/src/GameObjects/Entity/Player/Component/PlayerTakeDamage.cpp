#include "PlayerTakeDamage.hpp"
#include "StatSheet.hpp"

void PlayerTakeDamage::TakeDamage(float& hp, float damage, bool& isActive, bool& shouldRender)
{
    hp -= damage;
    HealthBarManager::RemoveHeart(damage);
    if (hp <= 0)
    {
        isActive = false;
        shouldRender = false;
    }
}

void PlayerTakeDamage::SetHealth(float& hp)
{
    hp = StatSheet::GetMaxHealth();
}