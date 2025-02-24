#include "card.hpp"
#include "GameObjects/UI/Bar/HealthBarManager.hpp"
#include "StatSheet.hpp"

void HealCard::ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
	HealthBarManager::RefillHeart(1);
    StatSheet::IncreaseHealth(1);
}

void HealCard::ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
	HealthBarManager::RefillHeart(2);
    StatSheet::IncreaseHealth(2);
}

void HealCard::ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
	HealthBarManager::RefillHeart(3);
    StatSheet::IncreaseHealth(3);
}

void HealCard::SetCardTexture(size_t cardLevel)
{
    switch (cardLevel) {
    case 1:
        this->m_textureName = "card_heal_lvl1.png";
        break;
    case 2:
        this->m_textureName = "card_heal_lvl2.png";
        break;
    case 3:
        this->m_textureName = "card_heal_lvl3.png";
        break;
    default:
        this->m_textureName = "card_basic.png";
        break;
    }
}