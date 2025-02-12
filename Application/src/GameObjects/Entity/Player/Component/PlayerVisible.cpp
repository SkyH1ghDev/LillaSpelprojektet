#include "PlayerVisible.hpp"

void PlayerVisible::Visible(std::string& texture, DX::XMFLOAT2 position, EntityState entityState, float& layer, float& scale)
{

    layer = 0.5 + position.y * 0.3 / 360;
    scale = 0.25;
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

void PlayerVisible::UpdateLayer(DX::XMFLOAT2 position, float& layer)
{
    layer = 0.5 + position.y * 0.3 / 360;
}
