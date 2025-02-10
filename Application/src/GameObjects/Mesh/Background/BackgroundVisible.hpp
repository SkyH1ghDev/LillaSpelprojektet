#pragma once
#include "IMeshVisible.hpp"
#include <iostream>

class BackgroundVisible : public IMeshVisible
{
public:
    void Visible(std::string& texture, float& layer, float& scale) override;
};