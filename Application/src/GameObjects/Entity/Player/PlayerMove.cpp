#include "PlayerMove.hpp"

#include <SpEngine/Clock/Clock.hpp>

DX::XMFLOAT2 PlayerMove::Move(const DX::XMFLOAT2& position, const DX::XMFLOAT2& direction) {
    DX::XMVECTOR positionXMVector = XMLoadFloat2(&position);
    DX::XMVECTOR directionXMVector = XMLoadFloat2(&direction);

    // Perform the movement operation
    const DX::XMVECTOR movement = DX::XMVectorScale(directionXMVector, 250.0f * Clock::GetDeltaTime());
    positionXMVector = DX::XMVectorAdd(positionXMVector, movement);

    DX::XMFLOAT2 newPosition;
    DX::XMStoreFloat2(&newPosition, positionXMVector);

    return newPosition;
}
