#include "BishopBallFactory.hpp"

#include "BishopBallHit.hpp"
#include "BishopBallMove.hpp"
#include "BishopBallSetCollider.hpp"
#include "BishopBallVisible.hpp"

std::shared_ptr<Projectile> BishopBallFactory::CreateObject()
{
    std::shared_ptr<Projectile> bishopBall = std::make_shared<Projectile>
    (
        Projectile 
        (
            CreateMoveComponent(),
            CreateHitComponent(),
            CreateSetColliderComponent(),
            CreateVisibleComponent(),
            ProjectileType::BishopBall,
            "BishopBall"
        )
    );

    return bishopBall;

}

std::shared_ptr<IProjectileMove> BishopBallFactory::CreateMoveComponent()
{
    return std::make_shared<BishopBallMove>();
}

std::shared_ptr<IProjectileHit> BishopBallFactory::CreateHitComponent()
{
    return std::make_shared<BishopBallHit>();
}

std::shared_ptr<IProjectileSetCollider> BishopBallFactory::CreateSetColliderComponent()
{
    return std::make_shared<BishopBallSetCollider>();
}

std::shared_ptr<IProjectileVisible> BishopBallFactory::CreateVisibleComponent()
{
    return std::make_shared<BishopBallVisible>();
}
