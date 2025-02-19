#include "PlayerTakeDamage.hpp"
#include "StatSheet.hpp"

void PlayerTakeDamage::TakeDamage(float& hp, float damage, bool& isActive, bool& shouldRender, float& iFrameTimer)
{
    if (iFrameTimer <= 0)
    {
        hp -= damage;
        HealthBarManager::RemoveHeart(damage);
        if (hp <= 0)
        {
            isActive = false;
            shouldRender = false;
        }
        iFrameTimer = 1.0;
    }
    
}

void PlayerTakeDamage::SetHealth(float& hp)
{
    hp = StatSheet::GetMaxHealth();
}