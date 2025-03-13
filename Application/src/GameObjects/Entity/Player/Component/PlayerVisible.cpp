#include "PlayerVisible.hpp"

void PlayerVisible::Visible(std::string& texture, DX::XMFLOAT2 position, EntityState entityState, float& layer, float& scale)
{

    layer = 0.5 + position.y * 0.3 / 360;
    scale = 0.20;

    switch (entityState) {
    case EntityState::WalkUp:
        texture = "chesster_back_idle";
        break;
    case EntityState::WalkDown:
        texture = "chesster_front_idle";
        break;
    case EntityState::WalkRight:
        texture = "chesster_right_idle";
        break;
    case EntityState::WalkLeft:
        texture = "chesster_left_idle";
        break;
    case EntityState::Spawning:
        texture = "chesster_front_idle";
        break;
    case EntityState::Dashing:
        switch (this->m_lastState) {
        case EntityState::WalkUp:
            texture = "chesster_back_dash.apng";
            break;
        case EntityState::WalkDown:
            texture = "chesster_front_dash.apng";
            break;
        case EntityState::WalkRight:
            texture = "chesster_right_dash.apng";
            break;
        case EntityState::WalkLeft:
            texture = "chesster_left_dash.apng";
            break;
        case EntityState::Dashing:
            break;
        default:
            texture = "chesster_front_dash.apng";
            break;
        }
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
        texture = "chesster_death";
        break;
    case EntityState::Dead:
        texture = "chesster_dead.png";
        break;
    default:
        switch (this->m_lastState)
        {
        case EntityState::WalkUp:
            texture = "chesster_back_idle";
            break;
        case EntityState::WalkDown:
            texture = "chesster_front_idle";
            break;
        case EntityState::WalkRight:
            texture = "chesster_right_idle";
            break;
        case EntityState::WalkLeft:
            texture = "chesster_left_idle";
            break;
        default:
            break;
        }
    }
    if (entityState != EntityState::Dashing && entityState != EntityState::Base)
        this->m_lastState = entityState;
}

void PlayerVisible::UpdateLayer(DX::XMFLOAT2 position, float& layer)
{
    layer = 0.5 + position.y * 0.3 / 360;
}
