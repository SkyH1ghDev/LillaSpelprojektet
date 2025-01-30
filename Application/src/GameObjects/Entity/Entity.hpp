#pragma once
#include <memory>

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
public:
    Entity(EntityType entityType);

    void PerformMove() { if (m_move) m_move->Move(); }
    void PerformVisible() { if (m_visible) m_visible->Visible(); }
    void RerformAttack() { if (m_attack) m_attack->Attack(); }
    void PerformTakeDamage() { if (m_takeDamage) m_takeDamage->TakeDamage(); }
    void PerformUseCard() { if (m_useCard) m_useCard->UseCard(); }

    EntityType GetType() const { return m_type; }

private:
    std::unique_ptr<IMove> m_move;
    std::unique_ptr<IVisible> m_visible;
    std::unique_ptr<IAttack> m_attack;
    std::unique_ptr<ITakeDamage> m_takeDamage;
    std::unique_ptr<IUseCard> m_useCard;
    EntityType m_type;

};
