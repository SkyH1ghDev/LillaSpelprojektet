#include "BaseVisible.hpp"

void BaseVisible::Visible(std::string& texture, DX::XMFLOAT2 position, ProjectileState entityState, float& layer, float& scale, bool& hasDeathAnimation)
{
    layer = 0.5 + 0.3 * position.y / 360;
    scale = 0.05;
    texture = "proj.png";
}

void BaseVisible::UpdateLayer(DX::XMFLOAT2 position, float& layer)
{
    layer = 0.5 + 0.3 * position.y / 360;
}