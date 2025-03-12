#include "IceBeamVisible.hpp"

void IceBeamVisible::Visible(std::string& texture, DX::XMFLOAT2 position, ProjectileState entityState, float& layer, float& scale, bool& hasDeathAnimation)
{
    hasDeathAnimation = true;

    layer = 0.5 + 0.3 * position.y / 360;

    scale = 1;
    switch (entityState)
    {
    case ProjectileState::Exploding:
        texture = "ice_beam_death";
        break;
    default:
        texture = "ice_beam";
        break;
    }

}

void IceBeamVisible::UpdateLayer(DX::XMFLOAT2 position, float& layer)
{
    layer = 0.5 + 0.3 * position.y / 360;
}