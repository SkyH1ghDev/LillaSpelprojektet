#include "Mesh.hpp"
#include "CardDeck.hpp"

enum UpgradeType
{
	AddCard,
	LevelCard
};

class DeckManager : public IGameObject
{
public:
	DeckManager() = default;
	~DeckManager() noexcept = default;
	DeckManager(const DeckManager& other) = default;
	DeckManager& operator=(const DeckManager& other) = default;
	DeckManager(DeckManager&& other) noexcept = default;
	DeckManager& operator=(DeckManager&& other) noexcept = default;

	static void Initialize(
		std::shared_ptr<IGameObject> button1,
		std::shared_ptr<IGameObject> button2,
		std::shared_ptr<IGameObject> button3,
		std::shared_ptr<IGameObject> card1,
		std::shared_ptr<IGameObject> card2,
		std::shared_ptr<IGameObject> card3,
		std::shared_ptr<IGameObject> cardDeck);

	static void PerformDeckUpgrade(int buttonValue);
	void OnStart() override;
	void Update() override;
	void Reset() override;
	static void ResetMenu(UpgradeType upgrade);
	static void SetLevel(int level);

private:

	static std::vector <std::shared_ptr<IGameObject>> m_buttons;

	static std::vector <std::shared_ptr<Mesh>> m_cardDisplay;

	static std::shared_ptr<CardDeck> m_cardDeck;
	static std::vector<CardType> m_cardChoice;
	static std::vector<int> m_cardIndex;
	static std::vector<int> m_displayLevel;

	static bool m_upgradePerformed;
	static int m_chosenCard;

	static float m_cardSpeed;

	static int m_level;

	static UpgradeType m_type;
	static bool m_update;
};

inline void DeckManager::SetLevel(int level)
{
	DeckManager::m_level = level;
}