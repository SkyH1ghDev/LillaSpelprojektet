#include "card.hpp"
#include "StatSheet.hpp"
#include "AbilityManager.hpp"
#include "playerinfo.hpp"

RangeBuffCard::RangeBuffCard()
{
    this->m_type = CardType::RangeBuff;
}

void RangeBuffCard::ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    DirectX::XMFLOAT2 dir = { 1,0 };
    StatSheet::CreateEffect(StatType::ShotSpeed, 5, 100);
    AbilityManager::longEffect(position, dir, 1, 5, 0, 0);
}

void RangeBuffCard::ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    DirectX::XMFLOAT2 dir = { 1,0 };
    StatSheet::CreateEffect(StatType::ShotSpeed, 5, 225);
    AbilityManager::longEffect(position, dir, 1, 5, 0, 0);
}

void RangeBuffCard::ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    DirectX::XMFLOAT2 dir = { 1,0 };
    StatSheet::CreateEffect(StatType::ShotSpeed, 5, 500);
    AbilityManager::longEffect(position, dir, 1, 5, 0, 0);
}

void RangeBuffCard::SetCardTexture(size_t cardLevel)
{
    switch (cardLevel) {
    case 1:
        this->m_textureName = "range_buff_lvl1.png";
        break;
    case 2:
        this->m_textureName = "range_buff_lvl2.png";
        break;
    case 3:
        this->m_textureName = "range_buff_lvl3.png";
        break;
    default:
        this->m_textureName = "card_basic.png";
        break;
    }
}