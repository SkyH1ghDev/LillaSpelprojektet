#pragma once
#include "IEntityMove.hpp"
#include "IEntityVisible.hpp"
#include "IEntityAttack.hpp"
#include "IEntityTakeDamage.hpp"
#include "IEntityUseCard.hpp"
#include "IEntitySetCollider.hpp"

#include <memory>
#include <SpEngine/Assets/Game/IGameObject.hpp>
#include <SpEngine/Clock/Clock.hpp>

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

    Entity(EntityType entityType, const std::string& name);
    void Initialize();
    void PerformMove(const DX::XMFLOAT2& direction, bool dashing);
    void PerformVisible(EntityState entityState);
    void PerformAttack(DX::XMFLOAT2 position, DX::XMFLOAT2 direction) { if (m_attack && this->m_state != EntityState::Spawning && this->m_state != EntityState::Dying) m_attack->Attack(position, direction); }
    void PerformTakeDamage(float damage);
    void PerformUseCard() { if (m_useCard) m_useCard->UseCard(); }
    void PerformSetCollider();
    void PlayerDeath();

    void Update() override;
    void OnStart() override;
    void Reset() override;

    EntityType GetType() const { return m_type; }

private:
    std::shared_ptr<IEntityMove> m_move;
    std::shared_ptr<IEntityVisible> m_visible;
    std::shared_ptr<IEntityAttack> m_attack;
    std::shared_ptr<IEntityTakeDamage> m_takeDamage;
    std::shared_ptr<IEntityUseCard> m_useCard;
    std::shared_ptr<IEntitySetCollider> m_setCollider;

    EntityType m_type;
    float m_hp = 0;
    bool m_isAnimating = false;
    float m_spawnTimer = 1.9f;
    float m_damageTimer = 0.0f;
    float m_DeathAnimationTimer = 0.0f;
    float m_dashTimer = 0.0f;
    EntityState m_state = EntityState::Base;
    bool m_iFrame = false;
};
