#include "ProjectileMoveComponentFactory.hpp"

std::shared_ptr<IProjectileMove> CreateMoveComponent(ProjectileType type)
{
    switch (type) {
    case ProjectileType::Base:
        return std::make_shared<BaseMove>();
        break;
    default:
        throw std::invalid_argument("Unknown ProjectileType in CreateMoveComponent");
        break;
    }
}
