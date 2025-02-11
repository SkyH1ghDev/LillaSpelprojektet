#include "Projectile.hpp"
#include "ProjectileMoveComponentFactory.hpp"
#include "ProjectileVisibleComponentFactory.hpp"
#include "ProjectileHitComponentFactory.hpp"
#include <iostream>

Projectile::Projectile(ProjectileType projectileType) :
    m_move(CreateMoveComponent(projectileType)),
    m_visible(CreateVisibleComponent(projectileType)),
    m_hit(CreateHitComponent(projectileType)),
    m_type(projectileType)
{
    std::cout << "Projectile created of type: " << (m_type == ProjectileType::Base ? "Base" : "not base") << "\n";
}

void Projectile::OnStart()
{
    PerformVisible(ProjectileState::Inactive);
    this->m_shouldRender = true;
}

void Projectile::Update()
{

}

void Projectile::PerformMove(const DX::XMFLOAT2& direction, float velocity) {
    if (m_move != nullptr) {
        this->m_position = m_move->Move(this->m_position, direction, velocity);
    }
}
