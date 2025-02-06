#pragma once
#include "IEntityVisible.hpp"
#include <iostream>

class PlayerVisible : public IEntityVisible
{
public:
    void Visible(std::string& texture, EntityState entityState, float& layer, float& scale) override;
};