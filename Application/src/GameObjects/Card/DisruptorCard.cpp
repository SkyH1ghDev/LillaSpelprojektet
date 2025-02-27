#include "card.hpp"
#include "AbilityManager.hpp"
#include "StatSheet.hpp"

void DisruptorCard::ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    //AbilityManager::SniperShot(position, target, 600, 3);
}

void DisruptorCard::ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    //AbilityManager::SniperShot(position, target, 600, 4);
}

void DisruptorCard::ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    //AbilityManager::SniperShot(position, target, 600, 5);
}

void DisruptorCard::SetCardTexture(size_t cardLevel)
{
    switch (cardLevel) {
    case 1:
        this->m_textureName = "card_basic.png";
        break;
    case 2:
        this->m_textureName = "card_basic.png";
        break;
    case 3:
        this->m_textureName = "card_basic.png";
        break;
    default:
        this->m_textureName = "card_basic.png";
        break;
    }
}