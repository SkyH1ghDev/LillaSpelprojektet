#pragma once

#include <queue>
#include <string>
#include <memory>
#include <stdexcept>
#include "Card.hpp"

class CardManager
{
private:
    
    std::queue<std::shared_ptr<Card>> m_CardDeck;
public:
    /*
    * Function that adds a card to your deck
    */
    void AddCard(std::shared_ptr<Card> Card);

    /*
    * Call function after using a card, the top card goes to the bottom of the deck
    */
    void ChangeAbilitie();

    /*
    * Returns false if deck is empty, otherwise true
    */
    bool HasCard() const;

    /*
    * Retreives the top card of deck
    */
    std::shared_ptr<Card> GetTopCard();
};




