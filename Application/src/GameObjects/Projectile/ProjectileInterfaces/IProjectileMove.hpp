#pragma once
#include <SpEngine/Clock/Clock.hpp>

#include <d3d11.h>
#include <DirectXMath.h>

namespace DX = DirectX;

class IProjectileMove
{
public:
    virtual DX::XMFLOAT2 Move(const DX::XMFLOAT2& position, const DX::XMFLOAT2& direction, float velocity) = 0;
    virtual ~IProjectileMove() = default;
};
