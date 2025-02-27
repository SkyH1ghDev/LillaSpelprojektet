#include "DisruptorWaveVisible.hpp"

void DisruptorWaveVisible::Visible(std::string& texture, DX::XMFLOAT2 position, ProjectileState entityState, float& layer, float& scale)
{
    layer = 0.5 + 0.3 * position.y / 360;
    scale = 1.0;
    texture = "disruptor_wave_animation_base.apng";
}

void DisruptorWaveVisible::UpdateLayer(DX::XMFLOAT2 position, float& layer)
{
    layer = 0.5 + 0.3 * position.y / 360;
}