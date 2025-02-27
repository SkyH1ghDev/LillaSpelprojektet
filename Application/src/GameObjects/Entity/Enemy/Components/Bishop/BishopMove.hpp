#pragma once
#include "IEntityMove.hpp"

class BishopMove : public IEntityMove
{
public:
    DX::XMFLOAT2 Move(const DX::XMFLOAT2& m_position, const DX::XMFLOAT2& m_direction, const std::shared_ptr<Collider>& collider, bool dashing) override;
};
