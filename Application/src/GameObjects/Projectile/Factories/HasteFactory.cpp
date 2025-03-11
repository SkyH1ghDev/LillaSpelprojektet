#include "HasteFactory.hpp"

#include "HasteHit.hpp"
#include "HasteMove.hpp"
#include "HasteSetCollider.hpp"
#include "HasteVisible.hpp"

std::shared_ptr<Projectile> HasteFactory::CreateObject()
{
    std::shared_ptr<Projectile> Haste = std::make_shared<Projectile>
    (
        Projectile 
        (
            CreateMoveComponent(),
            CreateHitComponent(),
            CreateSetColliderComponent(),
            CreateVisibleComponent(),
            ProjectileType::Haste,
            "Haste"
        )
    );

    return Haste;

}

std::shared_ptr<IProjectileMove> HasteFactory::CreateMoveComponent()
{
    return std::make_shared<HasteMove>();
}

std::shared_ptr<IProjectileHit> HasteFactory::CreateHitComponent()
{
    return std::make_shared<HasteHit>();
}

std::shared_ptr<IProjectileSetCollider> HasteFactory::CreateSetColliderComponent()
{
    return std::make_shared<HasteSetCollider>();
}

std::shared_ptr<IProjectileVisible> HasteFactory::CreateVisibleComponent()
{
    return std::make_shared<HasteVisible>();
}
