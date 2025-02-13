#pragma once
#include <memory>
#include"ICard.hpp"
#include <vector>
#include <random>
#include <algorithm>
#include <SpEngine/Assets/IGameObject.hpp>



class CardDeck 
{
public:
    CardDeck() = default;
    ~CardDeck() = default;
    CardDeck(const CardDeck& other) = default;
    CardDeck& operator=(const CardDeck& other) = default;
    CardDeck(CardDeck&& other) noexcept = default;
    CardDeck& operator=(CardDeck&& other) noexcept = default;
    
    void AddToDeck(std::pair<std::shared_ptr<ICard>,size_t> cardInfo);
    std::pair<std::shared_ptr<ICard>, size_t> GetTopCard();
    std::vector < std::pair<std::shared_ptr<ICard>, size_t>> GetDeck();
    void LevelUppCard(size_t cardIndex);
    void ChangeCurrentCard(); //CCC baby
    void ShuffleDeck();

private:
    std::vector<std::pair<std::shared_ptr<ICard>, size_t>> m_cardDeck;
    size_t m_currentcard;
};
