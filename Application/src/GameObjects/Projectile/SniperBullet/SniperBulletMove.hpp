#pragma once
#include "IProjectileMove.hpp"
#include <iostream>

class SniperBulletMove : public IProjectileMove
{
public:
    DX::XMFLOAT2 Move(const DX::XMFLOAT2& m_position, const DX::XMFLOAT2& m_direction, float velocity) override;
};
