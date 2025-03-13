#include "card.hpp"
#include "AbilityManager.hpp"
#include "StatSheet.hpp"

BladeCard::BladeCard()
{
    this->m_type = CardType::Blade;
}

void BladeCard::ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    AbilityManager::Blade(position, target, 10, 10);
}

void BladeCard::ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    AbilityManager::Blade(position, target, 10, 15);
}

void BladeCard::ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    AbilityManager::Blade(position, target, 10, 20);
}

void BladeCard::SetCardTexture(size_t cardLevel)
{
    switch (cardLevel) {
    case 1:
        this->m_textureName = "blade_lvl1.png";
        break;
    case 2:
        this->m_textureName = "blade_lvl2.png";
        break;
    case 3:
        this->m_textureName = "blade_lvl3.png";
        break;
    default:
        this->m_textureName = "card_basic.png";
        break;
    }
}