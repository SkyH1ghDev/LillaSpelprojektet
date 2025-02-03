#pragma once
#include <memory>
#include <d3d11.h>
#include <DirectXMath.h>

#include <SpEngine/Assets/IGameObject.hpp>

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

class Entity : public IGameObject
{
public:

    Entity() = default;
    ~Entity() override = default;
    Entity(const Entity& other) = default;
    Entity& operator=(const Entity& other) = default;
    Entity(Entity&& other) noexcept = default;
    Entity& operator=(Entity&& other) noexcept = default;

    Entity(EntityType entityType);
    void PerformMove() { if (m_move) m_move->Move(this->m_position); }
    void PerformVisible() { if (m_visible) m_visible->Visible(); }
    void PerformAttack() { if (m_attack) m_attack->Attack(); }
    void PerformTakeDamage() { if (m_takeDamage) m_takeDamage->TakeDamage(); }
    void PerformUseCard() { if (m_useCard) m_useCard->UseCard(); }

    void Update() override;
    void OnStart() override;

    EntityType GetType() const { return m_type; }

    const DX::XMFLOAT2& GetPosition() const { return this->m_position; }
private:
    std::shared_ptr<IMove> m_move;
    std::shared_ptr<IVisible> m_visible;
    std::shared_ptr<IAttack> m_attack;
    std::shared_ptr<ITakeDamage> m_takeDamage;
    std::shared_ptr<IUseCard> m_useCard;
    DX::XMFLOAT2 m_position = { 0, 0 };

    EntityType m_type;

};
