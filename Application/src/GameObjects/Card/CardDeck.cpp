#include "CardDeck.hpp"
#include <iostream>



void CardDeck::AddToDeck(std::pair<std::shared_ptr<ICard>, size_t> cardInfo)
{
    std::cout << "kortlek" << std::endl;
}

std::pair<std::shared_ptr<ICard>, size_t> CardDeck::GetTopCard()
{
    return m_cardDeck.at(m_currentcard);
}

std::vector<std::pair<std::shared_ptr<ICard>, size_t>> CardDeck::GetDeck()
{
    return m_cardDeck;
}

void CardDeck::LevelUppCard(size_t cardIndex)
{
    m_cardDeck.at(cardIndex).second++;
}

void CardDeck::ChangeCurrentCard()
{
    m_currentcard = (m_currentcard + 1) % m_cardDeck.size();
}

void CardDeck::ShuffleDeck()
{
    if (m_cardDeck.empty()) { 
        return; 
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(m_cardDeck.begin(), m_cardDeck.end(), g);

}

