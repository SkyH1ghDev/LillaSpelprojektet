#include "Entity.hpp"
#include "EntityAttackComponentFactory.hpp"
#include "EntityMoveComponentFactory.hpp"
#include "EntityTakeDamageComponentFactory.hpp"
#include "EntityUseCardComponentFactory.hpp"
#include "EntityVisibleComponentFactory.hpp"
#include "EntitySetColliderComponentFactory.hpp"
#include <iostream>

Entity::Entity(EntityType entityType, const std::string& name) : IGameObject(name),
    m_move(CreateMoveComponent(entityType)),
    m_visible(CreateVisibleComponent(entityType)),
    m_attack(CreateAttackComponent(entityType)),
    m_takeDamage(CreateTakeDamageComponent(entityType)),
    m_useCard(CreateUseCardComponent(entityType)),
    m_type(entityType),
    m_setCollider(CreateColliderComponent(entityType))
{
    std::cout << "Entity created of type: " << (m_type == EntityType::Player ? "Player" : "Enemy") << "\n";
}

void Entity::OnStart()
{
    PerformVisible(EntityState::Spawn);
    this->m_shouldRender = true;
    this->CenterOrigin(true);
    this->m_origonOffset = DX::XMFLOAT2(0, 50);
    //PerformAttack();
    this->m_takeDamage->SetHealth(this->m_hp);
    PerformSetCollider();
}

void Entity::PerformSetCollider()
{
    this->m_collider = std::make_unique<Collider>(this->m_setCollider->CreateCollider(this->m_position));
}

void Entity::Update()
{
    if (m_isSpawning)
    {
        m_spawnTimer -= Clock::GetDeltaTime(); // Assuming GetDeltaTime() returns the time since last frame
        if (m_spawnTimer <= 0.0f)
        {
            m_isSpawning = false; // Enable movement and attacks
            PerformVisible(EntityState::WalkDown);
        }
        return; // Skip the rest of update logic while spawning
    }

    // Normal update logic after spawn animation finishes
    this->m_visible->UpdateLayer(this->m_position, this->m_layerFloat);
    if (this->m_iFrameTimer == 1)
    {
        PerformVisible(EntityState::TakingDamage);
    }
    if (this->m_iFrameTimer > 0)
    {
        this->m_iFrameTimer -= Clock::GetDeltaTime();
    }
    else
    {
        PerformVisible(EntityState::WalkDown);
    }
}

void Entity::PerformMove(const DX::XMFLOAT2& direction, bool dashing) {
    if (m_move != nullptr) {
        m_position = m_move->Move(m_position, direction, dashing, this->m_collider);
    }
}