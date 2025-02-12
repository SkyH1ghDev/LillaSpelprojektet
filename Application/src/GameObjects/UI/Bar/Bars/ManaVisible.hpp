#pragma once
#include "IUIVisible.hpp"
#include <iostream>

class ManaVisible : public IUIVisible
{
public:
    void Visible(std::string& texture, float& layer, float& scale) override;
};