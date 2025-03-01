#pragma once
#include "IProjectileFactory.hpp"

class SniperBulletFactory : public IProjectileFactory
{
public:
    SniperBulletFactory() = default;
    ~SniperBulletFactory() override = default;
    SniperBulletFactory(const SniperBulletFactory& other) = default;
    SniperBulletFactory& operator=(const SniperBulletFactory& other) = default;
    SniperBulletFactory(SniperBulletFactory&& other) noexcept = default;
    SniperBulletFactory& operator=(SniperBulletFactory&& other) noexcept = default;

    std::shared_ptr<Projectile> CreateObject() override;

private:
    std::shared_ptr<IProjectileMove> CreateMoveComponent() override;
    std::shared_ptr<IProjectileHit> CreateHitComponent() override;
    std::shared_ptr<IProjectileSetCollider> CreateSetColliderComponent() override;
    std::shared_ptr<IProjectileVisible> CreateVisibleComponent() override;
    
};
