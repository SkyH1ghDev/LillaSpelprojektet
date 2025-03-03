#include "RookVisible.hpp"

void RookVisible::Visible(std::string& texture, DX::XMFLOAT2 position, EntityState entityState, float& layer, float& scale)
{
    switch (entityState) {
    case EntityState::WalkUp:
        texture = "rook_w_back_idle";
        break;
    case EntityState::WalkDown:
        texture = "rook_w_front_idle";
        break;
    case EntityState::WalkRight:
        texture = "rook_w_right_idle";
        break;
    case EntityState::WalkLeft:
        texture = "rook_w_left_idle";
        break;
    case EntityState::TakingDamage:
        texture = "rook_w_damage";
        break;
    case EntityState::Spawning:
        texture = "rook_w_spawn";
        break;
    case EntityState::Dying:
        texture = "rook_w_death";
        break;
    case EntityState::Stunned:
        texture = "rook_w_stun";
        break;
    default:
        texture = "rook_w_front_idle";
        break;
    }
    this->m_lastState = entityState;
    
    layer = 0.5 + position.y * 0.3 / 360;
    scale = 0.25;
}

void RookVisible::UpdateLayer(DX::XMFLOAT2 position, float& layer)
{
    layer = 0.5 + position.y * 0.3 / 360;
}
