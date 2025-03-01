#pragma once
#include "IProjectileFactory.hpp"

class ScatterPelletFactory : public IProjectileFactory
{
public:
    ScatterPelletFactory() = default;
    ~ScatterPelletFactory() override = default;
    ScatterPelletFactory(const ScatterPelletFactory& other) = default;
    ScatterPelletFactory& operator=(const ScatterPelletFactory& other) = default;
    ScatterPelletFactory(ScatterPelletFactory&& other) noexcept = default;
    ScatterPelletFactory& operator=(ScatterPelletFactory&& other) noexcept = default;

    std::shared_ptr<Projectile> CreateObject() override;

private:
    std::shared_ptr<IProjectileMove> CreateMoveComponent() override;
    std::shared_ptr<IProjectileHit> CreateHitComponent() override;
    std::shared_ptr<IProjectileSetCollider> CreateSetColliderComponent() override;
    std::shared_ptr<IProjectileVisible> CreateVisibleComponent() override;
    
};
