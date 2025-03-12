#pragma once
#include "IEntityAttack.hpp"

class RookAttack : public IEntityAttack
{
public:
    void Attack(DX::XMFLOAT2 position, DX::XMFLOAT2 direction) override;
    void Reset() override;
};