#pragma once
#include "IEntityAttack.hpp"
#include <DirectXMath.h>

namespace DX = DirectX;

class PlayerAttack : public IEntityAttack
{
public:
    void Attack(DX::XMFLOAT2 position, DX::XMFLOAT2 direction) override;
    void Reset() override;
};