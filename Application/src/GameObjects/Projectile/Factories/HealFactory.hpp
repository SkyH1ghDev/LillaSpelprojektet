#pragma once
#include "IProjectileFactory.hpp"

class HealFactory : public IProjectileFactory
{
public:
    HealFactory() = default;
    ~HealFactory() override = default;
    HealFactory(const HealFactory& other) = default;
    HealFactory& operator=(const HealFactory& other) = default;
    HealFactory(HealFactory&& other) noexcept = default;
    HealFactory& operator=(HealFactory&& other) noexcept = default;

    std::shared_ptr<Projectile> CreateObject() override;

private:
    std::shared_ptr<IProjectileMove> CreateMoveComponent() override;
    std::shared_ptr<IProjectileHit> CreateHitComponent() override;
    std::shared_ptr<IProjectileSetCollider> CreateSetColliderComponent() override;
    std::shared_ptr<IProjectileVisible> CreateVisibleComponent() override;
    
};
