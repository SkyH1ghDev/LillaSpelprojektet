#include "EntityMoveComponentFactory.hpp"
#include <stdexcept>

std::shared_ptr<IEntityMove> CreateMoveComponent(EntityType type) {
    switch (type) {
    case EntityType::Player:
        return std::make_shared<PlayerMove>();
    case EntityType::Enemy:
        return std::make_shared<EnemyMove>();
    default:
        throw std::invalid_argument("Unknown EntityType in CreateMoveComponent");
    }
}