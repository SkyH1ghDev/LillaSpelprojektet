#include "BladeMove.hpp"

DX::XMFLOAT2 BladeMove::Move(const DX::XMFLOAT2& m_position, const DX::XMFLOAT2& m_direction, float velocity)
{
    DX::XMFLOAT2 newPosition;
    newPosition.x = m_position.x + m_direction.x * (velocity * Clock::GetDeltaTime());
    newPosition.y = m_position.y + m_direction.y * (velocity * Clock::GetDeltaTime());
    return newPosition;
}
