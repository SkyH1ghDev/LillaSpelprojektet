#include "CardManager.hpp"

#include <iostream>


void CardManager::AddCard(std::shared_ptr<Card> Card)
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

    std::shared_ptr<Card> card = m_CardDeck.front();
    m_CardDeck.pop();

    //Here we can also if we want cast the "card" abilitie before putting it last

    m_CardDeck.push(card);
}

bool CardManager::HasCard() const
{
    return !m_CardDeck.empty();
}

std::shared_ptr<Card> CardManager::GetTopCard()
{
    if (m_CardDeck.empty())
    {
        std::cerr << "Deck contains no card" << std::endl;
        return;
    }
    std::shared_ptr<Card> TopCard = m_CardDeck.front();
    return TopCard;
}
