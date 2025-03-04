#include "card.hpp"
#include "StatSheet.hpp"

AttackSpeedBuffCard::AttackSpeedBuffCard()
{
    this->m_type = CardType::AttackSpeedBuff;
}

void AttackSpeedBuffCard::ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    float currentAtkSpd = StatSheet::GetShotDelay();
    float maxAtkSpd = 0.5f;

    StatSheet::CreateEffect(StatType::ShotDelay, 5, maxAtkSpd - currentAtkSpd);
    StatSheet::CreateEffect(StatType::ShotDelay, 5, -0.1f);
}

void AttackSpeedBuffCard::ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    float currentAtkSpd = StatSheet::GetShotDelay();
    float maxAtkSpd = 0.5f;

    StatSheet::CreateEffect(StatType::ShotDelay, 5, maxAtkSpd - currentAtkSpd);
    StatSheet::CreateEffect(StatType::ShotDelay, 5, -0.2f);
}

void AttackSpeedBuffCard::ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    float currentAtkSpd = StatSheet::GetShotDelay();
    float maxAtkSpd = 0.5f;

    StatSheet::CreateEffect(StatType::ShotDelay, 5, maxAtkSpd - currentAtkSpd);
    StatSheet::CreateEffect(StatType::ShotDelay, 5, -0.3f);
}

void AttackSpeedBuffCard::SetCardTexture(size_t cardLevel)
{
    switch (cardLevel) {
    case 1:
        this->m_textureName = "attack_speed_buff_lvl1.png";
        break;
    case 2:
        this->m_textureName = "attack_speed_buff_lvl2.png";
        break;
    case 3:
        this->m_textureName = "attack_speed_buff_lvl3.png";
        break;
    default:
        this->m_textureName = "card_basic.png";
        break;
    }
}