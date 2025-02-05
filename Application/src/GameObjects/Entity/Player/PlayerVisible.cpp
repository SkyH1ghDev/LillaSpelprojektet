#include "PlayerVisible.hpp"

void PlayerVisible::Visible(std::string& texture, EntityState entityState)
{
    switch (entityState) {
    case EntityState::WalkUp:
        texture = "chesster_backwards_v2.png";
        break;
    case EntityState::WalkDown:
        texture = "chesster_forwards_v2.png";
        break;
    case EntityState::WalkRight:
        texture = "chesster_right_v1.png";
        break;
    case EntityState::WalkLeft:
        texture = "chesster_left_v1.png";
        break;
    default:
        texture = "chesster_forwards_v2.png";
        break;
    }
}