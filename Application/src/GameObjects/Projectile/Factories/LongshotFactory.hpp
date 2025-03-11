#pragma once
#include "IProjectileFactory.hpp"

class LongshotFactory : public IProjectileFactory
{
public:
    LongshotFactory() = default;
    ~LongshotFactory() override = default;
    LongshotFactory(const LongshotFactory& other) = default;
    LongshotFactory& operator=(const LongshotFactory& other) = default;
    LongshotFactory(LongshotFactory&& other) noexcept = default;
    LongshotFactory& operator=(LongshotFactory&& other) noexcept = default;

    std::shared_ptr<Projectile> CreateObject() override;

private:
    std::shared_ptr<IProjectileMove> CreateMoveComponent() override;
    std::shared_ptr<IProjectileHit> CreateHitComponent() override;
    std::shared_ptr<IProjectileSetCollider> CreateSetColliderComponent() override;
    std::shared_ptr<IProjectileVisible> CreateVisibleComponent() override;
    
};
