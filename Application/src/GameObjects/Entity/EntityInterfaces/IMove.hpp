#pragma once

#include <d3d11.h>
#include <DirectXMath.h>

namespace DX = DirectX;

class IMove
{
public:
    virtual DX::XMFLOAT2 Move(const DX::XMFLOAT2& position, const DX::XMFLOAT2& direction) = 0;
    virtual ~IMove() = default;
};
