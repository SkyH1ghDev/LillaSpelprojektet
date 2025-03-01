#pragma once
#include "IEntityFactory.hpp"

class PawnFactory : public IEntityFactory
{
public:
    PawnFactory() = default;
    ~PawnFactory() override = default;
    PawnFactory(const PawnFactory& other) = default;
    PawnFactory& operator=(const PawnFactory& other) = default;
    PawnFactory(PawnFactory&& other) noexcept = default;
    PawnFactory& operator=(PawnFactory&& other) noexcept = default;

    std::shared_ptr<Entity> CreateEntity() override;

private:
    std::shared_ptr<IEntityAttack> CreateAttackComponent() override;
    std::shared_ptr<IEntityMove> CreateMoveComponent() override;
    std::shared_ptr<IEntityVisible> CreateVisibleComponent() override;
    std::shared_ptr<IEntityTakeDamage> CreateTakeDamageComponent() override;
    std::shared_ptr<IEntityUseCard> CreateUseCardComponent() override;
    
};
