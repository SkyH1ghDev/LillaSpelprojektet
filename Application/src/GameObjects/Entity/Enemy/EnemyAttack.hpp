#pragma once
#include "IEntityAttack.hpp"
#include <iostream>

class EnemyAttack : public IEntityAttack
{
public:
    void Attack(DX::XMFLOAT2 direction) override;
};