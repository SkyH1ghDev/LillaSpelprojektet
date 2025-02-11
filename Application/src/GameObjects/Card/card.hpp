#pragma once
#include <memory>

#include <SpEngine/Assets/IGameObject.hpp>

// Define an enum for the entity type
enum class CardType {
    Shotgun,
    Shield
};

#include "ICardActivated.hpp"
#include "ICardAvailability.hpp"
#include "ICardVisible.hpp"

class Card : public IGameObject
{
public:
    Card() = default;
    ~Card() override = default;
    Card(const Card& other) = default;
    Card& operator=(const Card& other) = default;
    Card(Card&& other) noexcept = default;
    Card& operator=(Card&& other) noexcept = default;

    Card(CardType cardtype);


private:
    std::shared_ptr<ICardAvailability> m_available;
    std::shared_ptr<ICardActivated> m_activated;
    std::shared_ptr<ICardVisible> m_visible;

    CardType m_type;
};
