#include "BaseProjectileFactory.hpp"

#include "BaseHit.hpp"
#include "BaseMove.hpp"
#include "BaseSetCollider.hpp"
#include "BaseVisible.hpp"

std::shared_ptr<Projectile> BaseProjectileFactory::CreateObject()
{
    std::shared_ptr<Projectile> base = std::make_shared<Projectile>
    (
        Projectile 
        (
            CreateMoveComponent(),
            CreateHitComponent(),
            CreateSetColliderComponent(),
            CreateVisibleComponent(),
            ProjectileType::Base,
            "BaseProjectile"
        )
    );

    return base;

}

std::shared_ptr<IProjectileMove> BaseProjectileFactory::CreateMoveComponent()
{
    return std::make_shared<BaseMove>();
}

std::shared_ptr<IProjectileHit> BaseProjectileFactory::CreateHitComponent()
{
    return std::make_shared<BaseHit>();
}

std::shared_ptr<IProjectileSetCollider> BaseProjectileFactory::CreateSetColliderComponent()
{
    return std::make_shared<BaseSetCollider>();
}

std::shared_ptr<IProjectileVisible> BaseProjectileFactory::CreateVisibleComponent()
{
    return std::make_shared<BaseVisible>();
}