#include "PawnMove.hpp"
#include <SpEngine/Clock/Clock.hpp>

DX::XMFLOAT2 PawnMove::Move(const DX::XMFLOAT2& position, const DX::XMFLOAT2& direction, const std::shared_ptr<Collider>& collider, bool dashing)
{
    DX::XMFLOAT2 newPosition = position;

    float speed = 15.0f;

    if (direction.x == -1 && direction.y == 0)
    {
        newPosition.x = newPosition.x - speed * Clock::GetDeltaTime();
    }
    if (direction.x == 1 && direction.y == 0)
    {
        newPosition.x = newPosition.x + speed * Clock::GetDeltaTime();
    }
    if (direction.x == 0 && direction.y == -1)
    {
        newPosition.y = newPosition.y - speed * Clock::GetDeltaTime();
    }
    if (direction.x == 0 && direction.y == 1)
    {
        newPosition.y = newPosition.y + speed * Clock::GetDeltaTime();
    }

    collider->UpdatePosition(newPosition);
    return newPosition;
}

