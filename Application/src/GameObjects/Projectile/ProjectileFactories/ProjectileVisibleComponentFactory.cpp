#include "ProjectileVisibleComponentFactory.hpp"
#include <stdexcept>

std::shared_ptr<IProjectileVisible> CreateVisibleComponent(ProjectileType type) 
{
    switch (type) {
    case ProjectileType::Base:
        return std::make_shared<BaseVisible>();
        break;
    case ProjectileType::BishopBall:
        return std::make_shared<BishopBallVisible>();
        break;
    case ProjectileType::PawnPellet:
        return std::make_shared<PawnPelletVisible>();
        break;
    case ProjectileType::ScatterPellet:
        return std::make_shared<ScatterPelletVisible>();
        break;
    case ProjectileType::SniperBullet:
        return std::make_shared<SniperBulletVisible>();
        break;
    case ProjectileType::DisruptorWave:
        return std::make_shared<DisruptorWaveVisible>();
        break;
    default:
        throw std::invalid_argument("Unknown ProjectileType in CreateVisibleComponent");
        break;
    }
}
