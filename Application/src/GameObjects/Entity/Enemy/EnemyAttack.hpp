#pragma once
#include "IAttack.hpp"
#include <iostream>

class EnemyAttack : public IAttack
{
public:
    void Attack() override;
};