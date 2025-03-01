#include "EntityTakeDamageComponentFactory.hpp"
#include <stdexcept>

std::shared_ptr<IEntityTakeDamage> CreateTakeDamageComponent(EntityType type) {
    switch (type) {
    case EntityType::Player:
        return std::make_shared<PlayerTakeDamage>();
        break;
    case EntityType::Bishop:
        return std::make_shared<BishopTakeDamage>();
        break;
    case EntityType::Rook:
        return std::make_shared<RookTakeDamage>();
        break;
    default:
        throw std::invalid_argument("Unknown EntityType in CreateTakeDamageComponent");
        break;
    }
}