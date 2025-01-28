#pragma once
#include "ITakeDamage.hpp"
#include <iostream>

class EnemyTakeDamage : public ITakeDamage
{
public:
    void TakeDamage() override;
};