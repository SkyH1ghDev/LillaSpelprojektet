#include "Projectile.hpp"
#include "ProjectileMoveComponentFactory.hpp"
#include "ProjectileVisibleComponentFactory.hpp"
#include "ProjectileHitComponentFactory.hpp"
#include "ProjectileSetColliderComponentFactory.hpp"
#include <SpEngine/Clock/Clock.hpp>
#include <iostream>

Projectile::Projectile(ProjectileType projectileType, const std::string& name) :
    m_move(CreateMoveComponent(projectileType)),
    m_visible(CreateVisibleComponent(projectileType)),
    m_hit(CreateHitComponent(projectileType)),
    m_setCollider(CreateSetColliderComponent(projectileType)),
    m_type(projectileType),
    m_velocity(0), 
    m_lifetime(0)
{
    std::cout << "Projectile created of type: " << (m_type == ProjectileType::Base ? "Base" : "not base") << "\n";
}

void Projectile::Initialize(DX::XMFLOAT2 position, DX::XMFLOAT2 direction, float velocity, float lifetime, float damage) {
    this->m_position = position;
    this->m_direction = direction;
    this->m_velocity = velocity;
    this->m_lifetime = lifetime;
    this->m_damage = damage;

    this->ResetAnimation();

    // Normalize direction
    float length = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
    m_direction = DX::XMFLOAT2(direction.x / length, direction.y / length);

    // Activate projectile
    this->m_isActive = true;
    this->m_shouldRender = true;
    this->m_isAlive = true;
    this->m_isAnimating = false;
    PerformVisible();
    this->CenterOrigin(true);
    PerformSetCollider();
    this->m_state = ProjectileState::Active;
    std::cout << "Projectile initialized of type: " << (m_type == ProjectileType::Base ? "Base" : "not base") << "\n";

    DX::XMFLOAT2 zeroAngle = DX::XMFLOAT2(1, 0);

    if (this->m_direction.y > 0)
        this->SetRotation(DX::XMVectorGetX(DX::XMVector2AngleBetweenVectors(DX::XMLoadFloat2(&this->m_direction), DX::XMLoadFloat2(&zeroAngle))));
    else
        this->SetRotation(-DX::XMVectorGetX(DX::XMVector2AngleBetweenVectors(DX::XMLoadFloat2(&this->m_direction), DX::XMLoadFloat2(&zeroAngle))));
}

void Projectile::OnStart()
{
    PerformVisible();
    this->m_shouldRender = false;
    this->m_isActive = false;
    this->m_isAlive = false;
    this->CenterOrigin(true);
}

void Projectile::Update()
{
    if (m_lifetime > 0 && m_isAlive)
    {
        this->UpdateAnimation();
        this->m_visible->UpdateLayer(this->m_position, this->m_layerFloat);
        PerformMove(this->m_direction, this->m_velocity);
        m_lifetime -= Clock::GetDeltaTime();
        this->m_collider->UpdatePosition(this->m_position);
        if (PhysicsEngine::WallProjectileCollision(m_collider) || PhysicsEngine::WallProjectileCollision(m_collider))
        {
            this->m_isActive = false;
            this->m_isAlive = false;
            this->m_shouldRender = false;
        }
    }
    else if(this->m_hasDeathAnimation)
    {
        this->m_state = ProjectileState::Exploding;
        SetCollider(nullptr);
        if (!this->m_isAnimating)
        {
            this->ResetAnimation();
            this->m_animationTimer = 0.4;
        }
        this->m_isAnimating = true;
        this->UpdateAnimation();
        this->m_animationTimer -= Clock::GetDeltaTime();
        if (this->m_animationTimer <= 0)
        {
            this->m_isActive = false;
            this->m_isAlive = false;
            this->m_shouldRender = false;
        }
    }
    else
    {
        this->m_isActive = false;
        this->m_isAlive = false;
        this->m_shouldRender = false;
    }
    
    PerformVisible();
}
void Projectile::PerformSetCollider()
{
    this->m_collider = std::make_unique<Collider>(this->m_setCollider->SetCollider(this->m_position));
}

void Projectile::PerformMove(const DX::XMFLOAT2& direction, float velocity) {
    if (m_move != nullptr && this->m_state != ProjectileState::Exploding) {
        this->m_position = m_move->Move(this->m_position, direction, velocity);
    }
}

float Projectile::GetDamage() const
{
    return this->m_damage * this->m_damageAmp;
}   

void Projectile::PerformHit()
{
    if (m_hit)
    {
        m_hit->Hit(this->m_isAlive);
    }  
}

void Projectile::Reset()
{
    PerformVisible();
    this->m_shouldRender = false;
    this->m_isActive = false;
    this->m_isAlive = false;
    this->CenterOrigin(true);
}