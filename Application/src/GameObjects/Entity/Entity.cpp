#include "Entity.hpp"
#include "EntityAttackComponentFactory.hpp"
#include "EntityMoveComponentFactory.hpp"
#include "EntityTakeDamageComponentFactory.hpp"
#include "EntityUseCardComponentFactory.hpp"
#include "EntityVisibleComponentFactory.hpp"
#include "EntitySetColliderComponentFactory.hpp"
#include <iostream>
#include "EnemyManager.hpp"
#include <SpEngine/Clock/Clock.hpp>

#include "StatSheet.hpp"
#include "HealthBarManager.hpp"
#include "ManaBarManager.hpp"
#include <SpEngine/Audio/Sound.hpp>
#include <SpEngine/Manager/SceneManager.hpp>


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


void Entity::Initialize()
{
    this->m_state = EntityState::Spawning;
    this->m_isAnimating = false;
    PerformVisible(this->m_state);
    this->m_spawnTimer = 2.0;
    this->m_shouldRender = true;
    this->m_isAlive = true;
    //PerformAttack();
    this->m_isActive = true;
    this->m_takeDamage->SetHealth(this->m_hp);
    this->CenterOrigin(true);
    this->m_origonOffset = DX::XMFLOAT2(0, 50);
    if (!this->m_collider)
        PerformSetCollider();
    else
        this->m_collider->UpdatePosition(this->m_position);

    switch (m_type) {
        
        case EntityType::Player:
            this->m_DeathAnimationTimer = 3.9;
            break;
        
        case EntityType::Enemy:
            this->m_DeathAnimationTimer = 0.9;
            break;
        default:
            this->m_DeathAnimationTimer = 0.0;
            break;
    }
}


void Entity::OnStart()
{
    PerformVisible(this->m_state);
    this->m_spawnTimer = 2.0;
    this->CenterOrigin(true);
    this->m_origonOffset = DX::XMFLOAT2(0, 50);
}

void Entity::PerformSetCollider()
{
    this->m_collider = std::make_unique<Collider>(this->m_setCollider->CreateCollider(this->m_position));
}

void Entity::Update()
{
    this->UpdateAnimation();

    if (this->m_state == EntityState::Spawning)
    {
        if (!this->m_isAnimating)
            this->ResetAnimation();
        this->m_isAnimating = true;
        m_spawnTimer -= Clock::GetDeltaTime(); // Assuming GetDeltaTime() returns the time since last frame
        if (m_spawnTimer <= 0.0f)
        {
            this->m_spawnTimer = 0;
            this->m_state = EntityState::Base;
            this->m_isAnimating = false;
        }
        return;
    }

    // Normal update logic after spawn animation finishes
    this->m_visible->UpdateLayer(this->m_position, this->m_layerFloat);

    if (this->m_damageTimer > 0)
    {
        if (!this->m_isAnimating && this->m_state != EntityState::TakingDamage)
            this->ResetAnimation();
        this->m_isAnimating = true;
        this->m_state = EntityState::TakingDamage;
        this->m_damageTimer -= Clock::GetDeltaTime();
        if (this->m_damageTimer <= 0)
        {
            this->m_damageTimer = 0;
            this->m_state = EntityState::Base;
            this->m_isAnimating = false;
            this->m_iFrame = false;
        }
    }

    if (this->m_hp <= 0)
    {   
        if ((!this->m_isAnimating && this->m_state != EntityState::Dying) || this->m_state == EntityState::TakingDamage)
        {
            this->ResetAnimation();
            this->m_damageTimer = 0;
        }
        this->m_isAnimating = true;
        this->m_state = EntityState::Dying;
        this->m_DeathAnimationTimer -= Clock::GetDeltaTime();
        if (this->m_DeathAnimationTimer <= 0)
        {
            this->m_DeathAnimationTimer = 0;
            if (this->m_type != EntityType::Player)
            {

                SetShouldRender(false);
                this->m_isAlive = false;
                this->m_isActive = false;
            }
            else
            {
                this->m_state = EntityState::Dead;
                this->m_isAnimating = false;
                SetActive(false);
                
                PlayerDeath();
            }
        }
    }

    if (this->m_dashTimer > 0)
    {
        if (!this->m_isAnimating)
            this->ResetAnimation();
        this->m_isAnimating = true;
        this->m_dashTimer -= Clock::GetDeltaTime();
        if (this->m_dashTimer <= 0)
        {
            m_isAnimating = false;
            this->m_dashTimer = 0;
            this->m_state = EntityState::Base;
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
        if (dashing)
        {
            this->m_state = EntityState::Dashing;
            this->m_dashTimer = 0.5f;
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

void Entity::PerformTakeDamage(float damage)
{
    if (m_takeDamage && this->m_state != EntityState::Spawning && this->m_state != EntityState::Dying)
    {
        this->m_isAnimating = false;
        m_takeDamage->TakeDamage(this->m_hp, damage, this->m_isActive, this->m_shouldRender, this->m_damageTimer, this->m_iFrame);
    }
}

void Entity::PlayerDeath()
{
    SceneManager::UnloadScene();
    SceneManager::LoadScene("death");
    SceneManager::ResetScene("game");

    HealthBarManager::Reset();
    ManaBarManager::Reset();
    StatSheet::Reset();

    this->m_state = EntityState::Dead;
}



void Entity::Reset()
{
    this->m_state = EntityState::Spawning;
    //PerformVisible(this->m_state);
    this->m_spawnTimer = 2.0;
    this->CenterOrigin(true);
    this->m_origonOffset = DX::XMFLOAT2(0, 50);
    //PerformAttack();
    this->m_takeDamage->SetHealth(this->m_hp);
    this->m_animationTime = 0;
    this->m_iFrame = false;

    switch (m_type) {
    case EntityType::Player:
        this->m_DeathAnimationTimer = 3.9;
        this->m_isActive = true;
        break;
    case EntityType::Enemy:
        this->m_DeathAnimationTimer = 0.9;
        this->m_isActive = false;
        this->m_isAlive = false;
        this->m_shouldRender = false;
        break;
    default:
        this->m_DeathAnimationTimer = 0.0;
        break;
    }
}