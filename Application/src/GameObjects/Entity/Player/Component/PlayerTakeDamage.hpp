#pragma once
#include "IEntityTakeDamage.hpp"
#include "HealthBarManager.hpp"
#include <iostream>

class PlayerTakeDamage : public IEntityTakeDamage
{
public:
    void TakeDamage(float& hp, float damage) override;
    void SetHealth(float& hp) override;
};