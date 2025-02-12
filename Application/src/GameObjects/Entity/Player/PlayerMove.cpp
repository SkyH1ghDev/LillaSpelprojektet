#include "PlayerMove.hpp"

#include <SpEngine/Clock/Clock.hpp>

DX::XMFLOAT2 PlayerMove::Move(const DX::XMFLOAT2& position, const DX::XMFLOAT2& direction) {
    DX::XMVECTOR positionXMVector = XMLoadFloat2(&position);
    DX::XMVECTOR directionXMVector = XMLoadFloat2(&direction);

    DX::XMVECTOR movement = DX::XMVectorScale(DX::XMVector2Normalize(directionXMVector), 250.0f * Clock::GetDeltaTime());
    positionXMVector = DX::XMVectorAdd(positionXMVector, movement);

    DX::XMFLOAT2 newPosition;
    DX::XMStoreFloat2(&newPosition, positionXMVector);

    if (PhysicsEngine::WallEntityXCollision(newPosition.x))
    {
        newPosition.x = position.x;
    }
    if (PhysicsEngine::WallEntityYCollision(newPosition.y))
    {
        newPosition.y = position.y;
    }

    return newPosition;
}
