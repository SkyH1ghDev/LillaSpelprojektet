#include "EnemyVisible.hpp"

void EnemyVisible::Visible(std::string& texture, DX::XMFLOAT2 position, EntityState entityState, float& layer, float& scale)
{
    switch (entityState) {
    case EntityState::Spawning:
        texture = "bishop_spawn_bilinear.apng";
        break;
    default:
        texture = "bishop_v2.png";
        break;
    }
    
    layer = 0.5 + position.y * 0.3 / 360;
    scale = 0.25;
}

void EnemyVisible::UpdateLayer(DX::XMFLOAT2 position, float& layer)
{
    layer = 0.5 + position.y * 0.3 / 360;
}
