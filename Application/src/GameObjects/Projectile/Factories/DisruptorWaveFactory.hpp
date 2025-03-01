#pragma once
#include "IProjectileFactory.hpp"

class DisruptorWaveFactory : public IProjectileFactory
{
public:
    DisruptorWaveFactory() = default;
    ~DisruptorWaveFactory() override = default;
    DisruptorWaveFactory(const DisruptorWaveFactory& other) = default;
    DisruptorWaveFactory& operator=(const DisruptorWaveFactory& other) = default;
    DisruptorWaveFactory(DisruptorWaveFactory&& other) noexcept = default;
    DisruptorWaveFactory& operator=(DisruptorWaveFactory&& other) noexcept = default;

    std::shared_ptr<Projectile> CreateObject() override;

private:
    std::shared_ptr<IProjectileMove> CreateMoveComponent() override;
    std::shared_ptr<IProjectileHit> CreateHitComponent() override;
    std::shared_ptr<IProjectileSetCollider> CreateSetColliderComponent() override;
    std::shared_ptr<IProjectileVisible> CreateVisibleComponent() override;
    
};
