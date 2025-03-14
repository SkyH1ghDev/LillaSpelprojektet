#include "HealVisible.hpp"

void HealVisible::Visible(std::string& texture, DX::XMFLOAT2 position, ProjectileState entityState, float& layer, float& scale, bool& hasDeathAnimation)
{
    layer = 0.5 + 0.3 * position.y / 360;
    scale = 1.0f;
    texture = "heal_effect";
    hasDeathAnimation = false;
}

void HealVisible::UpdateLayer(DX::XMFLOAT2 position, float& layer)
{
    layer = 0.5 + 0.3 * position.y / 360;
}