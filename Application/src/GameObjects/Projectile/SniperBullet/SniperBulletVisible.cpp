#include "SniperBulletVisible.hpp"

void SniperBulletVisible::Visible(std::string& texture, DX::XMFLOAT2 position, ProjectileState entityState, float& layer, float& scale, bool& hasDeathAnimation)
{
    layer = 0.5 + 0.3 * position.y / 360;
    scale = 1.0;
    texture = "sniper_bullet.apng";
}

void SniperBulletVisible::UpdateLayer(DX::XMFLOAT2 position, float& layer)
{
    layer = 0.5 + 0.3 * position.y / 360;
}