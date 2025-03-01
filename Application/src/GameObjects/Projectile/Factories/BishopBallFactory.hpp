#pragma once
#include "IProjectileFactory.hpp"

class BishopBallFactory : public IProjectileFactory
{
public:
    BishopBallFactory() = default;
    ~BishopBallFactory() override = default;
    BishopBallFactory(const BishopBallFactory& other) = default;
    BishopBallFactory& operator=(const BishopBallFactory& other) = default;
    BishopBallFactory(BishopBallFactory&& other) noexcept = default;
    BishopBallFactory& operator=(BishopBallFactory&& other) noexcept = default;

    std::shared_ptr<Projectile> CreateObject() override;

private:
    std::shared_ptr<IProjectileMove> CreateMoveComponent() override;
    std::shared_ptr<IProjectileHit> CreateHitComponent() override;
    std::shared_ptr<IProjectileSetCollider> CreateSetColliderComponent() override;
    std::shared_ptr<IProjectileVisible> CreateVisibleComponent() override;
    
};
