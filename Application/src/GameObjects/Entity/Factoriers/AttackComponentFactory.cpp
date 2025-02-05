#include "AttackComponentFactory.hpp"
#include <stdexcept>

std::shared_ptr<IAttack> CreateAttackComponent(EntityType type) {
    switch (type) {
    case EntityType::Player:
        return std::make_shared<PlayerAttack>();
    case EntityType::Enemy:
        return std::make_shared<EnemyAttack>();
    default:
        throw std::invalid_argument("Unknown EntityType in CreateAttackComponent");
    }
}