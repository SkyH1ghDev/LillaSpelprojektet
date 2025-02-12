#pragma once
#include "IEntityVisible.hpp"
#include <iostream>

class PlayerVisible : public IEntityVisible
{
public:
    void Visible(std::string& texture, DX::XMFLOAT2 position, EntityState entityState, float& layer, float& scale) override;
};