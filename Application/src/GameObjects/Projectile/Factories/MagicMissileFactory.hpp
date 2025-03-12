#pragma once
#include "IProjectileFactory.hpp"

class MagicMissileFactory : public IProjectileFactory
{
public:
    MagicMissileFactory() = default;
    ~MagicMissileFactory() override = default;
    MagicMissileFactory(const MagicMissileFactory& other) = default;
    MagicMissileFactory& operator=(const MagicMissileFactory& other) = default;
    MagicMissileFactory(MagicMissileFactory&& other) noexcept = default;
    MagicMissileFactory& operator=(MagicMissileFactory&& other) noexcept = default;

    std::shared_ptr<Projectile> CreateObject() override;

private:
    std::shared_ptr<IProjectileMove> CreateMoveComponent() override;
    std::shared_ptr<IProjectileHit> CreateHitComponent() override;
    std::shared_ptr<IProjectileSetCollider> CreateSetColliderComponent() override;
    std::shared_ptr<IProjectileVisible> CreateVisibleComponent() override;
    
};
