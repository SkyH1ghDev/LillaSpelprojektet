#pragma once
#include "IMeshVisible.hpp"
#include <iostream>

class BackgroundVisible : public IMeshVisible
{
public:
    void Visible(std::string& texture, DX::XMFLOAT2 position, float& layer, float& scale) override;
};