#include "Projectile.hpp"
#include <SpEngine/Clock/Clock.hpp>
#include <iostream>
#include <SpEngine/Audio/Sound.hpp>

Projectile::Projectile
(
    const std::shared_ptr<IProjectileMove>& moveComponent,
    const std::shared_ptr<IProjectileHit>& hitComponent,
    const std::shared_ptr<IProjectileSetCollider>& setColliderComponent,
    const std::shared_ptr<IProjectileVisible>& visibleComponent,
    const ProjectileType& type,
    const std::string& name
) : IGameObject(name)
{
    this->m_move = moveComponent;
    this->m_hit = hitComponent;
    this->m_visible = visibleComponent;
    this->m_setCollider = setColliderComponent;
    this->m_type = type;
    this->m_velocity = 0;
    this->m_lifetime = 0;
}

void Projectile::Initialize(DX::XMFLOAT2 position, DX::XMFLOAT2 direction, float velocity, float lifetime, float damage) {
    this->m_position = position;
    this->m_direction = direction;
    this->m_velocity = velocity;
    this->m_lifetime = lifetime;
    this->m_maxlifetime = lifetime;
    this->m_damage = damage;
    this->m_hasHit = false;
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
    if (m_lifetime > 0 && !this->m_hasHit)
    {
        this->UpdateAnimation();
        this->m_visible->UpdateLayer(this->m_position, this->m_layerFloat);
        PerformMove(this->m_direction, this->m_velocity);
        m_lifetime -= Clock::GetDeltaTime();
        this->m_collider->UpdatePosition(this->m_position);
        if (PhysicsEngine::WallProjectileCollision(m_collider) && this->m_type != ProjectileType::DisruptorWave)
        {
            if (this->m_type == ProjectileType::FireBall)
                this->m_velocity = 0;
            else
            {
                this->m_hasHit = true;
            }
        }
        if (this->m_type == ProjectileType::DisruptorWave)
        {
            float minRadius = 30 * this->m_maxlifetime;
            float maxRadius = 120 * this->m_maxlifetime;
            //this->m_collider->SetRadius(minRadius + (maxRadius - minRadius) * (1 - (this->m_lifetime / this->m_maxlifetime))); //Linear
            this->m_collider->SetRadius(minRadius + (maxRadius - minRadius) * (1 - exp(-3 * (1 - (this->m_lifetime / this->m_maxlifetime)))));
        }

        if (this->m_type == ProjectileType::FireBall)
        {
            this->m_rotationFloat = 0;
            if (this->m_velocity <= 0)
                this->m_velocity = 0;
            else
                this->m_velocity -= Clock::GetDeltaTime() * 100;
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
            this->m_isAnimating = false;
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
        m_hit->Hit(this->m_hasHit);
    }  
}

void Projectile::Reset()
{
    PerformVisible();
    this->m_shouldRender = false;
    this->m_isAnimating = false;
    this->m_isActive = false;
    this->m_isAlive = false;
    this->m_hasHit = false;
    this->CenterOrigin(true);
}