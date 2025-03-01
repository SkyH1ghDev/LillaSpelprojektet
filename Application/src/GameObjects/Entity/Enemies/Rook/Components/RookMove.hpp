#pragma once
#include "IEntityMove.hpp"

class RookMove : public IEntityMove
{
public:
    DX::XMFLOAT2 Move(const DX::XMFLOAT2& m_position, const DX::XMFLOAT2& m_direction, bool& dashing, std::shared_ptr<Collider> m_collider, bool& isStunned) override;
private:
    bool isDashing = false;
    DX::XMFLOAT2 dashDirection;
    float dashSpeed = 0.0f;
    float maxDashSpeed = 800.0f;
    float dashAcceleration = 2000.0f;
    float m_moveSpeed = 100.0f;
};
