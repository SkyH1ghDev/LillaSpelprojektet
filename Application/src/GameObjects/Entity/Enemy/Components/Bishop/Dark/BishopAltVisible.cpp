#include "BishopAltVisible.hpp"

void BishopAltVisible::Visible(std::string& texture, DX::XMFLOAT2 position, EntityState entityState, float& layer, float& scale)
{
    switch (entityState) {
    case EntityState::Spawning:
        texture = "bishop_b_spawn";
        break;
    case EntityState::Dying:
        texture = "bishop_b_death";
        break;
    case EntityState::TakingDamage:
        texture = "bishop_b_damage";
        break;
    default:
        texture = "bishop_b_idle";
        break;
    }
    
    layer = 0.5 + position.y * 0.3 / 360;
    scale = 0.25;
}

void BishopAltVisible::UpdateLayer(DX::XMFLOAT2 position, float& layer)
{
    layer = 0.5 + position.y * 0.3 / 360;
}
