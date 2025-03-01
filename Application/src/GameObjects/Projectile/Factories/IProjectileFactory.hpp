#pragma once
#include "Projectile.hpp"

class IProjectileFactory
{
public:
    IProjectileFactory() = default;
    virtual ~IProjectileFactory() = default;
    IProjectileFactory(const IProjectileFactory& other) = default;
    IProjectileFactory& operator=(const IProjectileFactory& other) = default;
    IProjectileFactory(IProjectileFactory&& other) noexcept = default;
    IProjectileFactory& operator=(IProjectileFactory&& other) noexcept = default;

    virtual std::shared_ptr<Projectile> CreateObject() = 0;

protected:
    virtual std::shared_ptr<IProjectileMove> CreateMoveComponent() = 0;
    virtual std::shared_ptr<IProjectileHit> CreateHitComponent() = 0;
    virtual std::shared_ptr<IProjectileVisible> CreateVisibleComponent() = 0;
    virtual std::shared_ptr<IProjectileSetCollider> CreateSetColliderComponent() = 0;
    
};
