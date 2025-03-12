#include "card.hpp"
#include "AbilityManager.hpp"

IceBeamCard::IceBeamCard()
{
    this->m_type = CardType::IceBeam;
}

void IceBeamCard::ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    AbilityManager::Beam(position, target, 4, 15);
}

void IceBeamCard::ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    AbilityManager::Beam(position, target, 4, 20);
}

void IceBeamCard::ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    AbilityManager::Beam(position, target, 4, 30);
}

void IceBeamCard::SetCardTexture(size_t cardLevel)
{
    switch (cardLevel) {
    case 1:
        this->m_textureName = "ice_beam_lvl1.png";
        break;
    case 2:
        this->m_textureName = "ice_beam_lvl2.png";
        break;
    case 3:
        this->m_textureName = "ice_beam_lvl3.png";
        break;
    default:
        this->m_textureName = "card_basic.png";
        break;
    }
}