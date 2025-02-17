#pragma once
#include "IEntityVisible.hpp"
#include <iostream>

class EnemyVisible : public IEntityVisible
{
public:
    void Visible(std::string& texture, DX::XMFLOAT2 position, EntityState entityState, float& layer, float& scale) override;
    void UpdateLayer(DX::XMFLOAT2 position, float& layer) override;
};