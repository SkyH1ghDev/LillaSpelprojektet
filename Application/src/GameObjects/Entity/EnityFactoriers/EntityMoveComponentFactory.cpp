#include "EntityMoveComponentFactory.hpp"
#include <stdexcept>

std::shared_ptr<IEntityMove> CreateMoveComponent(EntityType type) {
    switch (type) {
    case EntityType::Player:
        return std::make_shared<PlayerMove>();
        break;
    case EntityType::Bishop:
        return std::make_shared<BishopMove>();
        break;
    default:
        throw std::invalid_argument("Unknown EntityType in CreateMoveComponent");
        break;
    }
}