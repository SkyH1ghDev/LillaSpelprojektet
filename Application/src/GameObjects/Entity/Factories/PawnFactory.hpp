#pragma once
#include "IEntityFactory.hpp"
#include "PawnAttack.hpp"
#include "PawnMove.hpp"
#include "BishopVisible.hpp"
#include "BishopTakeDamage.hpp"
#include "BishopSetCollider.hpp"

class PawnFactory : public IEntityFactory
{
public:
    PawnFactory() = default;
    ~PawnFactory() override = default;
    PawnFactory(const PawnFactory& other) = default;
    PawnFactory& operator=(const PawnFactory& other) = default;
    PawnFactory(PawnFactory&& other) noexcept = default;
    PawnFactory& operator=(PawnFactory&& other) noexcept = default;

    std::shared_ptr<Entity> CreateEntity(const std::string& name) override;
    
private:
    std::shared_ptr<IEntityAttack> CreateAttackComponent() override;
    std::shared_ptr<IEntityMove> CreateMoveComponent() override;
    std::shared_ptr<IEntityVisible> CreateVisibleComponent() override;
    std::shared_ptr<IEntitySetCollider> CreateSetColliderComponent() override;
    std::shared_ptr<IEntityTakeDamage> CreateTakeDamageComponent() override;
    std::shared_ptr<IEntityDash> CreateDashComponent() override;
    
};

inline std::shared_ptr<Entity> PawnFactory::CreateEntity(const std::string& name)
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
            EntityType::Pawn,
            name
        )
    );

}

inline std::shared_ptr<IEntityAttack> PawnFactory::CreateAttackComponent()
{
    return std::make_shared<PawnAttack>();
}

inline std::shared_ptr<IEntityMove> PawnFactory::CreateMoveComponent()
{
    return std::make_shared<PawnMove>();
}

inline std::shared_ptr<IEntityDash> PawnFactory::CreateDashComponent()
{
    return nullptr;
}

inline std::shared_ptr<IEntityVisible> PawnFactory::CreateVisibleComponent()
{
    return std::make_shared<BishopVisible>();
}

inline std::shared_ptr<IEntitySetCollider> PawnFactory::CreateSetColliderComponent()
{
    return std::make_shared<BishopSetCollider>();
}

inline std::shared_ptr<IEntityTakeDamage> PawnFactory::CreateTakeDamageComponent()
{
    return std::make_shared<BishopTakeDamage>();
}
