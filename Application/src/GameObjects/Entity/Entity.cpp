#include "Entity.hpp"
#include "PlayerAttack.hpp"
#include "PlayerMove.hpp"
#include "PlayerTakeDamage.hpp"
#include "PlayerUseCard.hpp"
#include "PlayerVisible.hpp"
#include "EnemyAttack.hpp"
#include "EnemyMove.hpp"
#include "EnemyTakeDamage.hpp"
#include "EnemyUseCard.hpp"
#include "EnemyVisible.hpp"
#include <iostream>

// Factory function to create appropriate components
std::unique_ptr<IAttack> createAttackComponent(const std::string& type) {
    if (type == "player") {
        return std::make_unique<PlayerAttack>();
    }
    else if (type == "enemy") {
        return std::make_unique<EnemyAttack>();
    }
    return nullptr;
}

std::unique_ptr<IMove> createMoveComponent(const std::string& type) {
    if (type == "player") {
        return std::make_unique<PlayerMove>();
    }
    else if (type == "enemy") {
        return std::make_unique<EnemyMove>();
    }
    return nullptr;
}

std::unique_ptr<ITakeDamage> createTakeDamageComponent(const std::string& type) {
    if (type == "player") {
        return std::make_unique<PlayerTakeDamage>();
    }
    else if (type == "enemy") {
        return std::make_unique<EnemyTakeDamage>();
    }
    return nullptr;
}

std::unique_ptr<IUseCard> createUseCardComponent(const std::string& type) {
    if (type == "player") {
        return std::make_unique<PlayerUseCard>();
    }
    else if (type == "enemy") {
        return std::make_unique<EnemyUseCard>();
    }
    return nullptr;
}

std::unique_ptr<IVisible> createVisibleComponent(const std::string& type) {
    if (type == "player") {
        return std::make_unique<PlayerVisible>();
    }
    else if (type == "enemy") {
        return std::make_unique<EnemyVisible>();
    }
    return nullptr;
}

// Constructor: Decides behavior based on entity type
Entity::Entity(const std::string& entityType)
    : type(entityType),
    move(createMoveComponent(entityType)),
    attack(createAttackComponent(entityType)),
    takeDamage(createTakeDamageComponent(entityType)),
    useCard(createUseCardComponent(entityType)),
    visible(createVisibleComponent(entityType))
{
    std::cerr << "Entity created of type: " << entityType << std::endl;
}