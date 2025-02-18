#pragma once
#include "IEntityMove.hpp"
#include <iostream>

class EnemyMove : public IEntityMove
{
public:
    DX::XMFLOAT2 Move(const DX::XMFLOAT2& m_position, const DX::XMFLOAT2& m_direction, bool dashing, Collider m_collider) override;
};
