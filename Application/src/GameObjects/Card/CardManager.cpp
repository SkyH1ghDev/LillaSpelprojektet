#include "CardManager.hpp"

#include <iostream>

std::queue<std::shared_ptr<IGameObject>> CardManager::m_CardDeck = {};

void CardManager::AddCard(std::shared_ptr<IGameObject> Card)
{
    m_CardDeck.push(Card);
}


void CardManager::ChangeAbilitie()
{
    if (m_CardDeck.empty())
    {
        std::cout << "No abilities available" << std::endl;
        return;
    }

    std::shared_ptr<IGameObject> card = m_CardDeck.front();
    m_CardDeck.pop();

    //Here we can also if we want cast the "card" abilitie before putting it last

    m_CardDeck.push(card);
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
    std::shared_ptr<IGameObject> TopCard = m_CardDeck.front();
    return TopCard;
}


