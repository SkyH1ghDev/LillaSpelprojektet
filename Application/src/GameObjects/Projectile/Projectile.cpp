#include "Projectile.hpp"
#include "ProjectileMoveComponentFactory.hpp"
#include "ProjectileVisibleComponentFactory.hpp"
#include "ProjectileHitComponentFactory.hpp"
#include <SpEngine/Clock/Clock.hpp>
#include <iostream>

Projectile::Projectile(ProjectileType projectileType, DX::XMFLOAT2 position, DX::XMFLOAT2 direction, float velocity, float lifetime) :
    m_move(CreateMoveComponent(projectileType)),
    m_visible(CreateVisibleComponent(projectileType)),
    m_hit(CreateHitComponent(projectileType)),
    m_type(projectileType),
    m_setPosition(position),
    m_direction(direction),
    m_velocity(velocity),
    m_lifetime(lifetime)
{
    float length = sqrt(pow(direction.x, 2) + pow(direction.y, 2));
    m_direction = DX::XMFLOAT2(direction.x / length, direction.y / length);
    std::cout << "Projectile created of type: " << (m_type == ProjectileType::Base ? "Base" : "not base") << "\n";
}

void Projectile::OnStart()
{
    PerformVisible(ProjectileState::Inactive);
    this->m_shouldRender = true;
    this->m_position = m_setPosition;

}

void Projectile::Update()
{
    if (m_lifetime > 0)
    {
        PerformMove(this->m_direction, this->m_velocity);
        m_lifetime -= 0.2 * Clock::GetDeltaTime();
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
