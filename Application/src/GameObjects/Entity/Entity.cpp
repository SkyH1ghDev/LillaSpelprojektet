#include "Entity.hpp"
#include "EntityAttackComponentFactory.hpp"
#include "EntityMoveComponentFactory.hpp"
#include "EntityTakeDamageComponentFactory.hpp"
#include "EntityUseCardComponentFactory.hpp"
#include "EntityVisibleComponentFactory.hpp"
#include "EntitySetColliderComponentFactory.hpp"
#include <iostream>

Entity::Entity(EntityType entityType) :
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
    PerformVisible(EntityState::WalkDown);
    this->m_shouldRender = true;
    this->CenterOrigin(true);
    this->m_origonOffset = DX::XMFLOAT2(0, 50);
    //PerformAttack();
    PerformSetCollider();
}

void Entity::PerformSetCollider()
{
    this->m_collider = this->m_setCollider->CreateCollider(this->m_position);
}

void Entity::Update()
{
    this->m_visible->UpdateLayer(this->m_position, this->m_layerFloat);
}

void Entity::PerformMove(const DX::XMFLOAT2& direction, bool dashing) {
    if (m_move != nullptr) {
        m_position = m_move->Move(m_position, direction, dashing, this->m_collider);
    }
}