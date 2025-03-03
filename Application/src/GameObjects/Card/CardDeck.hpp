#pragma once
#include "ICard.hpp"
#include "CardManager.hpp"
#include <SpEngine/Assets/Game/IGameObject.hpp>

#include <memory>
#include <vector>

class CardDeck : public IGameObject
{
public:
    CardDeck() = default;
    ~CardDeck() override = default;
    CardDeck(const CardDeck& other) = default;
    CardDeck& operator=(const CardDeck& other) = default;
    CardDeck(CardDeck&& other) noexcept = default;
    CardDeck& operator=(CardDeck&& other) noexcept = default;

    void Update() override;
    void OnStart() override;
    void Reset() override;
    
    void AddToDeck(CardType cardtype, size_t lvl);
    std::pair<std::shared_ptr<ICard>, size_t> GetTopCard();
    std::vector < std::pair<std::shared_ptr<ICard>, size_t>> GetDeck();
    void LevelUpCard(size_t cardIndex);
    void ChangeCurrentCard(); //CCC baby
    void ShuffleDeck();
    void UseTopCard(DX::XMFLOAT2 position, DX::XMFLOAT2 target);
    size_t GetDeckSize();
    std::pair<std::shared_ptr<ICard>, size_t> GetCardAt(size_t index);
    void PerformVisible();

private:
    std::vector<std::pair<std::shared_ptr<ICard>, size_t>> m_cardDeck = {};
    size_t m_currentCard = 0;
};

inline size_t CardDeck::GetDeckSize()
{
    return m_cardDeck.size();
}

inline std::pair<std::shared_ptr<ICard>, size_t> CardDeck::GetCardAt(size_t index)
{
    return m_cardDeck.at(index);
}