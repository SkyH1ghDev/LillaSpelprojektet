#include "DeckManager.hpp"
#include <SpEngine/Clock/Clock.hpp>
#include <SpEngine/Manager/SceneManager.hpp>
#include <SpEngine/Audio/Sound.hpp>

int DeckManager::m_chosenCard = 0;
bool DeckManager::m_upgradePerformed = false;
float DeckManager::m_cardSpeed = 0;
bool DeckManager::m_update = true;

std::vector<CardType> DeckManager::m_cardChoice;
std::vector<int> DeckManager::m_cardIndex;
std::vector<int> DeckManager::m_displayLevel;

std::vector <std::shared_ptr<IGameObject>> DeckManager::m_buttons;

std::vector<std::shared_ptr<Mesh>> DeckManager::m_cardDisplay;

std::shared_ptr<CardDeck> DeckManager::m_cardDeck;
int DeckManager::m_level = 1;
UpgradeType DeckManager::m_type = UpgradeType::AddCard;

void DeckManager::Initialize(std::shared_ptr<IGameObject> button1,
	std::shared_ptr<IGameObject> button2,
	std::shared_ptr<IGameObject> button3,
	std::shared_ptr<IGameObject> card1,
	std::shared_ptr<IGameObject> card2,
	std::shared_ptr<IGameObject> card3,
	std::shared_ptr<IGameObject> cardDeck)
{
	m_buttons.push_back(button1);
	m_buttons.push_back(button2);
	m_buttons.push_back(button3);

	m_cardDisplay.push_back(std::static_pointer_cast<Mesh>(card1));
	m_cardDisplay.push_back(std::static_pointer_cast<Mesh>(card2));
	m_cardDisplay.push_back(std::static_pointer_cast<Mesh>(card3));

	m_cardChoice.push_back(CardType::Shotgun);
	m_cardChoice.push_back(CardType::Shotgun);
	m_cardChoice.push_back(CardType::Shotgun);

	m_cardIndex.push_back(-1);
	m_cardIndex.push_back(-2);
	m_cardIndex.push_back(-3);

	m_displayLevel.push_back(0);
	m_displayLevel.push_back(0);
	m_displayLevel.push_back(0);

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
	if (m_update)
	{
		if (DeckManager::m_upgradePerformed)
		{
			//Disable buttons after choice is made
			m_buttons[0]->SetActive(false);
			m_buttons[1]->SetActive(false);
			m_buttons[2]->SetActive(false);

			//Animate card buttons to reflect chosen card
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
				m_update = false;

				switch (m_type)
				{
				case AddCard:
					m_cardDeck->AddToDeck(CardType(m_cardChoice[m_chosenCard - 1]), m_level);
					m_cardDeck->ChangeCurrentCard();
					break;
				case LevelCard:
					m_cardDeck->LevelUpCard(m_cardIndex[m_chosenCard - 1]);
					break;
				default:
					break;
				}
				
				SceneManager::UnloadScene();
				SceneManager::LoadScene(SceneManager::GetPreviousSceneID());
				Sound::SetMusic("battle_theme_1.wav", 0.5f);
				Sound::PlayMusic(true);
			}

			this->m_cardSpeed += Clock::GetDeltaTime();
		}
	}
}

void DeckManager::Reset()
{
	ResetMenu(UpgradeType::AddCard);
}

void DeckManager::PerformDeckUpgrade(int buttonValue)
{
	DeckManager::m_upgradePerformed = true;
	DeckManager::m_chosenCard = buttonValue;
}

//Call after loading scene for correct buttons to be disabled
void DeckManager::ResetMenu(UpgradeType upgrade)
{
	m_update = true;
	m_type = upgrade;

	m_cardSpeed = 0;
	m_upgradePerformed = false;
	m_cardDisplay[0]->SetPosition({200, 145});
	m_cardDisplay[1]->SetPosition({295, 145});
	m_cardDisplay[2]->SetPosition({390, 145});

	m_buttons[0]->SetPosition({200, 145});
	m_buttons[1]->SetPosition({295, 145});
	m_buttons[2]->SetPosition({390, 145});
	
	switch (m_type)
	{
	case AddCard:

		//Randomise options
		m_cardChoice[0] = CardType(rand() % 5);
		m_cardChoice[1] = CardType(rand() % 5);
		m_cardChoice[2] = CardType(rand() % 5);

		//Make sure all options are different
		while (m_cardChoice[1] == m_cardChoice[0])
			m_cardChoice[1] = CardType(rand() % 5);
		while (m_cardChoice[2] == m_cardChoice[0] || m_cardChoice[2] == m_cardChoice[1])
			m_cardChoice[2] = CardType(rand() % 5);

		break;

	case LevelCard:
		m_cardIndex[0] = -1;
		m_cardIndex[1] = -2;
		m_cardIndex[2] = -3;
		//Choose up to three unique card from deck
		for (size_t i = 0; i < 3; i++)
		{
			m_cardChoice[i] = CardType(-1);
			for (size_t k = 0; k < m_cardDeck->GetDeckSize(); k++)
			{
				if (m_cardDeck->GetCardAt(k).second < 3)
				{
					m_cardIndex[i] = k;
					m_displayLevel[i] = m_cardDeck->GetCardAt(k).second;
					m_cardChoice[i] = m_cardDeck->GetCardAt(k).first->GetType();

					if (m_cardIndex[0] == m_cardIndex[1] || m_cardIndex[1] == m_cardIndex[2] || m_cardIndex[0] == m_cardIndex[2])
					{
						m_cardIndex[i] = -i - 1;
						m_cardChoice[i] = CardType(-1);
					}
					else
						break;
				}
			}

			if (m_cardIndex[i] < 0)
			{
				m_buttons[i]->Reset();
				m_buttons[i]->SetActive(false);
			}
		}

		break;

	default:
		break;
	}

	//Update card buttons to reflect options
	for (size_t i = 0; i < m_cardChoice.size(); i++)
	{
		int level = m_level;
		if (m_type == UpgradeType::LevelCard)
			level = m_displayLevel[i];

		switch (m_cardChoice[i])
		{
		case CardType::Shotgun: //Scatter
			m_cardDisplay.at(i)->SetTexture("card_scatter_lvl" + std::to_string(level) + ".png");
			break;
		case CardType::Spread: //Ring of fire
			m_cardDisplay.at(i)->SetTexture("card_rof_lvl" + std::to_string(level) + ".png");
			break;
		case CardType::Heal: //Heal
			m_cardDisplay.at(i)->SetTexture("card_heal_lvl" + std::to_string(level) + ".png");
			break;
		case CardType::Sniper: //Rune shard
			m_cardDisplay.at(i)->SetTexture("rune_shard_lvl" + std::to_string(level) + ".png");
			break;
		case CardType::Disruptor: //Disruptor
			m_cardDisplay.at(i)->SetTexture("disruptor_wave_lvl" + std::to_string(level) + ".png");
			break;
		default: //Nothing
			m_cardDisplay.at(i)->SetTexture("button_card.png");
			break;
		}
	}
}