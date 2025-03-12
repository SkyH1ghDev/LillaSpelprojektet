#pragma once
#include "IProjectileFactory.hpp"

class IceBeamFactory : public IProjectileFactory
{
public:
    IceBeamFactory() = default;
    ~IceBeamFactory() override = default;
    IceBeamFactory(const IceBeamFactory& other) = default;
    IceBeamFactory& operator=(const IceBeamFactory& other) = default;
    IceBeamFactory(IceBeamFactory&& other) noexcept = default;
    IceBeamFactory& operator=(IceBeamFactory&& other) noexcept = default;

    std::shared_ptr<Projectile> CreateObject() override;

private:
    std::shared_ptr<IProjectileMove> CreateMoveComponent() override;
    std::shared_ptr<IProjectileHit> CreateHitComponent() override;
    std::shared_ptr<IProjectileSetCollider> CreateSetColliderComponent() override;
    std::shared_ptr<IProjectileVisible> CreateVisibleComponent() override;
    
};
