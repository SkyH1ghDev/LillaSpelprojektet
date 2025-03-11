#pragma once
#include "IProjectileFactory.hpp"

class HasteFactory : public IProjectileFactory
{
public:
    HasteFactory() = default;
    ~HasteFactory() override = default;
    HasteFactory(const HasteFactory& other) = default;
    HasteFactory& operator=(const HasteFactory& other) = default;
    HasteFactory(HasteFactory&& other) noexcept = default;
    HasteFactory& operator=(HasteFactory&& other) noexcept = default;

    std::shared_ptr<Projectile> CreateObject() override;

private:
    std::shared_ptr<IProjectileMove> CreateMoveComponent() override;
    std::shared_ptr<IProjectileHit> CreateHitComponent() override;
    std::shared_ptr<IProjectileSetCollider> CreateSetColliderComponent() override;
    std::shared_ptr<IProjectileVisible> CreateVisibleComponent() override;
    
};
