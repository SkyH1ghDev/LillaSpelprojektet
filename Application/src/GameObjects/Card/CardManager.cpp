#include "CardManager.hpp"
#include <iostream>

std::vector<std::shared_ptr<ICard>> CardManager::m_cardObjects;
size_t CardManager::m_currentindex = 0;

void CardManager::Initialize()
{
    if (m_cardObjects.empty()) {
        m_cardObjects.push_back(std::make_shared<ShotgunCard>());
        m_cardObjects.push_back(std::make_shared<SpreadCard>());
        m_cardObjects.push_back(std::make_shared<HealCard>());
        m_cardObjects.push_back(std::make_shared<SniperCard>());
        m_cardObjects.push_back(std::make_shared<DisruptorCard>());
        m_cardObjects.push_back(std::make_shared<RangeBuffCard>());
        m_cardObjects.push_back(std::make_shared<AttackSpeedBuffCard>());
        m_cardObjects.push_back(std::make_shared<BladeCard>());
        m_cardObjects.push_back(std::make_shared<MagicMissileCard>());
        m_cardObjects.push_back(std::make_shared<IceCubesCard>());
    }
}

std::shared_ptr<ICard> CardManager::GetCard(CardType cardType)
{
    Initialize();
    switch (cardType) {
    case CardType::Shotgun:
        return m_cardObjects[0];
        break;
    case CardType::Spread:
        return m_cardObjects[1];
        break;
    case CardType::Heal:
        return m_cardObjects[2];
        break;
    case CardType::Sniper:
        return m_cardObjects[3];
        break;
    case CardType::Disruptor:
        return m_cardObjects[4];
        break;
    case CardType::RangeBuff:
        return m_cardObjects[5];
        break;
    case CardType::AttackSpeedBuff:
        return m_cardObjects[6];
        break;
    case CardType::Blade:
        return m_cardObjects[7];
        break;
    case CardType::MagicMissile:
        return m_cardObjects[8];
        break;
    case CardType::IceCubes:
        return m_cardObjects[9];
        break;
    default:
        std::cerr << "Unknown card type in CardManager";
        return nullptr;
    }
}

std::vector<std::shared_ptr<ICard>> CardManager::GetCardObjects()
{
    Initialize();
    return m_cardObjects;
}

std::string CardManager::GetCardTexture()
{
    Initialize();
    return m_cardObjects[0]->GetCardTexture();
}

void CardManager::Cleanup()
{
    m_cardObjects.clear();
    m_currentindex = 0;
}