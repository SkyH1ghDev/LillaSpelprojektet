#include "Entity.hpp"

#include <SpEngine/Clock/Clock.hpp>

#include "StatSheet.hpp"
#include "HealthBarManager.hpp"
#include "ManaBarManager.hpp"
#include <SpEngine/Audio/Sound.hpp>
#include <SpEngine/Manager/SceneManager.hpp>


Entity::Entity
(
    const std::shared_ptr<IEntityAttack>& attackComponent,
    const std::shared_ptr<IEntityMove>& moveComponent,
    const std::shared_ptr<IEntityVisible>& visibleComponent,
    const std::shared_ptr<IEntityTakeDamage>& takeDamageComponent,
    const std::shared_ptr<IEntitySetCollider>& setColliderComponent,
    const EntityType& type,
    const std::string& name
) : IGameObject(name)
{
    this->m_attack = attackComponent;
    this->m_move = moveComponent;
    this->m_visible = visibleComponent;
    this->m_takeDamage = takeDamageComponent;
    this->m_setCollider = setColliderComponent;
    this->m_type = type;
}


void Entity::Initialize()
{
    this->m_state = EntityState::Spawning;
    this->m_isAnimating = false;
    PerformVisible();
    this->m_spawnTimer = 2.0;
    this->m_shouldRender = true;
    this->m_isAlive = true;
    //PerformAttack();
    this->m_isActive = true;
    this->m_takeDamage->SetHealth(this->m_hp);
    this->CenterOrigin(true);
    this->m_origonOffset = DX::XMFLOAT2(0, 50);
    this->m_isDashing = false;

    if (!this->m_collider)
        PerformSetCollider();
    else
        this->m_collider->UpdatePosition(this->m_position);

    switch (m_type) {
        
        case EntityType::Player:
            this->m_DeathAnimationTimer = 3.9;
            break;
        
        case EntityType::Bishop:
            this->m_DeathAnimationTimer = 0.9;
            break;
        case EntityType::BishopAlt:
            this->m_DeathAnimationTimer = 0.9;
            break;

        case EntityType::Rook:
            this->m_DeathAnimationTimer = 0.9;
            this->m_stunnedTimer = 0.9;
            break;
        case EntityType::RookAlt:
            this->m_DeathAnimationTimer = 0.9;
            this->m_stunnedTimer = 0.9;
            break;
        
        case EntityType::Queen:
        case EntityType::Knight:
        case EntityType::Pawn:
            this->m_DeathAnimationTimer = 0.9;
            break;
        default:
            this->m_DeathAnimationTimer = 0.9;
            break;
    }
}


void Entity::OnStart()
{
    PerformVisible();
    this->m_spawnTimer = 2.0;
    this->CenterOrigin(true);
    this->m_origonOffset = DX::XMFLOAT2(0, 50);
    this->m_stunnedTimer = 0.9;
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

    if (this->m_dashTimer > 0 && this->m_type == EntityType::Player)
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

    if (this->m_isStunned)
    {
        if (!this->m_isAnimating)
            this->ResetAnimation();
        this->m_isAnimating = true;
        this->m_stunnedTimer -= Clock::GetDeltaTime();
        this->m_state = EntityState::Stunned;
        if (this->m_stunnedTimer <= 0)
        {
            this->m_isAnimating = false;
            this->m_stunnedTimer = 0.9;
            this->m_state = EntityState::Base;
            this->m_isStunned = false;
        }
    }

    PerformVisible();

}

void Entity::PerformMove(const DX::XMFLOAT2& direction, bool dashing) {
    if (m_move != nullptr && this->m_state != EntityState::Dying && (this->m_state != EntityState::Spawning || this->m_type == EntityType::Player)) {
        if (direction.y == -1 && !m_isAnimating && !this->m_isDashing)
        {
            this->m_state = EntityState::WalkUp;
        }
        else if (direction.y == 1 && !m_isAnimating && !this->m_isDashing)
        {
            this->m_state = EntityState::WalkDown;
        }
        else if (direction.x == 1 && !m_isAnimating && !this->m_isDashing)
        {
            this->m_state = EntityState::WalkRight;
        }
        else if (direction.x == -1 && !m_isAnimating && !this->m_isDashing)
        {
            this->m_state = EntityState::WalkLeft;
        }
        if (dashing && !this->m_isDashing)
        {
            this->m_dashTimer = 0.12f;
            this->m_isDashing = true;
        }
        
        m_position = m_move->Move(m_position, direction, this->m_isDashing, this->m_collider, this->m_isStunned);

        if (m_isDashing)
            this->m_state = EntityState::Dashing;
    }
}

void Entity::PerformVisible()
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
        m_takeDamage->TakeDamage(this->m_hp, damage, this->m_isAlive, this->m_shouldRender, this->m_damageTimer, this->m_iFrame);
    }
}

void Entity::PerformAttack(DX::XMFLOAT2 position, DX::XMFLOAT2 direction)
{
    if
    (
        m_attack && this->m_state != EntityState::Dying 
        &&
        (
            this->m_state != EntityState::Spawning
            ||
            this->m_type == EntityType::Player
        )
    )
    {
        m_attack->Attack(position, direction);
    }
}


void Entity::PerformSetCollider()
{
    this->m_collider = std::make_unique<Collider>(this->m_setCollider->CreateCollider(this->m_position));
}

void Entity::PlayerDeath()
{
    SceneManager::UnloadScene();
    SceneManager::LoadScene("death");
    SceneManager::ResetScene("game");
    this->m_isActive = false;
    Sound::SetMusic("menu_theme.wav", 0.4f);
    Sound::PlayOnce("game_over.wav", 0.4f);
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
    this->m_isDashing = false;

    switch (m_type) {
    case EntityType::Player:
        this->m_DeathAnimationTimer = 3.9;
        this->m_isActive = true;
        break;
    case EntityType::Bishop:
        this->m_DeathAnimationTimer = 0.9;
        this->m_isActive = false;
        this->m_isAlive = false;
        this->m_shouldRender = false;
        break;
    case EntityType::BishopAlt:
        this->m_DeathAnimationTimer = 0.9;
        this->m_isActive = false;
        this->m_isAlive = false;
        this->m_shouldRender = false;
        break;
    default:
        this->m_DeathAnimationTimer = 0.9;
        this->m_isActive = false;
        this->m_isAlive = false;
        this->m_shouldRender = false;
        break;
    }
}

bool Entity::Dashing() const
{
    return this->m_isDashing;
}

void Entity::SetIsStunned(bool isStunned)
{
    this->m_isStunned = isStunned;
}

bool Entity::IsStunned() const
{
    return this->m_isStunned;
}

void Entity::SetState(EntityState state)
{
    this->m_state = state;
}

EntityState Entity::GetState()
{
    return this->m_state;
}
