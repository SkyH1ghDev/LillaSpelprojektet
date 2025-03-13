#pragma once
#include "IProjectileFactory.hpp"

class IceCubeFactory : public IProjectileFactory
{
public:
    IceCubeFactory() = default;
    ~IceCubeFactory() override = default;
    IceCubeFactory(const IceCubeFactory& other) = default;
    IceCubeFactory& operator=(const IceCubeFactory& other) = default;
    IceCubeFactory(IceCubeFactory&& other) noexcept = default;
    IceCubeFactory& operator=(IceCubeFactory&& other) noexcept = default;

    std::shared_ptr<Projectile> CreateObject() override;

private:
    std::shared_ptr<IProjectileMove> CreateMoveComponent() override;
    std::shared_ptr<IProjectileHit> CreateHitComponent() override;
    std::shared_ptr<IProjectileSetCollider> CreateSetColliderComponent() override;
    std::shared_ptr<IProjectileVisible> CreateVisibleComponent() override;
    
};
