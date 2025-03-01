#include "EntityVisibleComponentFactory.hpp"
#include <stdexcept>

std::shared_ptr<IEntityVisible> CreateVisibleComponent(EntityType type) {
    switch (type) {
    case EntityType::Player:
        return std::make_shared<PlayerVisible>();
        break;
    case EntityType::Bishop:
        return std::make_shared<BishopVisible>();
        break;
    default:
        throw std::invalid_argument("Unknown EntityType in CreateVisibleComponent");
        break;
    }
}
