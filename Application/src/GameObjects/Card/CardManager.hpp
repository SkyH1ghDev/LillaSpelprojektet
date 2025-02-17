#pragma once

#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include "CardDeck.hpp"
#include "Card.hpp"
#include <SpEngine/Assets/IScript.hpp>

class CardManager : public IScript
{
public:
    
    CardManager() = default;
    virtual ~CardManager() {}
    CardManager(const CardManager& other) = default;
    CardManager& operator=(const CardManager& other) = default;
    CardManager(CardManager&& other) noexcept = default;
    CardManager& operator=(CardManager&& other) noexcept = default;

    
    void AttachCard(std::shared_ptr<ICard> Card);

    std::vector<std::shared_ptr<ICard>> GetCardObjects();

private:
    static std::vector<std::shared_ptr<ICard>> m_cardObjects;
    size_t m_currentindex = 0;
};