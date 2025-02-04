#pragma once
#include "IMove.hpp"

class PlayerMove : public IMove
{
public:
    DX::XMFLOAT2 Move(const DX::XMFLOAT2& position, const DX::XMFLOAT2& direction) override;
};

