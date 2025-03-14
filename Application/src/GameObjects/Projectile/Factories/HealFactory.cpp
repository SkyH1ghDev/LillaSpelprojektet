#include "HealFactory.hpp"

#include "HealHit.hpp"
#include "HealMove.hpp"
#include "HealSetCollider.hpp"
#include "HealVisible.hpp"

std::shared_ptr<Projectile> HealFactory::CreateObject()
{
    std::shared_ptr<Projectile> Heal = std::make_shared<Projectile>
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

    return Heal;

}

std::shared_ptr<IProjectileMove> HealFactory::CreateMoveComponent()
{
    return std::make_shared<HealMove>();
}

std::shared_ptr<IProjectileHit> HealFactory::CreateHitComponent()
{
    return std::make_shared<HealHit>();
}

std::shared_ptr<IProjectileSetCollider> HealFactory::CreateSetColliderComponent()
{
    return std::make_shared<HealSetCollider>();
}

std::shared_ptr<IProjectileVisible> HealFactory::CreateVisibleComponent()
{
    return std::make_shared<HealVisible>();
}
