#include "MagicMissileVisible.hpp"

void MagicMissileVisible::Visible(std::string& texture, DX::XMFLOAT2 position, ProjectileState entityState, float& layer, float& scale, bool& hasDeathAnimation)
{
    hasDeathAnimation = true;

    layer = 0.5 + 0.3 * position.y / 360;

    scale = 1;
    switch (entityState)
    {
    case ProjectileState::Exploding:
        texture = "magic_missile_death";
        break;
    default:
        texture = "magic_missile";
        break;
    }

}

void MagicMissileVisible::UpdateLayer(DX::XMFLOAT2 position, float& layer)
{
    layer = 0.5 + 0.3 * position.y / 360;
}