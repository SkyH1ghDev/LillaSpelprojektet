#include "LongshotFactory.hpp"

#include "LongshotHit.hpp"
#include "LongshotMove.hpp"
#include "LongshotSetCollider.hpp"
#include "LongshotVisible.hpp"

std::shared_ptr<Projectile> LongshotFactory::CreateObject()
{
    std::shared_ptr<Projectile> Longshot = std::make_shared<Projectile>
    (
        Projectile 
        (
            CreateMoveComponent(),
            CreateHitComponent(),
            CreateSetColliderComponent(),
            CreateVisibleComponent(),
            ProjectileType::Longshot,
            "Longshot"
        )
    );

    return Longshot;

}

std::shared_ptr<IProjectileMove> LongshotFactory::CreateMoveComponent()
{
    return std::make_shared<LongshotMove>();
}

std::shared_ptr<IProjectileHit> LongshotFactory::CreateHitComponent()
{
    return std::make_shared<LongshotHit>();
}

std::shared_ptr<IProjectileSetCollider> LongshotFactory::CreateSetColliderComponent()
{
    return std::make_shared<LongshotSetCollider>();
}

std::shared_ptr<IProjectileVisible> LongshotFactory::CreateVisibleComponent()
{
    return std::make_shared<LongshotVisible>();
}
