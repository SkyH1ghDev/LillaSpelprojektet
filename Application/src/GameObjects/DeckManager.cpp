#include "DeckManager.hpp"
#include <SpEngine/Clock/Clock.hpp>
#include <SpEngine/Manager/SceneManager.hpp>
#include <SpEngine/Audio/Sound.hpp>
#include <SpEngine/Math/SpMath.hpp>

int DeckManager::m_chosenCard = 0;
bool DeckManager::m_upgradePerformed = false;
float DeckManager::m_cardSpeed = 0;
bool DeckManager::m_update = true;

std::vector<CardType> DeckManager::m_cardChoice;
std::vector<int> DeckManager::m_cardIndex;
std::vector<int> DeckManager::m_displayLevel;

std::vector <std::shared_ptr<IGameObject>> DeckManager::m_buttons;
std::vector<std::shared_ptr<Mesh>> DeckManager::m_descriptions;

std::vector<std::shared_ptr<Mesh>> DeckManager::m_cardDisplay;

std::shared_ptr<Mesh> DeckManager::m_chesster;
std::shared_ptr<Mesh> DeckManager::m_text;
std::vector<std::shared_ptr<Mesh>> DeckManager::m_background;

std::shared_ptr<CardDeck> DeckManager::m_cardDeck;
int DeckManager::m_level = 1;
UpgradeType DeckManager::m_type = UpgradeType::AddCard;

void DeckManager::Initialize(std::shared_ptr<IGameObject> button1,
	std::shared_ptr<IGameObject> button2,
	std::shared_ptr<IGameObject> button3,
	std::shared_ptr<IGameObject> card1,
	std::shared_ptr<IGameObject> card2,
	std::shared_ptr<IGameObject> card3,
	std::shared_ptr<IGameObject> desc1,
	std::shared_ptr<IGameObject> desc2,
	std::shared_ptr<IGameObject> desc3,
	std::shared_ptr<IGameObject> cardDeck,
	std::shared_ptr<IGameObject> chesster,
	std::shared_ptr<IGameObject> text,
	std::vector<std::shared_ptr<Mesh>> background)
{
	m_chesster = std::static_pointer_cast<Mesh>(chesster);
	m_text = std::static_pointer_cast<Mesh>(text);
	m_background = background;

	m_buttons.push_back(button1);
	m_buttons.push_back(button2);
	m_buttons.push_back(button3);

	m_cardDisplay.push_back(std::static_pointer_cast<Mesh>(card1));
	m_cardDisplay.push_back(std::static_pointer_cast<Mesh>(card2));
	m_cardDisplay.push_back(std::static_pointer_cast<Mesh>(card3));

	m_descriptions.push_back(std::static_pointer_cast<Mesh>(desc1));
	m_descriptions.push_back(std::static_pointer_cast<Mesh>(desc2));
	m_descriptions.push_back(std::static_pointer_cast<Mesh>(desc3));

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
			m_buttons[0]->SetIsAlive(false);
			m_buttons[1]->SetIsAlive(false);
			m_buttons[2]->SetIsAlive(false);

			m_descriptions.at(0)->SetTexture("button_card.png");
			m_descriptions.at(1)->SetTexture("button_card.png");
			m_descriptions.at(2)->SetTexture("button_card.png");

			//Animate card buttons to reflect chosen card
			switch (m_chosenCard)
			{
			case 1:
				m_cardDisplay.at(0)->SetPosition({ m_cardDisplay.at(0)->GetPosition().x, m_cardDisplay.at(0)->GetPosition().y + m_cardSpeed * Clock::GetDeltaTime()});
				m_cardDisplay.at(1)->SetPosition({ m_cardDisplay.at(1)->GetPosition().x, m_cardDisplay.at(1)->GetPosition().y - m_cardSpeed * Clock::GetDeltaTime() });
				m_cardDisplay.at(2)->SetPosition({ m_cardDisplay.at(2)->GetPosition().x, m_cardDisplay.at(2)->GetPosition().y - m_cardSpeed * Clock::GetDeltaTime() });
				break;
			case 2:
				m_cardDisplay.at(0)->SetPosition({ m_cardDisplay.at(0)->GetPosition().x, m_cardDisplay.at(0)->GetPosition().y - m_cardSpeed * Clock::GetDeltaTime() });
				m_cardDisplay.at(1)->SetPosition({ m_cardDisplay.at(1)->GetPosition().x, m_cardDisplay.at(1)->GetPosition().y + m_cardSpeed * Clock::GetDeltaTime() });
				m_cardDisplay.at(2)->SetPosition({ m_cardDisplay.at(2)->GetPosition().x, m_cardDisplay.at(2)->GetPosition().y - m_cardSpeed * Clock::GetDeltaTime() });
				break;
			case 3:
				m_cardDisplay.at(0)->SetPosition({ m_cardDisplay.at(0)->GetPosition().x, m_cardDisplay.at(0)->GetPosition().y - m_cardSpeed * Clock::GetDeltaTime() });
				m_cardDisplay.at(1)->SetPosition({ m_cardDisplay.at(1)->GetPosition().x, m_cardDisplay.at(1)->GetPosition().y - m_cardSpeed * Clock::GetDeltaTime() });
				m_cardDisplay.at(2)->SetPosition({ m_cardDisplay.at(2)->GetPosition().x, m_cardDisplay.at(2)->GetPosition().y + m_cardSpeed * Clock::GetDeltaTime() });
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
					break;
				case LevelCard:
					m_cardDeck->LevelUpCard(m_cardIndex[m_chosenCard - 1]);
					break;
				default:
					break;
				}
				m_cardDeck->ChangeCurrentCard();
				SceneManager::UnloadScene();
				SceneManager::LoadScene("game");
				Sound::SetMusic("battle_theme_1.wav", 0.5f);
				Sound::PlayMusic(true);
			}

			this->m_cardSpeed += Clock::GetDeltaTime() * 500;
		}
	}

	if (m_buttons[0]->IsActive())
		m_buttons[0]->SetIsAlive(true);
	if (m_buttons[1]->IsActive())
		m_buttons[1]->SetIsAlive(true);
	if (m_buttons[2]->IsActive())
		m_buttons[2]->SetIsAlive(true);
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
void DeckManager::ResetMenu(UpgradeType upgrade, size_t level)
{
	m_update = true;

	m_level = level;

	m_buttons[0]->SetActive(true);
	m_buttons[1]->SetActive(true);
	m_buttons[2]->SetActive(true);
	m_buttons[0]->SetIsAlive(false);
	m_buttons[1]->SetIsAlive(false);
	m_buttons[2]->SetIsAlive(false);

	if (SpMath::RandomInteger(0, 50) == 0)
		m_chesster->SetTexture("chadster_closeup");
	else
		m_chesster->SetTexture("chesster_closeup");

	m_type = UpgradeType::AddCard;
	if (m_cardDeck->CanLevelUp())
		m_type = upgrade;

	m_cardSpeed = 0;
	m_upgradePerformed = false;
	m_cardDisplay[0]->SetPosition({160, 145});
	m_cardDisplay[1]->SetPosition({295, 145});
	m_cardDisplay[2]->SetPosition({430, 145});

	m_buttons[0]->SetPosition({160, 145});
	m_buttons[1]->SetPosition({295, 145});
	m_buttons[2]->SetPosition({430, 145});
	
	switch (m_type)
	{
	case AddCard:

		//Set text position and texture
		m_text->SetTexture("text_pick");
		m_text->SetPosition({ 180, 71 });

		//Set background texture
		for (size_t i = 0; i < 8; i++)
			m_background.at(i)->SetTexture("background_card");

		//Randomise options
		m_cardChoice[0] = CardType(SpMath::RandomInteger(0, 8));
		m_cardChoice[1] = CardType(SpMath::RandomInteger(0, 8));
		m_cardChoice[2] = CardType(SpMath::RandomInteger(0, 8));

		//Make sure all options are different
		while (m_cardChoice[1] == m_cardChoice[0])
			m_cardChoice[1] = CardType(SpMath::RandomInteger(0, 8));
		while (m_cardChoice[2] == m_cardChoice[0] || m_cardChoice[2] == m_cardChoice[1])
			m_cardChoice[2] = CardType(SpMath::RandomInteger(0, 8));

		if (SpMath::RandomInteger(0, 19) == 0)
			m_cardChoice[2] = CardType::Heal;

		break;

	case LevelCard:

		//Set text texture and position
		m_text->SetTexture("text_upgrade");
		m_text->SetPosition({ 141, 75 });

		//Set background texture
		for (size_t i = 0; i < 8; i++)
			m_background.at(i)->SetTexture("background_upgrade");

		//Reset stored values for comparison
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
			m_cardDisplay.at(i)->SetTexture("scatter_lvl" + std::to_string(level) + ".png");
			m_descriptions.at(i)->SetTexture("scatter_desc.png");
			break;
		case CardType::Spread: //Ring of fire
			m_cardDisplay.at(i)->SetTexture("ring_of_fire_lvl" + std::to_string(level) + ".png");
			m_descriptions.at(i)->SetTexture("ring_of_fire_desc.png");
			break;
		case CardType::Heal: //Heal
			m_cardDisplay.at(i)->SetTexture("heal_lvl" + std::to_string(level) + ".png");
			m_descriptions.at(i)->SetTexture("heal_desc.png");
			break;
		case CardType::Sniper: //Rune shard
			m_cardDisplay.at(i)->SetTexture("rune_shard_lvl" + std::to_string(level) + ".png");
			m_descriptions.at(i)->SetTexture("rune_shard_desc.png");
			break;
		case CardType::Disruptor: //Disruptor
			m_cardDisplay.at(i)->SetTexture("disruptor_lvl" + std::to_string(level) + ".png");
			m_descriptions.at(i)->SetTexture("disruptor_desc.png");
			break;
		case CardType::RangeBuff: //RangeBuff
			m_cardDisplay.at(i)->SetTexture("longshot_lvl" + std::to_string(level) + ".png");
			m_descriptions.at(i)->SetTexture("longshot_desc.png");
			break;
		case CardType::AttackSpeedBuff: //Attack speed buff
			m_cardDisplay.at(i)->SetTexture("haste_lvl" + std::to_string(level) + ".png");
			m_descriptions.at(i)->SetTexture("haste_desc.png");
			break;
		case CardType::Blade: //Blade
			m_cardDisplay.at(i)->SetTexture("blade_lvl" + std::to_string(level) + ".png");
			m_descriptions.at(i)->SetTexture("blade_desc.png");
			break;
		case CardType::IceCubes: //Ice cube
			m_cardDisplay.at(i)->SetTexture("ice_cubes_lvl" + std::to_string(level) + ".png");
			m_descriptions.at(i)->SetTexture("ice_cube_desc.png");
			break;
		case CardType::MagicMissile: //Magic missile
			m_cardDisplay.at(i)->SetTexture("magic_missile_lvl" + std::to_string(level) + ".png");
			m_descriptions.at(i)->SetTexture("magic_missile_desc.png");
			break;
		default: //Nothing
			m_cardDisplay.at(i)->SetTexture("button_card.png");
			m_descriptions.at(i)->SetTexture("button_card.png");
			break;
		}
	}
}