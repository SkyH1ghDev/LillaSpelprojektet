#pragma once
#include "IMove.hpp"
#include <iostream>

class EnemyMove : public IMove
{
public:
    void Move(DX::XMFLOAT2& m_position) override;
};
