#include "EnemyVisible.hpp"

void EnemyVisible::Visible(std::string& texture, DX::XMFLOAT2 position, EntityState entityState, float& layer, float& scale)
{
    texture = "bishop.png";
    layer = 0.5 + position.y * 0.3 / 360;
    scale = 0.3;
}

void EnemyVisible::UpdateLayer(DX::XMFLOAT2 position, float& layer)
{
    layer = 0.5 + position.y * 0.3 / 360;
}
