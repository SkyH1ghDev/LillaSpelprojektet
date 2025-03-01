#include "PawnFactory.hpp"

#include "BishopAttack.hpp"
#include "BishopMove.hpp"
#include "BishopSetCollider.hpp"
#include "BishopTakeDamage.hpp"
#include "BishopVisible.hpp"
#include "BishopController.hpp"

std::shared_ptr<Entity> PawnFactory::CreateEntity()
{
    std::shared_ptr<Entity> pawn = std::make_shared<Entity>
    (
        Entity
        (
            CreateAttackComponent(),
            CreateMoveComponent(),
            CreateVisibleComponent(),
            CreateTakeDamageComponent(),
            CreateSetColliderComponent(),
            EntityType::Pawn,
            "Pawn"
        )
    );

    pawn->Initialize();
    
    pawn->AttachScript(std::make_shared<BishopController>());
    return pawn;
}

std::shared_ptr<IEntityAttack> PawnFactory::CreateAttackComponent()
{
    return std::make_shared<BishopAttack>();
}

std::shared_ptr<IEntityMove> PawnFactory::CreateMoveComponent()
{
    return std::make_shared<BishopMove>();
}

std::shared_ptr<IEntityVisible> PawnFactory::CreateVisibleComponent()
{
    return std::make_shared<BishopVisible>();
}

std::shared_ptr<IEntityTakeDamage> PawnFactory::CreateTakeDamageComponent()
{
    return std::make_shared<BishopTakeDamage>();
}

std::shared_ptr<IEntitySetCollider> PawnFactory::CreateSetColliderComponent()
{
    return std::make_shared<BishopSetCollider>();
}

