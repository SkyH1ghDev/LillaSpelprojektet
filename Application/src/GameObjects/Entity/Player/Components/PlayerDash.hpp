#pragma once
#include "IEntityDash.hpp"


class PlayerDash : public IEntityDash
{
public:
    PlayerDash() = default;
    ~PlayerDash() override = default;
    PlayerDash(const PlayerDash& other) = default;
    PlayerDash& operator=(const PlayerDash& other) = default;
    PlayerDash(PlayerDash&& other) noexcept = default;
    PlayerDash& operator=(PlayerDash&& other) noexcept = default;

    DX::XMFLOAT2 Dash(const DX::XMFLOAT2& position, const DX::XMFLOAT2& direction, const std::shared_ptr<Collider>& collider, const bool& dashInput, EntityMoveData& moveData) override;

};
