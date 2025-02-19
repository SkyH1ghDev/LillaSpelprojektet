#pragma once
#include <memory>
#include"ICard.hpp"
#include "CardManager.hpp"
#include <vector>
#include <random>
#include <algorithm>
#include <SpEngine/Assets/IGameObject.hpp>



class CardDeck : public IGameObject
{
public:
    CardDeck() = default;
    ~CardDeck() = default;
    CardDeck(const CardDeck& other) = default;
    CardDeck& operator=(const CardDeck& other) = default;
    CardDeck(CardDeck&& other) noexcept = default;
    CardDeck& operator=(CardDeck&& other) noexcept = default;

    void Update() override;
    void OnStart() override;
    
    void AddToDeck(CardType cardtype, size_t lvl);
    std::pair<std::shared_ptr<ICard>, size_t> GetTopCard();
    std::vector < std::pair<std::shared_ptr<ICard>, size_t>> GetDeck();
    void LevelUppCard(size_t cardIndex);
    void ChangeCurrentCard(); //CCC baby
    void ShuffleDeck();
    void UseTopCard(DX::XMFLOAT2 position, DX::XMFLOAT2 target);

    void PerformVisible();

private:
    CardManager m_cardMan;
    std::vector<std::pair<std::shared_ptr<ICard>, size_t>> m_cardDeck = {};
    size_t m_currentcard=0;
};
