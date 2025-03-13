#include "IceCubeFactory.hpp"

#include "IceCubeHit.hpp"
#include "IceCubeMove.hpp"
#include "IceCubeSetCollider.hpp"
#include "IceCubeVisible.hpp"

std::shared_ptr<Projectile> IceCubeFactory::CreateObject()
{
    std::shared_ptr<Projectile> iceCube = std::make_shared<Projectile>
    (
        Projectile 
        (
            CreateMoveComponent(),
            CreateHitComponent(),
            CreateSetColliderComponent(),
            CreateVisibleComponent(),
            ProjectileType::IceCube,
            "IceCube"
        )
    );

    return iceCube;

}

std::shared_ptr<IProjectileMove> IceCubeFactory::CreateMoveComponent()
{
    return std::make_shared<IceCubeMove>();
}

std::shared_ptr<IProjectileHit> IceCubeFactory::CreateHitComponent()
{
    return std::make_shared<IceCubeHit>();
}

std::shared_ptr<IProjectileSetCollider> IceCubeFactory::CreateSetColliderComponent()
{
    return std::make_shared<IceCubeSetCollider>();
}

std::shared_ptr<IProjectileVisible> IceCubeFactory::CreateVisibleComponent()
{
    return std::make_shared<IceCubeVisible>();
}
