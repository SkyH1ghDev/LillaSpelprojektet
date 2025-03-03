#include "card.hpp"
#include "AbilityManager.hpp"
#include "StatSheet.hpp"

SniperCard::SniperCard()
{
    this->m_type = CardType::Sniper;
}

void SniperCard::ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    AbilityManager::SniperShot(position, target, 600, 3);
}

void SniperCard::ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    AbilityManager::SniperShot(position, target, 600, 4);
}

void SniperCard::ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    AbilityManager::SniperShot(position, target, 600, 5);
}

void SniperCard::SetCardTexture(size_t cardLevel)
{
    switch (cardLevel) {
    case 1:
        this->m_textureName = "rune_shard_lvl1.png";
        break;
    case 2:
        this->m_textureName = "rune_shard_lvl2.png";
        break;
    case 3:
        this->m_textureName = "rune_shard_lvl3.png";
        break;
    default:
        this->m_textureName = "card_basic.png";
        break;
    }
}