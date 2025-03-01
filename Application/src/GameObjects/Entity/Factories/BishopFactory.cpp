#include "BishopFactory.hpp" 
#include "BishopAttack.hpp"
#include "BishopMove.hpp"
#include "BishopTakeDamage.hpp"
#include "BishopVisible.hpp"
#include "BishopSetCollider.hpp"
#include "BishopController.hpp"

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
            CreateSetColliderComponent(),
            EntityType::Bishop,
            "Bishop"
        )
    );
    
    bishop->Initialize();
    bishop->AttachScript(std::make_shared<BishopController>());
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

std::shared_ptr<IEntitySetCollider> BishopFactory::CreateSetColliderComponent()
{
    return std::make_shared<BishopSetCollider>();
}
