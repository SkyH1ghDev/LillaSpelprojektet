#pragma once
#include "IEntityAttack.hpp"

class BishopAttack : public IEntityAttack
{
public:
    void Attack(DX::XMFLOAT2 position, DX::XMFLOAT2 direction) override;

private:
    float m_attackCooldown = 1.0f;
    float m_attackTimer = 0.0f;
};