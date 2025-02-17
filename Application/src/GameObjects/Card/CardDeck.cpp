#include "CardDeck.hpp"

#include <iostream>

//std::vector<std::pair<std::shared_ptr<ICard>, size_t>> CardDeck::m_cardDeck = {};
//size_t CardDeck::m_currentcard = 0;

void CardDeck::AddToDeck(CardType cardtype, size_t lvl)
{
    std::shared_ptr<ICard> card = m_cardMan.GetCard(cardtype);
    std::pair<std::shared_ptr<ICard>, size_t> cardInfo = std::make_pair(card, lvl);
    m_cardDeck.push_back(cardInfo);

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

void CardDeck::UseTopCard(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    std::pair<std::shared_ptr<ICard>, size_t> topCard = GetTopCard();
    topCard.first->ActivateLevel(topCard.second, position, target);
    ChangeCurrentCard();
}


