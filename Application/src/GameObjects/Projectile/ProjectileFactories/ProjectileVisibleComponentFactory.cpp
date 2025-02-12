#include "ProjectileVisibleComponentFactory.hpp"
#include <stdexcept>

std::shared_ptr<IProjectileVisible> CreateVisibleComponent(ProjectileType type) 
{
    switch (type) {
    case ProjectileType::Base:
        return std::make_shared<BaseVisible>();
        break;
    default:
        throw std::invalid_argument("Unknown ProjectileType in CreateVisibleComponent");
        break;
    }
}
