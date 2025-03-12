#include "BladeFactory.hpp"

#include "BladeHit.hpp"
#include "BladeMove.hpp"
#include "BladeSetCollider.hpp"
#include "BladeVisible.hpp"

std::shared_ptr<Projectile> BladeFactory::CreateObject()
{
    std::shared_ptr<Projectile> sniperBullet = std::make_shared<Projectile>
    (
        Projectile 
        (
            CreateMoveComponent(),
            CreateHitComponent(),
            CreateSetColliderComponent(),
            CreateVisibleComponent(),
            ProjectileType::Blade,
            "Blade"
        )
    );

    return sniperBullet;

}

std::shared_ptr<IProjectileMove> BladeFactory::CreateMoveComponent()
{
    return std::make_shared<BladeMove>();
}

std::shared_ptr<IProjectileHit> BladeFactory::CreateHitComponent()
{
    return std::make_shared<BladeHit>();
}

std::shared_ptr<IProjectileSetCollider> BladeFactory::CreateSetColliderComponent()
{
    return std::make_shared<BladeSetCollider>();
}

std::shared_ptr<IProjectileVisible> BladeFactory::CreateVisibleComponent()
{
    return std::make_shared<BladeVisible>();
}
