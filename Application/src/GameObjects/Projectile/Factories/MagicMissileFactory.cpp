#include "MagicMissileFactory.hpp"

#include "MagicMissileHit.hpp"
#include "MagicMissileMove.hpp"
#include "MagicMissileSetCollider.hpp"
#include "MagicMissileVisible.hpp"

std::shared_ptr<Projectile> MagicMissileFactory::CreateObject()
{
    std::shared_ptr<Projectile> magicMissile = std::make_shared<Projectile>
    (
        Projectile 
        (
            CreateMoveComponent(),
            CreateHitComponent(),
            CreateSetColliderComponent(),
            CreateVisibleComponent(),
            ProjectileType::MagicMissile,
            "MagicMissile"
        )
    );

    return magicMissile;

}

std::shared_ptr<IProjectileMove> MagicMissileFactory::CreateMoveComponent()
{
    return std::make_shared<MagicMissileMove>();
}

std::shared_ptr<IProjectileHit> MagicMissileFactory::CreateHitComponent()
{
    return std::make_shared<MagicMissileHit>();
}

std::shared_ptr<IProjectileSetCollider> MagicMissileFactory::CreateSetColliderComponent()
{
    return std::make_shared<MagicMissileSetCollider>();
}

std::shared_ptr<IProjectileVisible> MagicMissileFactory::CreateVisibleComponent()
{
    return std::make_shared<MagicMissileVisible>();
}
