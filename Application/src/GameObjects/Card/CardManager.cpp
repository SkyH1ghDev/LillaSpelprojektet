#include "CardManager.hpp"

#include <iostream>

std::vector<std::shared_ptr<IGameObject>> CardManager::m_CardDeck = {};

void CardManager::AddCard(std::shared_ptr<IGameObject> Card)
{
    m_CardDeck.push_back(Card);
}


void CardManager::ChangeAbilitie()
{
    if (m_CardDeck.empty())
    {
        std::cout << "No abilities available" << std::endl;
        return;
    }

    m_currentindex = (m_currentindex + 1) % m_CardDeck.size();

    //Here we can also if we want cast the "card" abilitie before putting it last

    
}

bool CardManager::HasCard() const
{
    return !m_CardDeck.empty();
}

std::shared_ptr<IGameObject> CardManager::GetTopCard()
{
    if (m_CardDeck.empty())
    {
        std::cout << "Deck contains no card" << std::endl;
    }
    std::shared_ptr<IGameObject> TopCard = m_CardDeck.at(m_currentindex);
    return TopCard;
}

