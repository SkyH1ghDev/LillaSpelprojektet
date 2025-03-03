#include "RookAltVisible.hpp"

void RookAltVisible::Visible(std::string& texture, DX::XMFLOAT2 position, EntityState entityState, float& layer, float& scale)
{
    switch (entityState) {
    case EntityState::WalkUp:
        texture = "rook_back.png";
        break;
    case EntityState::WalkDown:
        texture = "rook_front.png";
        break;
    case EntityState::WalkRight:
        texture = "rook_right.png";
        break;
    case EntityState::WalkLeft:
        texture = "rook_left.png";
        break;
    case EntityState::TakingDamage:
        texture = "rook_damage";
        break;
    case EntityState::Spawning:
        texture = "rook_spawn";
        break;
    case EntityState::Dying:
        texture = "rook_death";
        break;
    case EntityState::Stunned:
        texture = "rook_stun";
        break;
    default:
        texture = "rook_front.png";
        break;
    }
    this->m_lastState = entityState;
    
    layer = 0.5 + position.y * 0.3 / 360;
    scale = 0.25;
}

void RookAltVisible::UpdateLayer(DX::XMFLOAT2 position, float& layer)
{
    layer = 0.5 + position.y * 0.3 / 360;
}
