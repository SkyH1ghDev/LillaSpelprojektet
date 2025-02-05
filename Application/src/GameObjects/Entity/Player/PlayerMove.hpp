#pragma once
#include "IEntityMove.hpp"

class PlayerMove : public IEntityMove
{
public:
    DX::XMFLOAT2 Move(const DX::XMFLOAT2& position, const DX::XMFLOAT2& direction) override;
};

