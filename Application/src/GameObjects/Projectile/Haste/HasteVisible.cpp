#include "HasteVisible.hpp"

void HasteVisible::Visible(std::string& texture, DX::XMFLOAT2 position, ProjectileState entityState, float& layer, float& scale, bool& hasDeathAnimation)
{
    layer = 0.5 + 0.3 * position.y / 360;
    scale = 1.0f;
    texture = "longshot_effect";
    hasDeathAnimation = false;
}

void HasteVisible::UpdateLayer(DX::XMFLOAT2 position, float& layer)
{
    layer = 0.5 + 0.3 * position.y / 360;
}