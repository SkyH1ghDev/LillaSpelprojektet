#pragma once
#include "IEntityMove.hpp"
#include "IEntityVisible.hpp"
#include "IEntityAttack.hpp"
#include "IEntityTakeDamage.hpp"
#include "IEntitySetCollider.hpp"
#include "Projectile.hpp"

#include <memory>
#include <SpEngine/Assets/Game/IGameObject.hpp>
#include <SpEngine/Clock/Clock.hpp>

// Define an enum for the entity type
enum class EntityType {
    Player,
    Queen,
    Rook,
    RookAlt,
    Knight,
    Bishop,
    BishopAlt,
    Pawn,
    PawnAlt
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

    Entity
    (
        const std::shared_ptr<IEntityAttack>& attackComponent,
        const std::shared_ptr<IEntityMove>& moveComponent,
        const std::shared_ptr<IEntityVisible>& visibleComponent,
        const std::shared_ptr<IEntityTakeDamage>& takeDamageComponent,
        const std::shared_ptr<IEntitySetCollider>& setColliderComponent,
        const EntityType& type,
        const std::string& name
    );
    
    void Initialize();
    void PerformMove(const DX::XMFLOAT2& direction, bool dashing);
    void PerformVisible();
    void PerformAttack(DX::XMFLOAT2 position, DX::XMFLOAT2 direction);
    void PerformTakeDamage(float damage, ProjectileType projectileType);

    void PerformSetCollider();
    void PlayerDeath();

    void Update() override;
    void OnStart() override;
    void Reset() override;

    bool Dashing() const;
    void SetIsStunned(bool isStunned);
    bool IsStunned() const;

    bool HasIFrame();
    void AddFreeze(float time);

    void SetState(EntityState state);
    EntityState GetState();

    EntityType GetType() const { return m_type; }

private:
    std::shared_ptr<IEntityMove> m_move;
    std::shared_ptr<IEntityVisible> m_visible;
    std::shared_ptr<IEntityAttack> m_attack;
    std::shared_ptr<IEntityTakeDamage> m_takeDamage;
    std::shared_ptr<IEntitySetCollider> m_setCollider;

    EntityType m_type;
    float m_hp = 0;
    bool m_isAnimating = false;
    float m_spawnTimer = 1.9f;
    float m_damageTimer = 0.0f;
    float m_DeathAnimationTimer = 0.0f;
    float m_dashTimer = 0.0f;
    bool m_isDashing = false;
    EntityState m_state = EntityState::Base;
    bool m_iFrame = false;
    bool m_isStunned = false;
    float m_stunnedTimer;
    float m_freezeTimer = 0;
    EntityState m_previousState = EntityState::Base;
};

inline void Entity::AddFreeze(float time)
{
    this->m_freezeTimer += time;
}