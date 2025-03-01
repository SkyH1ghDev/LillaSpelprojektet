#include "ScatterPelletFactory.hpp"

#include "ScatterPellethit.hpp"
#include "ScatterPelletMove.hpp"
#include "ScatterPelletSetCollider.hpp"
#include "ScatterPelletVisible.hpp"

std::shared_ptr<Projectile> ScatterPelletFactory::CreateObject()
{
    std::shared_ptr<Projectile> scatterPellet = std::make_shared<Projectile>
    (
        Projectile 
        (
            CreateMoveComponent(),
            CreateHitComponent(),
            CreateSetColliderComponent(),
            CreateVisibleComponent(),
            ProjectileType::ScatterPellet,
            "ScatterPellet"
        )
    );

    return scatterPellet;

}

std::shared_ptr<IProjectileMove> ScatterPelletFactory::CreateMoveComponent()
{
    return std::make_shared<ScatterPelletMove>();
}

std::shared_ptr<IProjectileHit> ScatterPelletFactory::CreateHitComponent()
{
    return std::make_shared<ScatterPelletHit>();
}

std::shared_ptr<IProjectileSetCollider> ScatterPelletFactory::CreateSetColliderComponent()
{
    return std::make_shared<ScatterPelletSetCollider>();
}

std::shared_ptr<IProjectileVisible> ScatterPelletFactory::CreateVisibleComponent()
{
    return std::make_shared<ScatterPelletVisible>();
}
