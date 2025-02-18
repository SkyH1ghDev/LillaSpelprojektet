#pragma once

#include <d3d11.h>
#include <DirectXMath.h>
#include <SpEngine/Physics/PhysicsEngine.hpp>

namespace DX = DirectX;

class IEntityMove
{
public:
    virtual DX::XMFLOAT2 Move(const DX::XMFLOAT2& position, const DX::XMFLOAT2& direction, bool dashing, Collider m_collider) = 0;
    virtual ~IEntityMove() = default;
};
