#pragma once

#include <d3d11.h>
#include <DirectXMath.h>
#include <SpEngine/Physics/GamePhysics.hpp>

namespace DX = DirectX;

class IEntityMove
{
public:
    virtual DX::XMFLOAT2 Move(const DX::XMFLOAT2& position, const DX::XMFLOAT2& direction, bool dashing, std::shared_ptr<Collider> m_collider) = 0;
    virtual ~IEntityMove() = default;
};
