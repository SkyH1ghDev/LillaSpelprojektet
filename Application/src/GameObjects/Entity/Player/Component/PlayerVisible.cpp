#include "PlayerVisible.hpp"

void PlayerVisible::Visible(std::string& texture, DX::XMFLOAT2 position, EntityState entityState, float& layer, float& scale)
{

    layer = 0.5 + position.y * 0.3 / 360;
    scale = 0.20;

    switch (entityState) {
    case EntityState::WalkUp:
        texture = "bishopMockupTen.apng";
        break;
    case EntityState::WalkDown:
        texture = "chesster_forward_v3.png";
        break;
    case EntityState::WalkRight:
        texture = "chesster_right_v2.png";
        break;
    case EntityState::WalkLeft:
        texture = "chesster_left_v2.png";
        break;
    case EntityState::TakingDamage:    
        switch (this->m_lastState) {
        case EntityState::WalkUp:
            texture = "Toe.png";
            break;
        case EntityState::WalkDown:
            texture = "Toe.png";
            break;
        case EntityState::WalkRight:
            texture = "Toe.png";
            break;
        case EntityState::WalkLeft:
            texture = "Toe.png";
            break;
        default:
            texture = "Toe.png";
            break;
        }
        break;
    default:
        texture = "chesster_forward_v3.png";
        break;
    }
    this->m_lastState = entityState;
}

void PlayerVisible::UpdateLayer(DX::XMFLOAT2 position, float& layer)
{
    layer = 0.5 + position.y * 0.3 / 360;
}
