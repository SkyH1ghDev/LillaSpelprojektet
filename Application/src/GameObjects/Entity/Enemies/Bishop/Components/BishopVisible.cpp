#include "BishopVisible.hpp"

void BishopVisible::Visible(std::string& texture, DX::XMFLOAT2 position, EntityState entityState, float& layer, float& scale)
{
    switch (entityState) {
    case EntityState::Spawning:
        texture = "bishop_spawn_bilinear.apng";
        break;
    case EntityState::Dying:
        texture = "bishop_death";
        break;
    case EntityState::TakingDamage:
        texture = "bishop_damage";
        break;
    default:
        texture = "bishop_idle";
        break;
    }
    
    layer = 0.5 + position.y * 0.3 / 360;
    scale = 0.25;
}

void BishopVisible::UpdateLayer(DX::XMFLOAT2 position, float& layer)
{
    layer = 0.5 + position.y * 0.3 / 360;
}
