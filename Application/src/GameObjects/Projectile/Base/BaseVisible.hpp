#pragma once
#include "IProjectileVisible.hpp"
#include <iostream>

class BaseVisible : public IProjectileVisible
{
public:
    void Visible(std::string& texture, ProjectileState projectileState, float& layer, float& scale) override;
};