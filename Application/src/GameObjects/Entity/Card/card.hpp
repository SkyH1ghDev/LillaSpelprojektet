#pragma once
#include <memory>

#include <SpEngine/Assets/IGameObject.hpp>

// Define an enum for the entity type
enum class CardType {
    Active,
    Passive
};

#include "IEntityMove.hpp"
#include "IEntityVisible.hpp"
#include "IEntityAttack.hpp"
#include "IEntityTakeDamage.hpp"
#include "IEntityUseCard.hpp"

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
    std::shared_ptr<IEntityMove> m_move;
    std::shared_ptr<IEntityVisible> m_visible;
    std::shared_ptr<IEntityAttack> m_attack;
    std::shared_ptr<IEntityTakeDamage> m_takeDamage;
    std::shared_ptr<IEntityUseCard> m_useCard;
    CardType m_type;
};
