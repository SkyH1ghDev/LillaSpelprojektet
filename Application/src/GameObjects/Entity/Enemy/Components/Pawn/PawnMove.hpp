#pragma once
#include "IEntityMove.hpp"

class PawnMove : public IEntityMove
{
public:
    DX::XMFLOAT2 Move(const DX::XMFLOAT2& m_position, const DX::XMFLOAT2& m_direction, bool& dashing, std::shared_ptr<Collider> m_collider, bool& isStunned) override;
};
