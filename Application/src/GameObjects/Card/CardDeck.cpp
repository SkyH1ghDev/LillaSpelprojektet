#include "CardDeck.hpp"

#include <random>

//std::vector<std::pair<std::shared_ptr<ICard>, size_t>> CardDeck::m_cardDeck = {};
//size_t CardDeck::m_currentcard = 0;


void CardDeck::Update()
{
    PerformVisible();
}

void CardDeck::OnStart()
{
    this->m_shouldRender = true;
    this->m_isActive = false;
    SetIsAlive(true);
    if (m_cardDeck.empty()) {
        return;
    }
    m_cardDeck[m_currentCard].first.get()->SetCardTexture(m_cardDeck[m_currentCard].second);
}

void CardDeck::AddToDeck(CardType cardtype, size_t lvl)
{

    std::shared_ptr<ICard> card = CardManager::GetCard(cardtype);
    std::pair<std::shared_ptr<ICard>, size_t> cardInfo = std::make_pair(card, lvl);
    m_cardDeck.push_back(cardInfo);
}

std::pair<std::shared_ptr<ICard>, size_t> CardDeck::GetTopCard()
{
    if (m_cardDeck.empty()) {
        return { 0, 0 };
    }
    return m_cardDeck.at(m_currentCard);
}

std::vector<std::pair<std::shared_ptr<ICard>, size_t>> CardDeck::GetDeck()
{
    return m_cardDeck;
}

void CardDeck::LevelUpCard(size_t cardIndex)
{
    if (m_cardDeck.empty()) {
        return;
    }
    m_cardDeck.at(cardIndex).second++;
}

void CardDeck::ChangeCurrentCard()
{
    if (m_cardDeck.empty()) {
        return;
    }
    m_currentCard = (m_currentCard + 1) % m_cardDeck.size();
    m_cardDeck[m_currentCard].first.get()->SetCardTexture(m_cardDeck[m_currentCard].second);
}

void CardDeck::ShuffleDeck()
{
    if (m_cardDeck.empty()) { 
        return; 
    }
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(m_cardDeck.begin(), m_cardDeck.end(), g);
}

void CardDeck::UseTopCard(DX::XMFLOAT2 position, DX::XMFLOAT2 target)
{
    if (m_cardDeck.empty()) {
        return;
    }
    std::pair<std::shared_ptr<ICard>, size_t> topCard = GetTopCard();
    topCard.first->ActivateLevel(topCard.second, position, target);
    ChangeCurrentCard();
    m_cardDeck[m_currentCard].first.get()->SetCardTexture(m_cardDeck[m_currentCard].second);
}

void CardDeck::PerformVisible()
{
    this->m_scaleFloat = 1.0;
    this->m_layerFloat = 0.9;
    this->m_position = { 560, 285 };

    if (!m_cardDeck.empty())
        this->m_textureName = m_cardDeck[m_currentCard].first->GetCardTexture();
    else
        this->m_textureName = "button_card.png";
}

void CardDeck::Reset()
{
    this->m_shouldRender = true;
    this->m_isActive = false;
    SetIsAlive(true);
    this->m_cardDeck.clear();
    if (!m_cardDeck.empty())
        m_cardDeck[m_currentCard].first.get()->SetCardTexture(m_cardDeck[m_currentCard].second);
}

bool CardDeck::CanLevelUp()
{
    for (size_t i = 0; i < m_cardDeck.size(); i++)
        if (m_cardDeck.at(i).second < 3)
            return true;
    
    return false;
}