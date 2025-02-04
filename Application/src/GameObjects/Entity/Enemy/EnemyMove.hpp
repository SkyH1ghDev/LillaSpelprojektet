#pragma once
#include "IMove.hpp"
#include <iostream>

class EnemyMove : public IMove
{
public:
    DX::XMFLOAT2 Move(const DX::XMFLOAT2& m_position, const DX::XMFLOAT2& m_direction) override;
};
