#pragma once

#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include "Card.hpp"
#include <SpEngine/Assets/IScript.hpp>

class CardManager : public IScript
{
private:
    static std::vector<std::shared_ptr<IGameObject>> m_CardDeck;
    size_t m_currentindex = 0;
public:
    /*
    * Function that adds a card to your deck
    */
    void AddCard(std::shared_ptr<IGameObject> Card);

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
    std::shared_ptr<IGameObject> GetTopCard();


};