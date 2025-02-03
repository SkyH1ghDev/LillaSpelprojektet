#pragma once
#include "IMove.hpp"
#include "Vector2.hpp"

class PlayerMove : public IMove
{
public:
    void Move(DX::XMFLOAT2& m_position) override;
};