#include "PlayerMove.hpp"
#include <iostream>


void PlayerMove::Move(DX::XMFLOAT2& m_position) {
    std::cerr << "Chester hasar sig frammåt" << std::endl;

    // Example: Move the player to the right by 1 unit
    m_position.x += 1.0f;
}