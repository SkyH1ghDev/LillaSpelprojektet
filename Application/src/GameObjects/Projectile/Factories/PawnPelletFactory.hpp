#pragma once
#include "IProjectileFactory.hpp"

class PawnPelletFactory : public IProjectileFactory
{
public:
    PawnPelletFactory() = default;
    ~PawnPelletFactory() override = default;
    PawnPelletFactory(const PawnPelletFactory& other) = default;
    PawnPelletFactory& operator=(const PawnPelletFactory& other) = default;
    PawnPelletFactory(PawnPelletFactory&& other) noexcept = default;
    PawnPelletFactory& operator=(PawnPelletFactory&& other) noexcept = default;

    std::shared_ptr<Projectile> CreateObject() override;

private:
    std::shared_ptr<IProjectileMove> CreateMoveComponent() override;
    std::shared_ptr<IProjectileHit> CreateHitComponent() override;
    std::shared_ptr<IProjectileSetCollider> CreateSetColliderComponent() override;
    std::shared_ptr<IProjectileVisible> CreateVisibleComponent() override;
    
};
