#pragma once
#include "IUIVisible.hpp"
#include <iostream>

class HealthVisible : public IUIVisible
{
public:
    void Visible(std::string& texture, float& layer, float& scale) override;
};