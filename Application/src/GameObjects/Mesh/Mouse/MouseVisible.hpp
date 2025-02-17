#pragma once
#include "IMeshVisible.hpp"
#include <iostream>

class MouseVisible : public IMeshVisible
{
public:
    void Visible(std::string& texture, DX::XMFLOAT2 position, float& layer, float& scale) override;
    void UpdateLayer(DX::XMFLOAT2 position, float& layer) override;
};