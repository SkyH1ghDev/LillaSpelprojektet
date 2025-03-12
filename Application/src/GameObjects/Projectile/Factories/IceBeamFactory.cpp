#include "IceBeamFactory.hpp"

#include "IceBeamHit.hpp"
#include "IceBeamMove.hpp"
#include "IceBeamSetCollider.hpp"
#include "IceBeamVisible.hpp"

std::shared_ptr<Projectile> IceBeamFactory::CreateObject()
{
    std::shared_ptr<Projectile> iceBeam = std::make_shared<Projectile>
    (
        Projectile 
        (
            CreateMoveComponent(),
            CreateHitComponent(),
            CreateSetColliderComponent(),
            CreateVisibleComponent(),
            ProjectileType::IceBeam,
            "IceBeam"
        )
    );

    return iceBeam;

}

std::shared_ptr<IProjectileMove> IceBeamFactory::CreateMoveComponent()
{
    return std::make_shared<IceBeamMove>();
}

std::shared_ptr<IProjectileHit> IceBeamFactory::CreateHitComponent()
{
    return std::make_shared<IceBeamHit>();
}

std::shared_ptr<IProjectileSetCollider> IceBeamFactory::CreateSetColliderComponent()
{
    return std::make_shared<IceBeamSetCollider>();
}

std::shared_ptr<IProjectileVisible> IceBeamFactory::CreateVisibleComponent()
{
    return std::make_shared<IceBeamVisible>();
}
