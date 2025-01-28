#include "Entity.hpp"
#include <iostream>

// Factory function to create appropriate components
std::unique_ptr<IAttack> createAttackComponent(EntityType type) {
    switch (type) {
    case EntityType::Player:
        return std::make_unique<PlayerAttack>();
    case EntityType::Enemy:
        return std::make_unique<EnemyAttack>();
    }
    return nullptr;
}

std::unique_ptr<IMove> createMoveComponent(EntityType type) {
    switch (type) {
    case EntityType::Player:
        return std::make_unique<PlayerMove>();
    case EntityType::Enemy:
        return std::make_unique<EnemyMove>();
    }
    return nullptr;
}

std::unique_ptr<ITakeDamage> createTakeDamageComponent(EntityType type) {
    switch (type) {
    case EntityType::Player:
        return std::make_unique<PlayerTakeDamage>();
    case EntityType::Enemy:
        return std::make_unique<EnemyTakeDamage>();
    }
    return nullptr;
}

std::unique_ptr<IUseCard> createUseCardComponent(EntityType type) {
    switch (type) {
    case EntityType::Player:
        return std::make_unique<PlayerUseCard>();
    case EntityType::Enemy:
        return std::make_unique<EnemyUseCard>();
    }
    return nullptr;
}

std::unique_ptr<IVisible> createVisibleComponent(EntityType type) {
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
    : type(entityType),
    move(createMoveComponent(entityType)),
    attack(createAttackComponent(entityType)),
    takeDamage(createTakeDamageComponent(entityType)),
    useCard(createUseCardComponent(entityType)),
    visible(createVisibleComponent(entityType))
{
    std::cerr << "Entity created of type: " << (type == EntityType::Player ? "Player" : "Enemy") << std::endl;
}
