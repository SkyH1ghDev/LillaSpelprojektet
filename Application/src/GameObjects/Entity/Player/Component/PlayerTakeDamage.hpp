#pragma once
#include "IEntityTakeDamage.hpp"
#include "HealthBarManager.hpp"

class PlayerTakeDamage : public IEntityTakeDamage
{
public:
    void TakeDamage(float& hp, float damage, bool& isActive, bool& shouldRender, float& iFrameTimer) override;
    void SetHealth(float& hp) override;

private:
    void PlayerDeath();

private:
    float dyingTimer = 5;
};