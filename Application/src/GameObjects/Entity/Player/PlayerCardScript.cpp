#include "PlayerCardScript.hpp"

#include <SpEngine/Input/Input.hpp>
#include <SpEngine/Clock/Clock.hpp>

#include "GameObjects/UI/Bar/ManaBarManager.hpp"
#include "GameObjects/UI/Bar/HealthBarManager.hpp"

void PlayerCardScript::OnStart()
{
	Input::GetKey(VK_RBUTTON)->Attach(std::static_pointer_cast<IObserver, UseCard>(m_useCard));

	m_cardDeck->AddToDeck(CardType::Shotgun, 1);
	m_cardDeck->AddToDeck(CardType::Shotgun, 2);
	m_cardDeck->AddToDeck(CardType::Shotgun, 3);
	m_cardDeck->AddToDeck(CardType::Spread, 1);
	m_cardDeck->AddToDeck(CardType::Spread, 2);
	m_cardDeck->AddToDeck(CardType::Spread, 3);
	m_cardDeck->AddToDeck(CardType::Heal, 1);
	m_cardDeck->AddToDeck(CardType::Heal, 2);
	m_cardDeck->AddToDeck(CardType::Heal, 3);
	m_cardDeck->AddToDeck(CardType::Sniper, 1);
	m_cardDeck->AddToDeck(CardType::Sniper, 2);
	m_cardDeck->AddToDeck(CardType::Sniper, 3);
	m_cardDeck->AddToDeck(CardType::Disruptor, 1);
	m_cardDeck->ShuffleDeck();
}

void PlayerCardScript::Update()
{
	std::shared_ptr<Entity> player = std::static_pointer_cast<Entity>(m_gameObject.lock());

	DX::XMFLOAT2 pos = player->GetPosition();

	DX::XMFLOAT2 mousePos = DX::XMFLOAT2(Input::GetMousePositionX(), Input::GetMousePositionY());

	DX::XMFLOAT2 wandPos;

	DX::XMVECTOR playerToMouse = DX::XMVectorSubtract(DX::XMLoadFloat2(&mousePos), DX::XMLoadFloat2(&pos));
	DX::XMStoreFloat2(&wandPos, DX::XMVectorAdd(DX::XMVectorScale(DX::XMVector2Normalize(playerToMouse), 20), DX::XMLoadFloat2(&pos)));

	if (m_useCardTimer >= 0)
		m_useCardTimer -= Clock::GetDeltaTime();

	if (m_manaTimer >= 1) {
		ManaBarManager::RefillManaShard(1);
		m_manaTimer = 0;
	}


	m_manaTimer += Clock::GetDeltaTime();

	if (m_useCard->GetUseCard() && m_useCardTimer <= 0)
	{
		if (ManaBarManager::RemoveManaCrystal(1)) {
			//player->PerformAttack(wandPos, DX::XMFLOAT2(DX::XMVectorGetX(DX::XMVector2Normalize(playerToMouse)), (DX::XMVectorGetY(DX::XMVector2Normalize(playerToMouse)))));
			m_cardDeck->UseTopCard(wandPos, DX::XMFLOAT2(DX::XMVectorGetX(DX::XMVector2Normalize(playerToMouse)), (DX::XMVectorGetY(DX::XMVector2Normalize(playerToMouse)))));
			m_useCardTimer = 1;
		}
	}
}
