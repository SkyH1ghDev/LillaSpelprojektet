#pragma once
#include "IEntityTakeDamage.hpp"
#include <iostream>

class EnemyTakeDamage : public IEntityTakeDamage
{
public:
    void TakeDamage(float& hp, float damage, bool& isActive, bool& shouldRender) override;
    void SetHealth(float& hp) override;
};