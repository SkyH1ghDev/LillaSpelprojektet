#pragma once
#include "IEntityAttack.hpp"
#include <iostream>

class EnemyAttack : public IEntityAttack
{
public:
    void Attack() override;
};