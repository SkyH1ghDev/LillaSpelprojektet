#pragma once
#include "IEntityAttack.hpp"
#include "ProjectileManager.hpp"
#include <iostream>

class EnemyAttack : public IEntityAttack
{
public:
    void Attack(DX::XMFLOAT2 position, DX::XMFLOAT2 direction) override;
};