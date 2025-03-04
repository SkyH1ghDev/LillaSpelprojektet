#pragma once
#include "IEntityFactory.hpp"

class PawnAltFactory : public IEntityFactory
{
public:
    PawnAltFactory() = default;
    ~PawnAltFactory() override = default;
    PawnAltFactory(const PawnAltFactory& other) = default;
    PawnAltFactory& operator=(const PawnAltFactory& other) = default;
    PawnAltFactory(PawnAltFactory&& other) noexcept = default;
    PawnAltFactory& operator=(PawnAltFactory&& other) noexcept = default;

    std::shared_ptr<Entity> CreateEntity() override;

private:
    std::shared_ptr<IEntityAttack> CreateAttackComponent() override;
    std::shared_ptr<IEntityMove> CreateMoveComponent() override;
    std::shared_ptr<IEntityVisible> CreateVisibleComponent() override;
    std::shared_ptr<IEntityTakeDamage> CreateTakeDamageComponent() override;
    std::shared_ptr<IEntitySetCollider> CreateSetColliderComponent() override;
    
};
