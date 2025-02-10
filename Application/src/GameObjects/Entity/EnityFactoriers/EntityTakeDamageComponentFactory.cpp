#include "EntityTakeDamageComponentFactory.hpp"
#include <stdexcept>

std::shared_ptr<IEntityTakeDamage> CreateTakeDamageComponent(EntityType type) {
    switch (type) {
    case EntityType::Player:
        return std::make_shared<PlayerTakeDamage>();
        break;
    case EntityType::Enemy:
        return std::make_shared<EnemyTakeDamage>();
        break;
    default:
        throw std::invalid_argument("Unknown EntityType in CreateTakeDamageComponent");
        break;
    }
}