#include "Entity.hpp"
#include "EntityAttackComponentFactory.hpp"
#include "EntityMoveComponentFactory.hpp"
#include "EntityTakeDamageComponentFactory.hpp"
#include "EntityUseCardComponentFactory.hpp"
#include "EntityVisibleComponentFactory.hpp"
#include <iostream>

Entity::Entity(EntityType entityType) :
    m_move(CreateMoveComponent(entityType)),
    m_visible(CreateVisibleComponent(entityType)),
    m_attack(CreateAttackComponent(entityType)),
    m_takeDamage(CreateTakeDamageComponent(entityType)),
    m_useCard(CreateUseCardComponent(entityType)),
    m_type(entityType)
{
    std::cout << "Entity created of type: " << (m_type == EntityType::Player ? "Player" : "Enemy") << "\n";
}

void Entity::OnStart()
{
    PerformVisible(EntityState::WalkDown);
    this->m_shouldRender = true;
    this->CenterOrigin(true);
    this->m_origonOffset = DX::XMFLOAT2(0, 50);
    //PerformAttack();
    this->m_collider = std::make_shared<Collider>(this->m_position, 10, CollisionLayer::Player, CollisionLayer::Projectile);
}

void Entity::Update()
{
    this->m_visible->UpdateLayer(this->m_position, this->m_layerFloat);
    this->m_collider->UpdatePosition(this->m_position);
}

void Entity::PerformMove(const DX::XMFLOAT2& direction, bool dashing) {
    if (m_move != nullptr) {
        m_position = m_move->Move(m_position, direction, dashing);
    }
}