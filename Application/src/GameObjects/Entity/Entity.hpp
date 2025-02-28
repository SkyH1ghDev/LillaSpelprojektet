#pragma once
#include "IEntityMove.hpp"
#include "IEntityDash.hpp"
#include "IEntityVisible.hpp"
#include "IEntityAttack.hpp"
#include "IEntityTakeDamage.hpp"
#include "IEntitySetCollider.hpp"
#include "EntityMoveData.hpp"

#include <memory>
#include <SpEngine/Assets/Game/IGameObject.hpp>
#include <SpEngine/Clock/Clock.hpp>

// Define an enum for the entity type
enum class EntityType {
    Player,
    Queen,
    Rook,
    Bishop,
    Knight,
    Pawn
};

// UGLY IMPLEMENTATION



class Entity : public IGameObject
{
public:

    Entity() = default;
    ~Entity() override = default;
    Entity(const Entity& other) = default;
    Entity& operator=(const Entity& other) = default;
    Entity(Entity&& other) noexcept = default;
    Entity& operator=(Entity&& other) noexcept = default;

    Entity
    (
        const std::shared_ptr<IEntityAttack>& attackComponent,
        const std::shared_ptr<IEntityMove>& moveComponent,
        const std::shared_ptr<IEntityVisible>& visibleComponent,
        const std::shared_ptr<IEntitySetCollider>& colliderComponent,
        const std::shared_ptr<IEntityTakeDamage>& takeDamageComponent,
        const std::shared_ptr<IEntityDash>& dashComponent,
        const EntityType& entityType,
        const std::string& name
    );

    void InitializeValues();

    void PerformMove(const DX::XMFLOAT2& direction);
    void PerformDash(const DX::XMFLOAT2& direction, const bool& isDashing);
    void PerformVisible();
    void PerformAttack(const DX::XMFLOAT2& position, const DX::XMFLOAT2& direction); 
    void PerformTakeDamage(const float& damage);
    void PerformSetCollider();

    void Update() override;
    void OnStart() override;

    EntityType GetType() const { return m_type; }

private:
    std::shared_ptr<IEntityMove> m_move;
    std::shared_ptr<IEntityDash> m_dash;
    std::shared_ptr<IEntityVisible> m_visible;
    std::shared_ptr<IEntityAttack> m_attack;
    std::shared_ptr<IEntityTakeDamage> m_takeDamage;
    std::shared_ptr<IEntitySetCollider> m_setCollider;

    EntityMoveData m_moveData = {};

    EntityType m_type;
    float m_hp = 0;
    bool m_isAnimating = false;
    float m_spawnTimer = 1.9f;
    float m_iFrameTimer = 0.0f;
    float m_DeathAnimationTimer = 0.0f;
    float m_dashTimer = 0.0f;
    EntityState m_state;
};
