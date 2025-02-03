#include "Entity.hpp"
#include <iostream>

#include <memory>

// Factory function to create appropriate components
std::unique_ptr<IAttack> CreateAttackComponent(EntityType type) {
    switch (type) {
    case EntityType::Player:
        return std::make_unique<PlayerAttack>();
    case EntityType::Enemy:
        return std::make_unique<EnemyAttack>();
    default:
        throw std::invalid_argument("Unknown EntityType in CreateAttackComponent");
    }
}

std::unique_ptr<IMove> CreateMoveComponent(EntityType type) {
    switch (type) {
    case EntityType::Player:
        return std::make_unique<PlayerMove>();
    case EntityType::Enemy:
        return std::make_unique<EnemyMove>();
    default:
        throw std::invalid_argument("Unknown EntityType in CreateMoveComponent");
    }
}

std::unique_ptr<ITakeDamage> CreateTakeDamageComponent(EntityType type) {
    switch (type) {
    case EntityType::Player:
        return std::make_unique<PlayerTakeDamage>();
    case EntityType::Enemy:
        return std::make_unique<EnemyTakeDamage>();
    default:
        throw std::invalid_argument("Unknown EntityType in CreateTakeDamageComponent");
    }
}

std::unique_ptr<IUseCard> CreateUseCardComponent(EntityType type) {
    switch (type) {
    case EntityType::Player:
        return std::make_unique<PlayerUseCard>();
    case EntityType::Enemy:
        return std::make_unique<EnemyUseCard>();
    default:
        throw std::invalid_argument("Unknown EntityType in CreateUseCardComponent");
    }

}

std::unique_ptr<IVisible> CreateVisibleComponent(EntityType type) {
    switch (type) {
    case EntityType::Player:
        return std::make_unique<PlayerVisible>();
    case EntityType::Enemy:
        return std::make_unique<EnemyVisible>();
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

}

void Entity::Update()
{

}



