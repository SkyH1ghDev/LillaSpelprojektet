#include "ProjectileSetColliderComponentFactory.hpp"

std::shared_ptr<IProjectileSetCollider> CreateSetColliderComponent(ProjectileType type)
{
    switch (type) {
    case ProjectileType::Base:
        return std::make_shared<BaseSetCollider>();
        break;
    case ProjectileType::BishopBall:
        return std::make_shared<BishopBallSetCollider>();
        break;
    case ProjectileType::PawnPellet:
        return std::make_shared<PawnPelletSetCollider>();
        break;
    case ProjectileType::ScatterPellet:
        return std::make_shared<ScatterPelletSetCollider>();
        break;
    case ProjectileType::SniperBullet:
        return std::make_shared<SniperBulletSetCollider>();
        break;
    default:
        throw std::invalid_argument("Unknown ProjectileType in CreateSetColliderComponent");
        break;
    }
}
