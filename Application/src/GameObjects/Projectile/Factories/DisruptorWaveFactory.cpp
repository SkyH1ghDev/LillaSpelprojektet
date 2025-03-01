#include "DisruptorWaveFactory.hpp"

#include "DisruptorWaveHit.hpp"
#include "DisruptorWaveMove.hpp"
#include "DisruptorWaveSetCollider.hpp"
#include "DisruptorWaveVisible.hpp"

std::shared_ptr<Projectile> DisruptorWaveFactory::CreateObject()
{
    std::shared_ptr<Projectile> disruptorWave = std::make_shared<Projectile>
    (
        Projectile 
        (
            CreateMoveComponent(),
            CreateHitComponent(),
            CreateSetColliderComponent(),
            CreateVisibleComponent(),
            ProjectileType::DisruptorWave,
            "DisruptorWave"
        )
    );

    return disruptorWave;

}

std::shared_ptr<IProjectileMove> DisruptorWaveFactory::CreateMoveComponent()
{
    return std::make_shared<DisruptorWaveMove>();
}

std::shared_ptr<IProjectileHit> DisruptorWaveFactory::CreateHitComponent()
{
    return std::make_shared<DisruptorWaveHit>();
}

std::shared_ptr<IProjectileSetCollider> DisruptorWaveFactory::CreateSetColliderComponent()
{
    return std::make_shared<DisruptorWaveSetCollider>();
}

std::shared_ptr<IProjectileVisible> DisruptorWaveFactory::CreateVisibleComponent()
{
    return std::make_shared<DisruptorWaveVisible>();
}
