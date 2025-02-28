#pragma once
#include "IEntityTakeDamage.hpp"

class PlayerTakeDamage : public IEntityTakeDamage
{
public:
    void TakeDamage(float& hp, float damage, bool& isActive, bool& shouldRender, float& damageTimer, bool& iFrame) override;
    void SetHealth(float& hp) override;
};