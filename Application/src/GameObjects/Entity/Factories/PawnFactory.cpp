#include "PawnFactory.hpp"

#include "PawnController.hpp"
#include "PawnAttack.hpp"
#include "PawnMove.hpp"
#include "PawnSetCollider.hpp"
#include "PawnTakeDamage.hpp"
#include "PawnVisible.hpp"

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
    
    pawn->AttachScript(std::make_shared<PawnController>());
    return pawn;
}

std::shared_ptr<IEntityAttack> PawnFactory::CreateAttackComponent()
{
    return std::make_shared<PawnAttack>();
}

std::shared_ptr<IEntityMove> PawnFactory::CreateMoveComponent()
{
    return std::make_shared<PawnMove>();
}

std::shared_ptr<IEntityVisible> PawnFactory::CreateVisibleComponent()
{
    return std::make_shared<PawnVisible>();
}

std::shared_ptr<IEntityTakeDamage> PawnFactory::CreateTakeDamageComponent()
{
    return std::make_shared<PawnTakeDamage>();
}

std::shared_ptr<IEntitySetCollider> PawnFactory::CreateSetColliderComponent()
{
    return std::make_shared<PawnSetCollider>();
}

