#pragma once
#include "EntityMoveData.hpp"
#include <SpEngine/Physics/Collider.hpp>
#include <DirectXMath.h>

namespace DX = DirectX;

class IEntityDash
{
public:
    IEntityDash() = default;
    virtual ~IEntityDash() = default;
    IEntityDash(const IEntityDash& other) = default;
    IEntityDash& operator=(const IEntityDash& other) = default;
    IEntityDash(IEntityDash&& other) noexcept = default;
    IEntityDash& operator=(IEntityDash&& other) noexcept = default;

    virtual DX::XMFLOAT2 Dash(const DX::XMFLOAT2& position, const DX::XMFLOAT2& direction, const std::shared_ptr<Collider>& collider, const bool& dashInput, EntityMoveData& moveData) = 0;
};
