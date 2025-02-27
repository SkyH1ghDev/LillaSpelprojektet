#pragma once
#include "IEntityAttack.hpp"

class PawnAttack : public IEntityAttack
{
public:
    PawnAttack() = default;
    ~PawnAttack() override = default;
    PawnAttack(const PawnAttack& other) = default;
    PawnAttack& operator=(const PawnAttack& other) = default;
    PawnAttack(PawnAttack&& other) noexcept = default;
    PawnAttack& operator=(PawnAttack&& other) noexcept = default;
    
    void Attack(DX::XMFLOAT2 position, DX::XMFLOAT2 direction) override;
};
