#include "FireBallVisible.hpp"

void FireBallVisible::Visible(std::string& texture, DX::XMFLOAT2 position, ProjectileState entityState, float& layer, float& scale, bool& hasDeathAnimation)
{
    hasDeathAnimation = true;
    layer = 0.5 + 0.3 * position.y / 360;
    scale = 1.0f;
    texture = "fireball";

    if (entityState == ProjectileState::Exploding)
        texture = "fireball_death";
}

void FireBallVisible::UpdateLayer(DX::XMFLOAT2 position, float& layer)
{
    layer = 0.5 + 0.3 * position.y / 360;
}