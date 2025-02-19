#pragma once
#include "IUIVisible.hpp"
#include <iostream>

class ManaReadyVisible : public IUIVisible
{
public:
    void Visible(std::string& texture, float& layer, float& scale, DirectX::XMFLOAT2& position) override;
};