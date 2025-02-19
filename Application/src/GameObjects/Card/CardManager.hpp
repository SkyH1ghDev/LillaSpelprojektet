#pragma once

#include <vector>
#include <memory>
#include "Card.hpp"

class CardManager
{
public:
    
    CardManager();
    virtual ~CardManager() {}
    CardManager(const CardManager& other) = default;
    CardManager& operator=(const CardManager& other) = default;
    CardManager(CardManager&& other) noexcept = default;
    CardManager& operator=(CardManager&& other) noexcept = default;

    std::shared_ptr<ICard> GetCard(CardType cardType);
    std::vector<std::shared_ptr<ICard>> GetCardObjects();

private:
    std::vector<std::shared_ptr<ICard>> m_cardObjects;
    size_t m_currentindex = 0;
};