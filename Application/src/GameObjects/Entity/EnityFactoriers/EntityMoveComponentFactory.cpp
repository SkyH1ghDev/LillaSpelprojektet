#include "EntityMoveComponentFactory.hpp"
#include <stdexcept>

std::shared_ptr<IEntityMove> CreateMoveComponent(EntityType type) {
    switch (type) {
    case EntityType::Player:
        return std::make_shared<PlayerMove>();
        break;
    case EntityType::Enemy:
        return std::make_shared<EnemyMove>();
        break;
    default:
        throw std::invalid_argument("Unknown EntityType in CreateMoveComponent");
        break;
    }
}