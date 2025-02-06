#pragma once
#include "IEntityVisible.hpp"
#include <iostream>

class EnemyVisible : public IEntityVisible
{
public:
    void Visible(std::string& texture, EntityState entityState, float& layer, float& scale) override;
};