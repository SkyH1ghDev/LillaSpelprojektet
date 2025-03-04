#include "PawnAltFactory.hpp"

#include "PawnController.hpp"
#include "PawnAltAttack.hpp"
#include "PawnMove.hpp"
#include "PawnSetCollider.hpp"
#include "PawnTakeDamage.hpp"
#include "PawnAltVisible.hpp"

std::shared_ptr<Entity> PawnAltFactory::CreateEntity()
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
            EntityType::PawnAlt,
            "PawnAlt"
        )
    );

    pawn->Initialize();
    
    pawn->AttachScript(std::make_shared<PawnController>());
    return pawn;
}

std::shared_ptr<IEntityAttack> PawnAltFactory::CreateAttackComponent()
{
    return std::make_shared<PawnAltAttack>();
}

std::shared_ptr<IEntityMove> PawnAltFactory::CreateMoveComponent()
{
    return std::make_shared<PawnMove>();
}

std::shared_ptr<IEntityVisible> PawnAltFactory::CreateVisibleComponent()
{
    return std::make_shared<PawnAltVisible>();
}

std::shared_ptr<IEntityTakeDamage> PawnAltFactory::CreateTakeDamageComponent()
{
    return std::make_shared<PawnTakeDamage>();
}

std::shared_ptr<IEntitySetCollider> PawnAltFactory::CreateSetColliderComponent()
{
    return std::make_shared<PawnSetCollider>();
}

