#include "DeckManager.hpp"
#include <SpEngine/Clock/Clock.hpp>

int DeckManager::m_chosenCard = 0;
bool DeckManager::m_upgradePerformed = false;
float DeckManager::m_cardSpeed = 0;
std::vector<int> DeckManager::m_cardChoice;

std::shared_ptr<IGameObject> DeckManager::m_button1;
std::shared_ptr<IGameObject> DeckManager::m_button2;
std::shared_ptr<IGameObject> DeckManager::m_button3;

std::vector<std::shared_ptr<Mesh>> DeckManager::m_cardDisplay;

std::shared_ptr<CardDeck> DeckManager::m_cardDeck;

void DeckManager::Initialize(std::shared_ptr<IGameObject> button1,
	std::shared_ptr<IGameObject> button2,
	std::shared_ptr<IGameObject> button3,
	std::shared_ptr<IGameObject> card1,
	std::shared_ptr<IGameObject> card2,
	std::shared_ptr<IGameObject> card3,
	std::shared_ptr<IGameObject> cardDeck)
{
	m_button1 = button1;
	m_button2 = button2;
	m_button3 = button3;

	m_cardDisplay.push_back(std::static_pointer_cast<Mesh>(card1));
	m_cardDisplay.push_back(std::static_pointer_cast<Mesh>(card2));
	m_cardDisplay.push_back(std::static_pointer_cast<Mesh>(card3));

	m_cardChoice.push_back(rand() % 5);
	m_cardChoice.push_back(rand() % 5);
	m_cardChoice.push_back(rand() % 5);

	m_cardDeck = std::static_pointer_cast<CardDeck>(cardDeck);

	DeckManager::m_upgradePerformed = false;
}

void DeckManager::OnStart()
{
	this->m_isActive = false;
	this->m_isAlive = true;
}

void DeckManager::Update()
{
	if (!DeckManager::m_upgradePerformed)
		this->m_isAlive = true;

	if (this->m_isAlive)
	{
		if (DeckManager::m_upgradePerformed)
		{
			m_button1->SetActive(false);
			m_button2->SetActive(false);
			m_button3->SetActive(false);

			switch (m_chosenCard)
			{
			case 1:
				m_cardDisplay.at(0)->SetPosition({ m_cardDisplay.at(0)->GetPosition().x, m_cardDisplay.at(0)->GetPosition().y + m_cardSpeed});
				m_cardDisplay.at(1)->SetPosition({ m_cardDisplay.at(1)->GetPosition().x, m_cardDisplay.at(1)->GetPosition().y - m_cardSpeed});
				m_cardDisplay.at(2)->SetPosition({ m_cardDisplay.at(2)->GetPosition().x, m_cardDisplay.at(2)->GetPosition().y - m_cardSpeed});
				break;
			case 2:
				m_cardDisplay.at(0)->SetPosition({ m_cardDisplay.at(0)->GetPosition().x, m_cardDisplay.at(0)->GetPosition().y - m_cardSpeed });
				m_cardDisplay.at(1)->SetPosition({ m_cardDisplay.at(1)->GetPosition().x, m_cardDisplay.at(1)->GetPosition().y + m_cardSpeed });
				m_cardDisplay.at(2)->SetPosition({ m_cardDisplay.at(2)->GetPosition().x, m_cardDisplay.at(2)->GetPosition().y - m_cardSpeed });
				break;
			case 3:
				m_cardDisplay.at(0)->SetPosition({ m_cardDisplay.at(0)->GetPosition().x, m_cardDisplay.at(0)->GetPosition().y - m_cardSpeed });
				m_cardDisplay.at(1)->SetPosition({ m_cardDisplay.at(1)->GetPosition().x, m_cardDisplay.at(1)->GetPosition().y - m_cardSpeed });
				m_cardDisplay.at(2)->SetPosition({ m_cardDisplay.at(2)->GetPosition().x, m_cardDisplay.at(2)->GetPosition().y + m_cardSpeed });
				break;
			default:
				break;
			}

			//End of upgrade sequence
			if (m_cardDisplay.at(0)->GetPosition().y < -70 || m_cardDisplay.at(0)->GetPosition().y > 360)
			{
				this->m_isAlive = false;
				m_cardDeck->AddToDeck(CardType(m_cardChoice[m_chosenCard - 1]), 1);
				m_cardDeck->ShuffleDeck();
			}

			this->m_cardSpeed += Clock::GetDeltaTime();
		}
	}
}

void DeckManager::Reset()
{
	this->m_isAlive = true;

	ResetMenu();
}

void DeckManager::PerformDeckUpgrade(int buttonValue)
{
	DeckManager::m_upgradePerformed = true;
	DeckManager::m_chosenCard = buttonValue;
}

void DeckManager::ResetMenu()
{
	DeckManager::m_cardSpeed = 0;
	DeckManager::m_upgradePerformed = false;
	DeckManager::m_cardDisplay[0]->SetPosition({200, 145});
	DeckManager::m_cardDisplay[1]->SetPosition({295, 145});
	DeckManager::m_cardDisplay[2]->SetPosition({390, 145});

	DeckManager::m_button1->SetPosition({200, 145});
	DeckManager::m_button2->SetPosition({295, 145});
	DeckManager::m_button3->SetPosition({390, 145});
	
	m_cardChoice[0] = rand() % 5;
	m_cardChoice[1] = rand() % 5;
	m_cardChoice[2] = rand() % 5;

	int lvl = 1;

	while (m_cardChoice[1] == m_cardChoice[0])
		m_cardChoice[1] = rand() % 5;
	while (m_cardChoice[2] == m_cardChoice[0] || m_cardChoice[2] == m_cardChoice[1])
		m_cardChoice[2] = rand() % 5;

	for (size_t i = 0; i < m_cardChoice.size(); i++)
	{
		switch (m_cardChoice[i])
		{
		case 0: //Shotgun
			m_cardDisplay.at(i)->SetTexture("card_scatter_lvl" + std::to_string(lvl) + ".png");
			break;
		case 1: //Spread
			m_cardDisplay.at(i)->SetTexture("card_rof_lvl" + std::to_string(lvl) + ".png");
			break;
		case 2: //Heal
			m_cardDisplay.at(i)->SetTexture("card_heal_lvl" + std::to_string(lvl) + ".png");
			break;
		case 3: //Sniper
			m_cardDisplay.at(i)->SetTexture("rune_shard_lvl" + std::to_string(lvl) + ".png");
			break;
		case 4: //Disruptor
			m_cardDisplay.at(i)->SetTexture("disruptor_wave_lvl" + std::to_string(lvl) + ".png");
			break;
		default:
			break;
		}
	}
}