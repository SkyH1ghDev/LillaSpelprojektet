#include "PlayerVisible.hpp"

void PlayerVisible::Visible(std::string& texture, DX::XMFLOAT2 position, EntityState entityState, float& layer, float& scale)
{

    layer = 0.5 + position.y * 0.3 / 360;
    scale = 0.20;

    switch (entityState) {
    case EntityState::WalkUp:
        texture = "chesster_back_v3.png";
        break;
    case EntityState::WalkDown:
        texture = "chesster_front_v3.png";
        break;
    case EntityState::WalkRight:
        texture = "chesster_right_v3.png";
        break;
    case EntityState::WalkLeft:
        texture = "chesster_left_v3.png";
        break;
    case EntityState::DashUp:
        texture = "chesster_back_dash.apng";
        break;
    case EntityState::DashDown:
        texture = "chesster_front_dash.apng";
        break;
    case EntityState::DashRight:
        texture = "chesster_right_dash.apng";
        break;
    case EntityState::DashLeft:
        texture = "chesster_left_dash.apng";
        break;
    case EntityState::TakingDamage:    
        switch (this->m_lastState) {
        case EntityState::WalkUp:
            texture = "chesster_back_damage.apng";
            break;
        case EntityState::WalkDown:
            texture = "chesster_front_damage.apng";
            break;
        case EntityState::WalkRight:
            texture = "chesster_right_damage.apng";
            break;
        case EntityState::WalkLeft:
            texture = "chesster_left_damage.apng";
            break;
        case EntityState::TakingDamage:
            break;
        default:
            texture = "chesster_front_damage.apng";
            break;
        }
        break;
    case EntityState::Dying:
        texture = "chesster_death_animation.apng";
        break;
    case EntityState::Dead:
        texture = "chesster_dead.png";
        break;
    default:
        texture = "chesster_front_v3.png";
        break;
    }
    this->m_lastState = entityState;
}

void PlayerVisible::UpdateLayer(DX::XMFLOAT2 position, float& layer)
{
    layer = 0.5 + position.y * 0.3 / 360;
}
