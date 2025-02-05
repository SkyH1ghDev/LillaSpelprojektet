#include "EntityVisibleComponentFactory.hpp"
#include <stdexcept>

std::shared_ptr<IEntityVisible> CreateVisibleComponent(EntityType type) {
    switch (type) {
    case EntityType::Player:
        return std::make_shared<PlayerVisible>();
    case EntityType::Enemy:
        return std::make_shared<EnemyVisible>();
    default:
        throw std::invalid_argument("Unknown EntityType in CreateVisibleComponent");
    }
}
