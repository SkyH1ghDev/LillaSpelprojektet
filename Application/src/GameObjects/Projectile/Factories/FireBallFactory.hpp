#pragma once
#include "IProjectileFactory.hpp"

class FireBallFactory : public IProjectileFactory
{
public:
    FireBallFactory() = default;
    ~FireBallFactory() override = default;
    FireBallFactory(const FireBallFactory& other) = default;
    FireBallFactory& operator=(const FireBallFactory& other) = default;
    FireBallFactory(FireBallFactory&& other) noexcept = default;
    FireBallFactory& operator=(FireBallFactory&& other) noexcept = default;

    std::shared_ptr<Projectile> CreateObject() override;

private:
    std::shared_ptr<IProjectileMove> CreateMoveComponent() override;
    std::shared_ptr<IProjectileHit> CreateHitComponent() override;
    std::shared_ptr<IProjectileSetCollider> CreateSetColliderComponent() override;
    std::shared_ptr<IProjectileVisible> CreateVisibleComponent() override;
    
};
