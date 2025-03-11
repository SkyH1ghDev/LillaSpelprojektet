#include "Card.hpp"
#include "AbilityManager.hpp"
#include <iostream>

ShotgunCard::ShotgunCard()
{
    this->m_type = CardType::Shotgun;
}

void ShotgunCard::ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target) {
    AbilityManager::Shotgun(position, target, 8, 0.4f, 225, 10);
}

void ShotgunCard::ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target) {
    AbilityManager::Shotgun(position, target, 11, 0.4f, 225, 9);
}

void ShotgunCard::ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target) {
    AbilityManager::Shotgun(position, target, 14, 0.4f, 225, 7);
}

void ShotgunCard::SetCardTexture(size_t cardLevel)
{
    switch (cardLevel) {
    case 1:
        this->m_textureName = "card_scatter_lvl1.png";
        break;
    case 2:
        this->m_textureName = "card_scatter_lvl2.png";
        break;
    case 3:
        this->m_textureName = "card_scatter_lvl3.png";
        break;
    default:
        this->m_textureName = "card_basic.png";
        break;
    }
}
