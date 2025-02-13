#pragma once
#include <memory>
#include"Card.hpp"
#include <SpEngine/Assets/IGameObject.hpp>

struct CardInfo {
    CardType type;
    size_t level;
};

class CardDeck 
{
public:
    CardDeck() = default;
    ~CardDeck() = default;
    CardDeck(const CardDeck& other) = default;
    CardDeck& operator=(const CardDeck& other) = default;
    CardDeck(CardDeck&& other) noexcept = default;
    CardDeck& operator=(CardDeck&& other) noexcept = default;
    
    CardDeck(CardInfo cardInfo);

private:

};
