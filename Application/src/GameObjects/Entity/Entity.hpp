#pragma once
#include <memory>
#include <d3d11.h>
#include <DirectXMath.h>

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


namespace DX = DirectX;
// Define an enum for the entity type
enum class EntityType {
    Player,
    Enemy
};

class Entity
{
public:
    Entity(EntityType entityType);
    void PerformMove() { if (m_move) m_move->Move(this->m_position); }
    void PerformVisible() { if (m_visible) m_visible->Visible(); }
    void PerformAttack() { if (m_attack) m_attack->Attack(); }
    void PerformTakeDamage() { if (m_takeDamage) m_takeDamage->TakeDamage(); }
    void PerformUseCard() { if (m_useCard) m_useCard->UseCard(); }

    EntityType GetType() const { return m_type; }

    const DX::XMFLOAT2& GetPosition() const { return this->m_position; }
private:
    DX::XMFLOAT2 m_position = { 0, 0 };

    std::unique_ptr<IMove> m_move;
    std::unique_ptr<IVisible> m_visible;
    std::unique_ptr<IAttack> m_attack;
    std::unique_ptr<ITakeDamage> m_takeDamage;
    std::unique_ptr<IUseCard> m_useCard;
    EntityType m_type;

};
