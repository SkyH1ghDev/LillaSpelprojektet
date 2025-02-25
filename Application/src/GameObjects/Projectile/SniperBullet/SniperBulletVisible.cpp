#include "SniperBulletVisible.hpp"

void SniperBulletVisible::Visible(std::string& texture, DX::XMFLOAT2 position, ProjectileState entityState, float& layer, float& scale)
{
    layer = 0.5 + 0.3 * position.y / 360;
    scale = 1;
    texture = "scatter_pellet.png";
}

void SniperBulletVisible::UpdateLayer(DX::XMFLOAT2 position, float& layer)
{
    layer = 0.5 + 0.3 * position.y / 360;
}