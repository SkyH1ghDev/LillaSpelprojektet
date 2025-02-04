#include "PlayerMove.hpp"
#include <iostream>


void PlayerMove::Move(DX::XMFLOAT2& m_position, DX::XMFLOAT2& m_direction) {
    DX::XMVECTOR position = XMLoadFloat2(&m_position);
    DX::XMVECTOR direction = XMLoadFloat2(&m_direction);

    // Perform the movement operation
    DX::XMVECTOR movement = DX::XMVectorScale(direction, 0.2f);
    position = DX::XMVectorAdd(position, movement);

    // Store the result back into m_position
    XMStoreFloat2(&m_position, position);
}
