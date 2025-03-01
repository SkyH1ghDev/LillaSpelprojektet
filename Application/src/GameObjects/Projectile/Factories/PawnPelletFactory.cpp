#include "PawnPelletFactory.hpp"

#include "PawnPelletHit.hpp"
#include "PawnPelletMove.hpp"
#include "PawnPelletSetCollider.hpp"
#include "PawnPelletVisible.hpp"

std::shared_ptr<Projectile> PawnPelletFactory::CreateObject()
{
    std::shared_ptr<Projectile> pawnPellet = std::make_shared<Projectile>
    (
        Projectile 
        (
            CreateMoveComponent(),
            CreateHitComponent(),
            CreateSetColliderComponent(),
            CreateVisibleComponent(),
            ProjectileType::PawnPellet,
            "PawnPellet"
        )
    );

    return pawnPellet;

}

std::shared_ptr<IProjectileMove> PawnPelletFactory::CreateMoveComponent()
{
    return std::make_shared<PawnPelletMove>();
}

std::shared_ptr<IProjectileHit> PawnPelletFactory::CreateHitComponent()
{
    return std::make_shared<PawnPelletHit>();
}

std::shared_ptr<IProjectileSetCollider> PawnPelletFactory::CreateSetColliderComponent()
{
    return std::make_shared<PawnPelletSetCollider>();
}

std::shared_ptr<IProjectileVisible> PawnPelletFactory::CreateVisibleComponent()
{
    return std::make_shared<PawnPelletVisible>();
}
