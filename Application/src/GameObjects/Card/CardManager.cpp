#include "CardManager.hpp"

#include <iostream>



CardManager::CardManager()
{
    m_cardObjects.push_back(std::make_shared<ShotgunCard>());
    m_cardObjects.push_back(std::make_shared<SpreadCard>());
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
    default:
        std::cerr << "unknonwn cardtype in cardManager";
    }
}

std::vector<std::shared_ptr<ICard>> CardManager::GetCardObjects()
{
    return m_cardObjects;
}





