#include "card.hpp"
#include "StatSheet.hpp"

RangeBuffCard::RangeBuffCard()
{
    this->m_type = CardType::RangeBuff;
}

void RangeBuffCard::ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    StatSheet::CreateEffect(StatType::ShotLife, 5, 10);
}

void RangeBuffCard::ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    StatSheet::CreateEffect(StatType::ShotLife, 5, 10);
}

void RangeBuffCard::ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    StatSheet::CreateEffect(StatType::ShotLife, 5, 10);
}

void RangeBuffCard::SetCardTexture(size_t cardLevel)
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