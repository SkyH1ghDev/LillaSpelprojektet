#include "ProjectileHitComponentFactory.hpp"

std::shared_ptr<IProjectileHit> CreateHitComponent(ProjectileType type)
{
    switch (type) {
    case ProjectileType::Base:
        return std::make_shared<BaseHit>();
        break;
    case ProjectileType::BishopBall:
        return std::make_shared<BishopBallHit>();
        break;
    case ProjectileType::PawnPellet:
        return std::make_shared<PawnPelletHit>();
        break;
    case ProjectileType::ScatterPellet:
        return std::make_shared<ScatterPelletHit>();
        break;
    case ProjectileType::SniperBullet:
        return std::make_shared<SniperBulletHit>();
        break;
    case ProjectileType::DisruptorWave:
        return std::make_shared<DisruptorWaveHit>();
        break;
    default:
        throw std::invalid_argument("Unknown ProjectileType in CreateHitComponent");
        break;
    }
}
