#include "BishopAltVisible.hpp"

void BishopAltVisible::Visible(std::string& texture, DX::XMFLOAT2 position, EntityState entityState, float& layer, float& scale)
{
    switch (entityState) {
    case EntityState::Spawning:
        texture = "bishop_spawn_bilinear.apng";
        break;
    case EntityState::Dying:
        texture = "bishop_w_death";
        break;
    case EntityState::TakingDamage:
        texture = "bishop_w_damage";
        break;
    case EntityState::Frozen:
        texture = "bishop_w_frozen.png";
        break;
    default:
        texture = "bishop_w_idle";
        break;
    }
    
    layer = 0.5 + position.y * 0.3 / 360;
    scale = 0.25;
}

void BishopAltVisible::UpdateLayer(DX::XMFLOAT2 position, float& layer)
{
    layer = 0.5 + position.y * 0.3 / 360;
}
