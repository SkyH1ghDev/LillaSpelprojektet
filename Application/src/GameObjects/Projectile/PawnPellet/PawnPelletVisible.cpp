#include "PawnPelletVisible.hpp"

void PawnPelletVisible::Visible(std::string& texture, DX::XMFLOAT2 position, ProjectileState entityState, float& layer, float& scale)
{
    layer = 0.5 + 0.3 * position.y / 360;
    scale = 1.0;
    switch (entityState)
    {
    case ProjectileState::Exploding:
        texture = "BlueBulletHit.apng";
        break;
    default:
        texture = "BlueBullet_noParticle.apng";
        break;
    }
}

void PawnPelletVisible::UpdateLayer(DX::XMFLOAT2 position, float& layer)
{
    layer = 0.5 + 0.3 * position.y / 360;
}