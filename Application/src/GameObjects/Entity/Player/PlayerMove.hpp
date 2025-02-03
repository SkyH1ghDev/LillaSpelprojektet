#pragma once
#include "IMove.hpp"

class PlayerMove : public IMove
{
public:
    void Move(DX::XMFLOAT2& m_position) override;
};