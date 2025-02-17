#pragma once
#include "IEntityTakeDamage.hpp"
#include <iostream>

class EnemyTakeDamage : public IEntityTakeDamage
{
public:
    void TakeDamage() override;
};