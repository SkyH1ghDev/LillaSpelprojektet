#include "card.hpp"
#include "AbilityManager.hpp"

DisruptorCard::DisruptorCard()
{
    this->m_type = CardType::Disruptor;
}

void DisruptorCard::ActivateLvl1(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    AbilityManager::DisruptorWave(position, target, 0.5f);
}

void DisruptorCard::ActivateLvl2(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    AbilityManager::DisruptorWave(position, target, 0.7f);
}

void DisruptorCard::ActivateLvl3(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    AbilityManager::DisruptorWave(position, target, 1.0f);
}

void DisruptorCard::SetCardTexture(size_t cardLevel)
{
    switch (cardLevel) {
    case 1:
        this->m_textureName = "disruptor_wave_lvl1.png";
        break;
    case 2:
        this->m_textureName = "disruptor_wave_lvl2.png";
        break;
    case 3:
        this->m_textureName = "disruptor_wave_lvl3.png";
        break;
    default:
        this->m_textureName = "card_basic.png";
        break;
    }
}