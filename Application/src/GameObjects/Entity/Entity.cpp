#include "Entity.hpp"
#include "EnemyManager.hpp"
#include <SpEngine/Clock/Clock.hpp>

Entity::Entity
(
    const std::shared_ptr<IEntityAttack>& attackComponent,
    const std::shared_ptr<IEntityMove>& moveComponent,
    const std::shared_ptr<IEntityVisible>& visibleComponent,
    const std::shared_ptr<IEntitySetCollider>& colliderComponent,
    const std::shared_ptr<IEntityTakeDamage>& takeDamageComponent,
    const EntityType& entityType,
    const std::string& name
) : IGameObject(name)
{
    this->m_move = moveComponent;
    this->m_visible = visibleComponent;
    this->m_attack = attackComponent;
    this->m_takeDamage = takeDamageComponent;
    this->m_setCollider = colliderComponent;
    this->m_type = entityType;
}


void Entity::InitializeValues()
{
    this->m_state = EntityState::Spawning;
    PerformVisible(this->m_state);
    this->m_spawnTimer = 2.0;
    this->m_shouldRender = true;
    this->m_isAlive = true;
    this->m_isActive = true;
    this->CenterOrigin(true);
    this->m_origonOffset = DX::XMFLOAT2(0, 50);
    //PerformAttack();
    this->m_takeDamage->SetHealth(this->m_hp);
    PerformSetCollider();
    
    switch (m_type) {
        
        case EntityType::Player:
            this->m_DeathAnimationTimer = 3.9;
            break;
        
        case EntityType::Bishop:
        default:
            this->m_DeathAnimationTimer = 0.0;
            break;
    }
}


void Entity::OnStart()
{
    InitializeValues();
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
        if (!this->m_isAnimating && this->m_state != EntityState::TakingDamage)
            this->ResetAnimation();
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
        this->m_iFrameTimer = 0;
        if (!this->m_isAnimating && this->m_state != EntityState::Dying)
            this->ResetAnimation();
        this->m_isAnimating = true;
        this->m_state = EntityState::Dying;
        this->m_DeathAnimationTimer -= Clock::GetDeltaTime();
        if (this->m_DeathAnimationTimer <= 0)
        {
            this->m_state = EntityState::Dead;
            this->m_isAnimating = false;
            SetActive(false);
            SetIsAlive(false);
            if (this->m_type != EntityType::Player)
            {
                SetShouldRender(false);
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
        
        m_position = m_move->Move(m_position, direction, this->m_collider, dashing);
    }
}

void Entity::PerformVisible(EntityState entityState)
{
    if (m_visible)
    {
        m_visible->Visible(m_textureName, m_position, this->m_state, m_layerFloat, m_scaleFloat);
    }
        
}