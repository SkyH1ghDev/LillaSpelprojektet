#pragma once
#include <memory>

#include <SpEngine/Assets/IGameObject.hpp>
#include <SpEngine/Physics/Collider.hpp>

// Define an enum for the entity type
enum class EntityType {
    Player,
    Enemy
};

#include "IEntityMove.hpp"
#include "IEntityVisible.hpp"
#include "IEntityAttack.hpp"
#include "IEntityTakeDamage.hpp"
#include "IEntityUseCard.hpp"

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

    void PerformMove(const DX::XMFLOAT2& direction, bool dashing);
    void PerformVisible(EntityState entityState) { if (m_visible) m_visible->Visible(m_textureName, m_position, entityState, m_layerFloat, m_scaleFloat); }
    void PerformAttack(DX::XMFLOAT2 position, DX::XMFLOAT2 direction) { if (m_attack) m_attack->Attack(position, direction); }
    void PerformTakeDamage() { if (m_takeDamage) m_takeDamage->TakeDamage(); }
    void PerformUseCard() { if (m_useCard) m_useCard->UseCard(); }

    void Update() override;
    void OnStart() override;

    EntityType GetType() const { return m_type; }

private:
    std::shared_ptr<IEntityMove> m_move;
    std::shared_ptr<IEntityVisible> m_visible;
    std::shared_ptr<IEntityAttack> m_attack;
    std::shared_ptr<IEntityTakeDamage> m_takeDamage;
    std::shared_ptr<IEntityUseCard> m_useCard;
    EntityType m_type;
};
