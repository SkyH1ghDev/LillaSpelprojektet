#pragma once
#include "IUIVisible.hpp"

class HeartFullVisible : public IUIVisible
{
public:
    void Visible(std::string& texture, float& layer, float& scale, DirectX::XMFLOAT2& position) override;
};