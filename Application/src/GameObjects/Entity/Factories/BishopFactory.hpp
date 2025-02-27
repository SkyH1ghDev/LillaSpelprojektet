#pragma once
#include "IEntityFactory.hpp"


class BishopFactory : public IEntityFactory
{
public:
    BishopFactory() = default;
    ~BishopFactory() override = default;
    BishopFactory(const BishopFactory& other) = default;
    BishopFactory& operator=(const BishopFactory& other) = default;
    BishopFactory(BishopFactory&& other) noexcept = default;
    BishopFactory& operator=(BishopFactory&& other) noexcept = default;

    std::shared_ptr<IEntityAttack> CreateAttackComponent() override;
    std::shared_ptr<IEntityMove> CreateMoveComponent() override;
    std::shared_ptr<IEntityVisible> CreateVisibleComponent() override;
    std::shared_ptr<IEntitySetCollider> CreateSetColliderComponent() override;
    std::shared_ptr<IEntityTakeDamage> CreateTakeDamageComponent() override;
};

inline std::shared_ptr<IEntityAttack> BishopFactory::CreateAttackComponent()
{
    return std::make_shared<BishopAttack>();
}

inline std::shared_ptr<IEntityMove> BishopFactory::CreateMoveComponent()
{
    return std::make_shared<BishopMove>();
}
