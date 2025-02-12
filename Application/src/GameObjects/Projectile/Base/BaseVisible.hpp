#pragma once
#include "IProjectileVisible.hpp"
#include <iostream>

class BaseVisible : public IProjectileVisible
{
public:
    void Visible(std::string& texture, DX::XMFLOAT2 position, ProjectileState projectileState, float& layer, float& scale) override;
};