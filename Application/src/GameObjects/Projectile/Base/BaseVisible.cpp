#include "BaseVisible.hpp"

void BaseVisible::Visible(std::string& texture, DX::XMFLOAT2 position, ProjectileState entityState, float& layer, float& scale)
{
    layer = 0.5 + 0.3 * position.y / 360;
    scale = 0.05;
    texture = "proj.png";
}
