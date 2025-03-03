#pragma once
#include "IEntityAttack.hpp"

class BishopAltAttack : public IEntityAttack
{
public:
    void Attack(DX::XMFLOAT2 position, DX::XMFLOAT2 direction) override;

private:
    float m_attackCooldown = 0.7f;
    float m_attackTimer = 0.0f;
    float m_burstTimer = 0.0f;
    float m_burstCooldown = 0.1f;
    int m_burstAmount = 3;
};