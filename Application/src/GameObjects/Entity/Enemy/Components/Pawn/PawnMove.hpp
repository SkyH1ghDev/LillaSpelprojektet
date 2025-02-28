#pragma once
#include "IEntityMove.hpp"

class PawnMove : public IEntityMove
{
public:
    PawnMove() = default;
    ~PawnMove() override = default;
    PawnMove(const PawnMove& other) = default;
    PawnMove& operator=(const PawnMove& other) = default;
    PawnMove(PawnMove&& other) noexcept = default;
    PawnMove& operator=(PawnMove&& other) noexcept = default;

    DX::XMFLOAT2 Move(const DX::XMFLOAT2& position, const DX::XMFLOAT2& direction, const std::shared_ptr<Collider>& collider, EntityMoveData& moveData) override;
};
