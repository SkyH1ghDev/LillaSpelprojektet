#pragma once
#include "IProjectileFactory.hpp"

class BaseProjectileFactory : public IProjectileFactory
{
public:
    BaseProjectileFactory() = default;
    ~BaseProjectileFactory() override = default;
    BaseProjectileFactory(const BaseProjectileFactory& other) = default;
    BaseProjectileFactory& operator=(const BaseProjectileFactory& other) = default;
    BaseProjectileFactory(BaseProjectileFactory&& other) noexcept = default;
    BaseProjectileFactory& operator=(BaseProjectileFactory&& other) noexcept = default;
    
    std::shared_ptr<Projectile> CreateObject() override;

private:
    std::shared_ptr<IProjectileMove> CreateMoveComponent() override;
    std::shared_ptr<IProjectileHit> CreateHitComponent() override;
    std::shared_ptr<IProjectileSetCollider> CreateSetColliderComponent() override;
    std::shared_ptr<IProjectileVisible> CreateVisibleComponent() override;
    
};
