#pragma once
#include "IEntityFactory.hpp"
#include "BishopAttack.hpp"
#include "BishopMove.hpp"
#include "PawnMove.hpp"
#include "BishopVisible.hpp"
#include "BishopTakeDamage.hpp"
#include "BishopSetCollider.hpp"

class BishopFactory : public IEntityFactory
{
public:
    BishopFactory() = default;
    ~BishopFactory() override = default;
    BishopFactory(const BishopFactory& other) = default;
    BishopFactory& operator=(const BishopFactory& other) = default;
    BishopFactory(BishopFactory&& other) noexcept = default;
    BishopFactory& operator=(BishopFactory&& other) noexcept = default;

    std::shared_ptr<Entity> CreateEntity(const std::string& name) override;
    
private:
    std::shared_ptr<IEntityAttack> CreateAttackComponent() override;
    std::shared_ptr<IEntityMove> CreateMoveComponent() override;
    std::shared_ptr<IEntityVisible> CreateVisibleComponent() override;
    std::shared_ptr<IEntitySetCollider> CreateSetColliderComponent() override;
    std::shared_ptr<IEntityTakeDamage> CreateTakeDamageComponent() override;
    std::shared_ptr<IEntityDash> CreateDashComponent() override;
};

inline std::shared_ptr<Entity> BishopFactory::CreateEntity(const std::string& name)
{
    return std::make_shared<Entity>
    (
        Entity
        (
            CreateAttackComponent(),
            CreateMoveComponent(),
            CreateVisibleComponent(),
            CreateSetColliderComponent(),
            CreateTakeDamageComponent(),
            CreateDashComponent(),
            EntityType::Bishop,
            name
        )
    );

}

inline std::shared_ptr<IEntityAttack> BishopFactory::CreateAttackComponent()
{
    return std::make_shared<BishopAttack>();
}

inline std::shared_ptr<IEntityMove> BishopFactory::CreateMoveComponent()
{
    return std::make_shared<BishopMove>();
}

inline std::shared_ptr<IEntityDash> BishopFactory::CreateDashComponent()
{
    return nullptr;
}

inline std::shared_ptr<IEntityVisible> BishopFactory::CreateVisibleComponent()
{
    return std::make_shared<BishopVisible>();
}

inline std::shared_ptr<IEntitySetCollider> BishopFactory::CreateSetColliderComponent()
{
    return std::make_shared<BishopSetCollider>();
}

inline std::shared_ptr<IEntityTakeDamage> BishopFactory::CreateTakeDamageComponent()
{
    return std::make_shared<BishopTakeDamage>();
}
