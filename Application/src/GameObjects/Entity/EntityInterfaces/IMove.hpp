#pragma once

#include <d3d11.h>
#include <DirectXMath.h>

namespace DX = DirectX;

class IMove
{
public:
    virtual void Move(DX::XMFLOAT2& position, DX::XMFLOAT2& m_direction) = 0;
    virtual ~IMove() = default;
};
