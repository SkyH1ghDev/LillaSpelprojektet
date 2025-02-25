#include "ProjectileMoveComponentFactory.hpp"

std::shared_ptr<IProjectileMove> CreateMoveComponent(ProjectileType type)
{
    switch (type) {
    case ProjectileType::Base:
        return std::make_shared<BaseMove>();
        break;
    case ProjectileType::BishopBall:
        return std::make_shared<BishopBallMove>();
        break;
    case ProjectileType::PawnPellet:
        return std::make_shared<PawnPelletMove>();
        break;
    case ProjectileType::ScatterPellet:
        return std::make_shared<ScatterPelletMove>();
        break;
    case ProjectileType::SniperBullet:
        return std::make_shared<SniperBulletMove>();
        break;
    default:
        throw std::invalid_argument("Unknown ProjectileType in CreateMoveComponent");
        break;
    }
}
