#include "PawnMove.hpp"
#include <SpEngine/Clock/Clock.hpp>

DX::XMFLOAT2 PawnMove::Move(const DX::XMFLOAT2& m_position, const DX::XMFLOAT2& m_direction, bool& dashing, std::shared_ptr<Collider> m_collider, bool& isStunned)
{
    float movementSpeed = 25.0f * Clock::GetDeltaTime();
    m_collider->UpdatePosition({ m_position.x, m_position.y - 12 });
    
    return { m_position.x + m_direction.x * movementSpeed, m_position.y + m_direction.y * movementSpeed };
}

