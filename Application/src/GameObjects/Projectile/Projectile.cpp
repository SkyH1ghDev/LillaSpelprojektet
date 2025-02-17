#include "Projectile.hpp"
#include "ProjectileMoveComponentFactory.hpp"
#include "ProjectileVisibleComponentFactory.hpp"
#include "ProjectileHitComponentFactory.hpp"
#include <SpEngine/Clock/Clock.hpp>
#include <iostream>

Projectile::Projectile(ProjectileType projectileType) :
    m_move(CreateMoveComponent(projectileType)),
    m_visible(CreateVisibleComponent(projectileType)),
    m_hit(CreateHitComponent(projectileType)),
    m_type(projectileType),
    m_velocity(0), 
    m_lifetime(0)
{
    std::cout << "Projectile created of type: " << (m_type == ProjectileType::Base ? "Base" : "not base") << "\n";
}

void Projectile::Initialize(DX::XMFLOAT2 position, DX::XMFLOAT2 direction, float velocity, float lifetime) {
    this->m_position = position;
    this->m_direction = direction;
    this->m_velocity = velocity;
    this->m_lifetime = lifetime;

    // Normalize direction
    float length = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
    m_direction = DX::XMFLOAT2(direction.x / length, direction.y / length);

    // Activate projectile
    this->m_isActive = true;
    this->m_shouldRender = true;
    PerformVisible(ProjectileState::Inactive);
    this->CenterOrigin(true);
    std::cout << "Projectile initialized of type: " << (m_type == ProjectileType::Base ? "Base" : "not base") << "\n";
}

void Projectile::OnStart()
{
    PerformVisible(ProjectileState::Inactive);
    this->m_shouldRender = false;
    this->m_isActive = false;
    this->CenterOrigin(true);

}

void Projectile::Update()
{
    if (m_lifetime > 0)
    {
        this->m_visible->UpdateLayer(this->m_position, this->m_layerFloat);
        PerformMove(this->m_direction, this->m_velocity);
        m_lifetime -= Clock::GetDeltaTime();
        m_rotationFloat += Clock::GetDeltaTime() * 20;
    }
    else
    {
        this->m_isActive = false;
        this->m_shouldRender = false;
    }
}

void Projectile::PerformMove(const DX::XMFLOAT2& direction, float velocity) {
    if (m_move != nullptr) {
        this->m_position = m_move->Move(this->m_position, direction, velocity);
    }
}
