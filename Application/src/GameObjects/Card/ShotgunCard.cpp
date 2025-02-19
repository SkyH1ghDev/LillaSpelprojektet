#include "Card.hpp"
#include "AbilityManager.hpp"
#include <iostream>



void ShotgunCard::ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target) {
    AbilityManager::Shotgun(position, target, 7, 3, 150, 4);
}

void ShotgunCard::ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target) {
    AbilityManager::Shotgun(position, target, 10, 3, 250, 6);
}

void ShotgunCard::ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target) {
    AbilityManager::Shotgun(position, target, 12, 3, 400, 8);
}

void ShotgunCard::SetCardTexture(size_t cardLevel)
{
    switch (cardLevel) {
    case 1:
        this->m_textureName = "shotgun_lvl1.png";
        break;
    case 2:
        this->m_textureName = "shotgun_lvl2.png";
        break;
    case 3:
        this->m_textureName = "shotgun_lvl3.png";
        break;
    default:
        std::cerr << "unknown cardlevel" << std::endl;
        break;
    }
}
