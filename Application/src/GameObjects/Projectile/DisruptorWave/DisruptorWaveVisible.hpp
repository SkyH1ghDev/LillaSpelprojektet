#pragma once
#include "IProjectileVisible.hpp"
#include <iostream>

class DisruptorWaveVisible : public IProjectileVisible
{
public:
    void Visible(std::string& texture, DX::XMFLOAT2 position, ProjectileState projectileState, float& layer, float& scale, bool& hasDeathAnimation) override;
    void UpdateLayer(DX::XMFLOAT2 position, float& layer) override;
};