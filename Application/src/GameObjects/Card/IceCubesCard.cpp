#include "card.hpp"
#include "AbilityManager.hpp"

IceCubesCard::IceCubesCard()
{
    this->m_type = CardType::IceCubes;
}

void IceCubesCard::ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    AbilityManager::Beam(position, target, 5, 5);
}

void IceCubesCard::ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    AbilityManager::Beam(position, target, 5, 10);
}

void IceCubesCard::ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    AbilityManager::Beam(position, target, 5, 15);
}

void IceCubesCard::SetCardTexture(size_t cardLevel)
{
    switch (cardLevel) {
    case 1:
        this->m_textureName = "ice_cubes_lvl1.png";
        break;
    case 2:
        this->m_textureName = "ice_cubes_lvl2.png";
        break;
    case 3:
        this->m_textureName = "ice_cubes_lvl3.png";
        break;
    default:
        this->m_textureName = "card_basic.png";
        break;
    }
}