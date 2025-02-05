#include "Entity.hpp"
#include <iostream>

#include <memory>

#include "EnemyAttack.hpp"
#include "EnemyMove.hpp"
#include "EnemyTakeDamage.hpp"
#include "EnemyUseCard.hpp"
#include "EnemyVisible.hpp"
#include "PlayerAttack.hpp"
#include "PlayerMove.hpp"
#include "PlayerTakeDamage.hpp"
#include "PlayerUseCard.hpp"
#include "PlayerVisible.hpp"

// Factory function to create appropriate components
std::shared_ptr<IAttack> CreateAttackComponent(EntityType type) {
    switch (type) {
    case EntityType::Player:
        return std::make_shared<PlayerAttack>();
    case EntityType::Enemy:
        return std::make_shared<EnemyAttack>();
    default:
        throw std::invalid_argument("Unknown EntityType in CreateAttackComponent");
    }
}

std::shared_ptr<IMove> CreateMoveComponent(EntityType type) {
    switch (type) {
    case EntityType::Player:
        return std::make_shared<PlayerMove>();
    case EntityType::Enemy:
        return std::make_shared<EnemyMove>();
    default:
        throw std::invalid_argument("Unknown EntityType in CreateMoveComponent");
    }
}

std::shared_ptr<ITakeDamage> CreateTakeDamageComponent(EntityType type) {
    switch (type) {
    case EntityType::Player:
        return std::make_shared<PlayerTakeDamage>();
    case EntityType::Enemy:
        return std::make_shared<EnemyTakeDamage>();
    default:
        throw std::invalid_argument("Unknown EntityType in CreateTakeDamageComponent");
    }
}

std::shared_ptr<IUseCard> CreateUseCardComponent(EntityType type) {
    switch (type) {
    case EntityType::Player:
        return std::make_shared<PlayerUseCard>();
    case EntityType::Enemy:
        return std::make_shared<EnemyUseCard>();
    default:
        throw std::invalid_argument("Unknown EntityType in CreateUseCardComponent");
    }

}

std::shared_ptr<IVisible> CreateVisibleComponent(EntityType type) {
    switch (type) {
    case EntityType::Player:
        return std::make_shared<PlayerVisible>();
    case EntityType::Enemy:
        return std::make_shared<EnemyVisible>();
    default:
        throw std::invalid_argument("Unknown EntityType in CreateVisibleComponent");
    }
}

// Constructor: Decides behavior based on entity type
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
    PerformVisible();
    this->m_shouldRender = true;
}

void Entity::Update()
{

}

void Entity::PerformMove(const DX::XMFLOAT2& direction)
{
    if (m_move != nullptr)
    {
        m_position = m_move->Move(m_position, direction);
    }
}

