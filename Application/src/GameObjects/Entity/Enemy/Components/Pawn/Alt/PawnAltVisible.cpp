#include "PawnAltVisible.hpp"

void PawnAltVisible::Visible(std::string& texture, DX::XMFLOAT2 position, EntityState entityState, float& layer, float& scale)
{
    switch (entityState) {
    case EntityState::Spawning:
        texture = "pawn_spawn";
        break;
    case EntityState::Dying:
        texture = "pawn_death";
        break;
    case EntityState::TakingDamage:
        texture = "pawn_damage";
        break;
    default:
        texture = "pawn_front.png";
        break;
    }
    
    layer = 0.5 + position.y * 0.3 / 360;
    scale = 0.25;
}

void PawnAltVisible::UpdateLayer(DX::XMFLOAT2 position, float& layer)
{
    layer = 0.5 + position.y * 0.3 / 360;
}
