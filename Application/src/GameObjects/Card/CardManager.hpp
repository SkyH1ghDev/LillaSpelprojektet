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
    void AddCard(std::shared_ptr<Card> Card);
    void ToggleAbilitie();
    bool HasCard() const;
};




