#pragma once

#include <vector>
#include <memory>
#include "Card.hpp"

class CardManager
{
public:
    static std::shared_ptr<ICard> GetCard(CardType cardType);
    static std::vector<std::shared_ptr<ICard>> GetCardObjects();
    static std::string GetCardTexture();
    static void Cleanup();

private:
    static std::vector<std::shared_ptr<ICard>> m_cardObjects;
    static size_t m_currentindex;
    static void Initialize();
};