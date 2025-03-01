#pragma once
#include "IEntityAttack.hpp"

<<<<<<<< HEAD:Application/src/GameObjects/Entity/Enemy/Components/Bishop/BishopAttack.hpp
class BishopAttack : public IEntityAttack
========
class RookAttack : public IEntityAttack
>>>>>>>> main:Application/src/GameObjects/Entity/Enemies/Rook/Components/RookAttack.hpp
{
public:
    void Attack(DX::XMFLOAT2 position, DX::XMFLOAT2 direction) override;
};