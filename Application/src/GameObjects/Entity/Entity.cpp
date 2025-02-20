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
    this->m_state = EntityState::Spawning;
    PerformVisible(this->m_state);
    this->m_spawnTimer = 2.0;
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
    if (this->m_state == EntityState::Spawning)
    {
        m_spawnTimer -= Clock::GetDeltaTime(); // Assuming GetDeltaTime() returns the time since last frame
        if (m_spawnTimer <= 0.0f)
        {
            this->m_state = EntityState::Base;
        }
        return;
    }

    // Normal update logic after spawn animation finishes
    this->m_visible->UpdateLayer(this->m_position, this->m_layerFloat);

    if (this->m_iFrameTimer > 0)
    {
        this->m_isAnimating = true;
        this->m_state = EntityState::TakingDamage;
        this->m_iFrameTimer -= Clock::GetDeltaTime();
        if (this->m_iFrameTimer <= 0)
        {
            this->m_state = EntityState::Base;
            this->m_isAnimating = false;
        }
    }

    if (this->m_hp <= 0)
    {
        this->m_isAnimating = true;
        this->m_state = EntityState::Dying;
        this->m_DeathAnimationTimer -= Clock::GetDeltaTime();
        if (this->m_DeathAnimationTimer <= 0)
        {
            this->m_state = EntityState::Dead;
            this->m_isAnimating = false;
            SetActive(false);
        }
    }
    PerformVisible(this->m_state);

}

void Entity::PerformMove(const DX::XMFLOAT2& direction, bool dashing) {
    if (m_move != nullptr && this->m_state != EntityState::Dying) {
        if (direction.y == -1 && !m_isAnimating)
        {
            this->m_state = EntityState::WalkUp;
        }
        else if (direction.y == 1 && !m_isAnimating)
        {
            this->m_state = EntityState::WalkDown;
        }
        else if (direction.x == 1 && !m_isAnimating)
        {
            this->m_state = EntityState::WalkRight;
        }
        else if (direction.x == -1 && !m_isAnimating)
        {
            this->m_state = EntityState::WalkLeft;
        }
        m_position = m_move->Move(m_position, direction, dashing, this->m_collider);
    }
}

void Entity::PerformVisible(EntityState entityState)
{
    if (m_visible)
    {
        m_visible->Visible(m_textureName, m_position, this->m_state, m_layerFloat, m_scaleFloat);
    }
        
}