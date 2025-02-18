#pragma once
#include "IEntityTakeDamage.hpp"
#include <iostream>

class EnemyTakeDamage : public IEntityTakeDamage
{
public:
    void TakeDamage(float& hp, float damage) override;
    void SetHealth(float& hp) override;
};