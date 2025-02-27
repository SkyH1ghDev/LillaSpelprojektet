#pragma once
#include "Entity.hpp"
#include "Actions/UseCard.hpp"
#include "Card/CardDeck.hpp"

#include <SpEngine/Assets/Game/IScript.hpp>


class PlayerCardScript : public IScript
{
public:
	void OnStart() override;
	void Update() override;
	std::shared_ptr<CardDeck> GetCardDeck() { return this->m_cardDeck; }

private:
	std::shared_ptr<CardDeck> m_cardDeck = std::make_shared<CardDeck>();
	std::shared_ptr<UseCard> m_useCard = std::make_shared<UseCard>();
	float m_useCardTimer = 0;
	float m_manaTimer = 0;
};
