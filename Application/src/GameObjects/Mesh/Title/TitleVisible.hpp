#pragma once
#include "IMeshVisible.hpp"

class TitleVisible : public IMeshVisible
{
public:
    void Visible(std::string& texture, DX::XMFLOAT2 position, float& layer, float& scale) override;
    void UpdateLayer(DX::XMFLOAT2& position, float& layer) override;
};