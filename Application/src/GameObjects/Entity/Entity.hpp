#pragma once
#include <memory>
#include <string>
#include "IAttack.hpp"
#include "IMove.hpp"
#include "IVisible.hpp"
#include "ITakeDamage.hpp"
#include "IUseCard.hpp"
#include "IGameObject.hpp"

#include "PlayerAttack.hpp"
#include "PlayerMove.hpp"
#include "PlayerTakeDamage.hpp"
#include "PlayerUseCard.hpp"
#include "PlayerVisible.hpp"

#include "EnemyAttack.hpp"
#include "EnemyMove.hpp"
#include "EnemyTakeDamage.hpp"
#include "EnemyUseCard.hpp"
#include "EnemyVisible.hpp"

// Define an enum for the entity type
enum class EntityType {
    Player,
    Enemy
};

class Entity
{
private:
    std::unique_ptr<IMove> move;
    std::unique_ptr<IVisible> visible;
    std::unique_ptr<IAttack> attack;
    std::unique_ptr<ITakeDamage> takeDamage;
    std::unique_ptr<IUseCard> useCard;
    EntityType type;

public:
    Entity(EntityType entityType);

    void performMove() { if (move) move->Move(); }
    void performVisible() { if (visible) visible->Visible(); }
    void performAttack() { if (attack) attack->Attack(); }
    void performTakeDamage() { if (takeDamage) takeDamage->TakeDamage(); }
    void performUseCard() { if (useCard) useCard->UseCard(); }

    EntityType getType() const { return type; }
};
