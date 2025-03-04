#pragma once
#include "IEntityVisible.hpp"

class PawnAltVisible : public IEntityVisible
{
public:
    PawnAltVisible() = default;
    ~PawnAltVisible() override = default;
    PawnAltVisible(const PawnAltVisible& other) = default;
    PawnAltVisible& operator=(const PawnAltVisible& other) = default;
    PawnAltVisible(PawnAltVisible&& other) noexcept = default;
    PawnAltVisible& operator=(PawnAltVisible&& other) noexcept = default;

    void Visible(std::string& texture, DX::XMFLOAT2 position, EntityState entityState, float& layer, float& scale) override;
    void UpdateLayer(DX::XMFLOAT2 position, float& layer) override;
};
