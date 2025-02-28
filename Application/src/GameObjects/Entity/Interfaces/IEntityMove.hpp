#pragma once
#include <DirectXMath.h>
#include <SpEngine/Physics/Collider.hpp>
#include "EntityMoveData.hpp"

namespace DX = DirectX;

class IEntityMove
{
public:
    virtual DX::XMFLOAT2 Move(const DX::XMFLOAT2& position, const DX::XMFLOAT2& direction, const std::shared_ptr<Collider>& collider, EntityMoveData& moveData) = 0;
    virtual ~IEntityMove() = default;

};
