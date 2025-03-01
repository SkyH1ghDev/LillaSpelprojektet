#include "SniperBulletFactory.hpp"

#include "SniperBulletHit.hpp"
#include "SniperBulletMove.hpp"
#include "SniperBulletSetCollider.hpp"
#include "SniperBulletVisible.hpp"

std::shared_ptr<Projectile> SniperBulletFactory::CreateObject()
{
    std::shared_ptr<Projectile> sniperBullet = std::make_shared<Projectile>
    (
        Projectile 
        (
            CreateMoveComponent(),
            CreateHitComponent(),
            CreateSetColliderComponent(),
            CreateVisibleComponent(),
            ProjectileType::SniperBullet,
            "SniperBullet"
        )
    );

    return sniperBullet;

}

std::shared_ptr<IProjectileMove> SniperBulletFactory::CreateMoveComponent()
{
    return std::make_shared<SniperBulletMove>();
}

std::shared_ptr<IProjectileHit> SniperBulletFactory::CreateHitComponent()
{
    return std::make_shared<SniperBulletHit>();
}

std::shared_ptr<IProjectileSetCollider> SniperBulletFactory::CreateSetColliderComponent()
{
    return std::make_shared<SniperBulletSetCollider>();
}

std::shared_ptr<IProjectileVisible> SniperBulletFactory::CreateVisibleComponent()
{
    return std::make_shared<SniperBulletVisible>();
}
