#include "CardManager.hpp"

#include <iostream>

std::vector<std::shared_ptr<ICard>> CardManager::m_cardObjects = {};

void CardManager::AttachCard(std::shared_ptr<ICard> Card)
{
    if (const auto& it = std::ranges::find(m_cardObjects, Card); it == m_cardObjects.end())
    {
        m_cardObjects.push_back(Card);
    }
}

std::vector<std::shared_ptr<ICard>> CardManager::GetCardObjects()
{
    return m_cardObjects;
}





