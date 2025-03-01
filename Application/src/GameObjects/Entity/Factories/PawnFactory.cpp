#include "PawnFactory.hpp"

#include "BishopAttack.hpp"
#include "BishopMove.hpp"
#include "BishopTakeDamage.hpp"
#include "BishopVisible.hpp"

std::shared_ptr<Entity> PawnFactory::CreateEntity()
{
    return std::make_shared<Entity>
    (
        Entity
        (
            CreateAttackComponent(),
            CreateMoveComponent(),
            CreateVisibleComponent(),
            CreateTakeDamageComponent(),
            CreateUseCardComponent(),
            EntityType::Pawn,
            "Pawn"
        )
    );
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

std::shared_ptr<IEntityUseCard> PawnFactory::CreateUseCardComponent()
{
    return nullptr;  
}

