#include "CardManager.hpp"

#include <iostream>

CardManager::CardManager()
{
    m_cardObjects.push_back(std::make_shared<ShotgunCard>());
    m_cardObjects.push_back(std::make_shared<SpreadCard>());
    m_cardObjects.push_back(std::make_shared<HealCard>());
}

std::shared_ptr<ICard> CardManager::GetCard(CardType cardType)
{
    switch (cardType) {
    case CardType::Shotgun:
        return m_cardObjects[0];
        break;
    case CardType::Spread:
        return m_cardObjects[1];
        break;
    case CardType::Heal:
        return m_cardObjects[2];
    default:
        std::cerr << "unknonwn cardtype in cardManager";
    }
}

std::vector<std::shared_ptr<ICard>> CardManager::GetCardObjects()
{
    return m_cardObjects;
}

std::string CardManager::GetCardTexture()
{
    m_cardObjects[0].get()->GetType();
    return m_cardObjects[0].get()->GetCardTexture();
}





