#include "EntityAttackComponentFactory.hpp"
#include <stdexcept>

std::shared_ptr<IEntityAttack> CreateAttackComponent(EntityType type) {
    switch (type) {
    case EntityType::Player:
        return std::make_shared<PlayerAttack>();
        break;
    case EntityType::Bishop:
        return std::make_shared<BishopAttack>();
        break;
    case EntityType::Rook:
        return std::make_shared<RookAttack>();
        break;
    default:
        throw std::invalid_argument("Unknown EntityType in CreateAttackComponent");
        break;
    }
}