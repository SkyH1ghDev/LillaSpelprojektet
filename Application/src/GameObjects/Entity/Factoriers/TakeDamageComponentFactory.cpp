#include "TakeDamageComponentFactory.hpp"
#include <stdexcept>

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