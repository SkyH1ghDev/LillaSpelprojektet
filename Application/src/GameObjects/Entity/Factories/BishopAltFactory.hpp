#pragma once
#include "IEntityFactory.hpp"

class BishopAltFactory : public IEntityFactory
{
public:
    BishopAltFactory() = default;
    ~BishopAltFactory() override = default;
    BishopAltFactory(const BishopAltFactory& other) = default;
    BishopAltFactory& operator=(const BishopAltFactory& other) = default;
    BishopAltFactory(BishopAltFactory&& other) noexcept = default;
    BishopAltFactory& operator=(BishopAltFactory&& other) noexcept = default;

    std::shared_ptr<Entity> CreateEntity() override;

private:
    std::shared_ptr<IEntityAttack> CreateAttackComponent() override;
    std::shared_ptr<IEntityMove> CreateMoveComponent() override;
    std::shared_ptr<IEntityVisible> CreateVisibleComponent() override;
    std::shared_ptr<IEntityTakeDamage> CreateTakeDamageComponent() override;
    std::shared_ptr<IEntitySetCollider> CreateSetColliderComponent() override;

};
