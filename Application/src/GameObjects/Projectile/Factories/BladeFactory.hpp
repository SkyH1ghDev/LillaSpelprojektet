#pragma once
#include "IProjectileFactory.hpp"

class BladeFactory : public IProjectileFactory
{
public:
    BladeFactory() = default;
    ~BladeFactory() override = default;
    BladeFactory(const BladeFactory& other) = default;
    BladeFactory& operator=(const BladeFactory& other) = default;
    BladeFactory(BladeFactory&& other) noexcept = default;
    BladeFactory& operator=(BladeFactory&& other) noexcept = default;

    std::shared_ptr<Projectile> CreateObject() override;

private:
    std::shared_ptr<IProjectileMove> CreateMoveComponent() override;
    std::shared_ptr<IProjectileHit> CreateHitComponent() override;
    std::shared_ptr<IProjectileSetCollider> CreateSetColliderComponent() override;
    std::shared_ptr<IProjectileVisible> CreateVisibleComponent() override;
    
};
