#pragma once
#include "IMeshVisible.hpp"
#include <iostream>

class WeaponVisible : public IMeshVisible
{
public:
    void Visible(std::string& texture, float& layer, float& scale) override;
};