#pragma once

#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include "CardDeck.hpp"
#include <SpEngine/Assets/IScript.hpp>

class CardManager : public IScript
{
private:
    static std::vector<std::shared_ptr<ICard>> m_cardObjects;
    size_t m_currentindex = 0;
public:
    /*
    * Function attaches a card
    */
    void AttachCard(std::shared_ptr<ICard> Card);

    std::vector<std::shared_ptr<ICard>> GetCardObjects();
};