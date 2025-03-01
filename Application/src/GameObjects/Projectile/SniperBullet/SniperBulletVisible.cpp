#include "SniperBulletVisible.hpp"

void SniperBulletVisible::Visible(std::string& texture, DX::XMFLOAT2 position, ProjectileState entityState, float& layer, float& scale, bool& hasDeathAnimation)
{
    hasDeathAnimation = true;
    layer = 0.5 + 0.3 * position.y / 360;
    scale = 1.2f;
    switch (entityState)
    {
    case ProjectileState::Exploding:
        texture = "rune_shard_death";
        break;
    default:
        texture = "rune_shard";
        break;
    }
}

void SniperBulletVisible::UpdateLayer(DX::XMFLOAT2 position, float& layer)
{
    layer = 0.5 + 0.3 * position.y / 360;
}