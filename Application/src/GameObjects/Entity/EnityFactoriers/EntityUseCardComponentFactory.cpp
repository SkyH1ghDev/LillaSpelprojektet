#include "EntityUseCardComponentFactory.hpp"
#include <stdexcept>

std::shared_ptr<IEntityUseCard> CreateUseCardComponent(EntityType type) {
    switch (type) {
    case EntityType::Player:
        return std::make_shared<PlayerUseCard>();
    case EntityType::Enemy:
        return std::make_shared<EnemyUseCard>();
    default:
        throw std::invalid_argument("Unknown EntityType in CreateUseCardComponent");
    }
}