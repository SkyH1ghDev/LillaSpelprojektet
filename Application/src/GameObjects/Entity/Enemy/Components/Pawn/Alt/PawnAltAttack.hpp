#pragma once
#include "IEntityAttack.hpp"

class PawnAltAttack : public IEntityAttack
{
public:
    PawnAltAttack() = default;
    ~PawnAltAttack() override = default;
    PawnAltAttack(const PawnAltAttack& other) = default;
    PawnAltAttack& operator=(const PawnAltAttack& other) = default;
    PawnAltAttack(PawnAltAttack&& other) noexcept = default;
    PawnAltAttack& operator=(PawnAltAttack&& other) noexcept = default;

    void Attack(DX::XMFLOAT2 position, DX::XMFLOAT2 direction) override;
    
private:
    float m_attackCooldown = 0.75f;
    float m_attackTimer = 0.0f;
};
