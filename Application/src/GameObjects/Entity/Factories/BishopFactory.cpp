#include "BishopFactory.hpp" 
#include "BishopAttack.hpp"
#include "BishopMove.hpp"
#include "BishopTakeDamage.hpp"
#include "BishopVisible.hpp"
#include "EnemyController.hpp"

std::shared_ptr<Entity> BishopFactory::CreateEntity()
{
    std::shared_ptr<Entity> bishop = std::make_shared<Entity> 
    (
        Entity
        (
            CreateAttackComponent(),
            CreateMoveComponent(),
            CreateVisibleComponent(),
            CreateTakeDamageComponent(),
            CreateUseCardComponent(),
            EntityType::Bishop,
            "Bishop"
        )
    );
    bishop->AttachScript(std::make_shared<EnemyController>());
    return bishop;
}

std::shared_ptr<IEntityAttack> BishopFactory::CreateAttackComponent()
{
    return std::make_shared<BishopAttack>();
}

std::shared_ptr<IEntityMove> BishopFactory::CreateMoveComponent()
{
    return std::make_shared<BishopMove>();
}

std::shared_ptr<IEntityVisible> BishopFactory::CreateVisibleComponent()
{
    return std::make_shared<BishopVisible>();
}

std::shared_ptr<IEntityTakeDamage> BishopFactory::CreateTakeDamageComponent()
{
    return std::make_shared<BishopTakeDamage>();
}

std::shared_ptr<IEntityUseCard> BishopFactory::CreateUseCardComponent()
{
    return nullptr;  
}
