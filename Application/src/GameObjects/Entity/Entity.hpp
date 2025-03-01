#pragma once
#include "IEntityMove.hpp"
#include "IEntityVisible.hpp"
#include "IEntityAttack.hpp"
#include "IEntityTakeDamage.hpp"
#include "IEntitySetCollider.hpp"

#include <memory>
#include <SpEngine/Assets/Game/IGameObject.hpp>
#include <SpEngine/Clock/Clock.hpp>

// Define an enum for the entity type
enum class EntityType {
    Player,
    Bishop,
    Rook
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

    Entity(EntityType entityType, const std::string& name);
    void Initialize();
    void PerformMove(const DX::XMFLOAT2& direction, bool dashing);
    void PerformVisible(EntityState entityState);
    void PerformAttack(DX::XMFLOAT2 position, DX::XMFLOAT2 direction) { if (m_attack && this->m_state != EntityState::Dying 
        && (this->m_state != EntityState::Spawning || this->m_type == EntityType::Player)) m_attack->Attack(position, direction); }
    void PerformTakeDamage(float damage);
    void PerformSetCollider();
    void PlayerDeath();

    void Update() override;
    void OnStart() override;
    void Reset() override;

    bool Dashing() const;
    bool IsStunned() const;
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
};
