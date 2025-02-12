#include "ProjectileHitComponentFactory.hpp"

std::shared_ptr<IProjectileHit> CreateHitComponent(ProjectileType type)
{
    switch (type) {
    case ProjectileType::Base:
        return std::make_shared<BaseHit>();
        break;
    default:
        throw std::invalid_argument("Unknown ProjectileType in CreateHitComponent");
        break;
    }
}
