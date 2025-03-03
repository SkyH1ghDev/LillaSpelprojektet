#include "BishopVisible.hpp"

void BishopVisible::Visible(std::string& texture, DX::XMFLOAT2 position, EntityState entityState, float& layer, float& scale)
{
    switch (entityState) {
    case EntityState::Spawning:
        texture = "bishop_w_spawn";
        break;
    case EntityState::Dying:
        texture = "bishop_w_death";
        break;
    case EntityState::TakingDamage:
        texture = "bishop_w_damage";
        break;
    default:
        texture = "bishop_w_idle";
        break;
    }
    
    layer = 0.5 + position.y * 0.3 / 360;
    scale = 0.25;
}

void BishopVisible::UpdateLayer(DX::XMFLOAT2 position, float& layer)
{
    layer = 0.5 + position.y * 0.3 / 360;
}
