#include "Entity.hpp"
#include <iostream>

// Factory function to create appropriate components
std::unique_ptr<IAttack> CreateAttackComponent(EntityType type) {
    switch (type) {
    case EntityType::Player:
        return std::make_unique<PlayerAttack>();
    case EntityType::Enemy:
        return std::make_unique<EnemyAttack>();
    }
    return nullptr;
}

std::unique_ptr<IMove> CreateMoveComponent(EntityType type) {
    switch (type) {
    case EntityType::Player:
        return std::make_unique<PlayerMove>();
    case EntityType::Enemy:
        return std::make_unique<EnemyMove>();
    }
    return nullptr;
}

std::unique_ptr<ITakeDamage> CreateTakeDamageComponent(EntityType type) {
    switch (type) {
    case EntityType::Player:
        return std::make_unique<PlayerTakeDamage>();
    case EntityType::Enemy:
        return std::make_unique<EnemyTakeDamage>();
    }
    return nullptr;
}

std::unique_ptr<IUseCard> CreateUseCardComponent(EntityType type) {
    switch (type) {
    case EntityType::Player:
        return std::make_unique<PlayerUseCard>();
    case EntityType::Enemy:
        return std::make_unique<EnemyUseCard>();
    }
    return nullptr;
}

std::unique_ptr<IVisible> CreateVisibleComponent(EntityType type) {
    switch (type) {
    case EntityType::Player:
        return std::make_unique<PlayerVisible>();
    case EntityType::Enemy:
        return std::make_unique<EnemyVisible>();
    }
    return nullptr;
}

// Constructor: Decides behavior based on entity type
Entity::Entity(EntityType entityType)
    : m_type(entityType),
    m_move(CreateMoveComponent(entityType)),
    m_attack(CreateAttackComponent(entityType)),
    m_takeDamage(CreateTakeDamageComponent(entityType)),
    m_useCard(CreateUseCardComponent(entityType)),
    m_visible(CreateVisibleComponent(entityType))
{
    std::cerr << "Entity created of type: " << (m_type == EntityType::Player ? "Player" : "Enemy") << std::endl;
}
