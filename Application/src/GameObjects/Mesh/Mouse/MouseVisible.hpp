#pragma once
#include "IMeshVisible.hpp"
#include <iostream>

class MouseVisible : public IMeshVisible
{
public:
    void Visible(std::string& texture, float& layer, float& scale) override;
};