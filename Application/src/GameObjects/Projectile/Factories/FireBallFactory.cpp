#include "FireBallFactory.hpp"

#include "FireBallHit.hpp"
#include "FireBallMove.hpp"
#include "FireBallSetCollider.hpp"
#include "FireBallVisible.hpp"

std::shared_ptr<Projectile> FireBallFactory::CreateObject()
{
    std::shared_ptr<Projectile> fireBall = std::make_shared<Projectile>
        (
            Projectile
            (
                CreateMoveComponent(),
                CreateHitComponent(),
                CreateSetColliderComponent(),
                CreateVisibleComponent(),
                ProjectileType::FireBall,
                "FireBall"
            )
        );

    return fireBall;
}

std::shared_ptr<IProjectileMove> FireBallFactory::CreateMoveComponent()
{
    return std::make_shared<FireBallMove>();
}

std::shared_ptr<IProjectileHit> FireBallFactory::CreateHitComponent()
{
    return std::make_shared<FireBallHit>();
}

std::shared_ptr<IProjectileSetCollider> FireBallFactory::CreateSetColliderComponent()
{
    return std::make_shared<FireBallSetCollider>();
}

std::shared_ptr<IProjectileVisible> FireBallFactory::CreateVisibleComponent()
{
    return std::make_shared<FireBallVisible>();
}
