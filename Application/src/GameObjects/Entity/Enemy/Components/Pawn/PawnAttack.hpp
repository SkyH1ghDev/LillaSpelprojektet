#pragma once
#include "IEntityAttack.hpp"

class PawnAttack : public IEntityAttack
{
public:
    void Attack(DX::XMFLOAT2 position, DX::XMFLOAT2 direction) override;
    void Reset() override;

private:
    float m_attackCooldown = 0.50f;
    float m_attackTimer = 0.0f;
};