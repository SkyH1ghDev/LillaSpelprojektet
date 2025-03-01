#include "RookFactory.hpp"

#include "RookAttack.hpp"
#include "RookController.hpp"
#include "RookMove.hpp"
#include "RookSetCollider.hpp"
#include "RookTakeDamage.hpp"
#include "RookVisible.hpp"

std::shared_ptr<Entity> RookFactory::CreateEntity()
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
    bishop->AttachScript(std::make_shared<RookController>());
    return bishop;
}

std::shared_ptr<IEntityAttack> RookFactory::CreateAttackComponent()
{
    return std::make_shared<RookAttack>();
}

std::shared_ptr<IEntityMove> RookFactory::CreateMoveComponent()
{
    return std::make_shared<RookMove>();
}

std::shared_ptr<IEntityVisible> RookFactory::CreateVisibleComponent()
{
    return std::make_shared<RookVisible>();
}

std::shared_ptr<IEntityTakeDamage> RookFactory::CreateTakeDamageComponent()
{
    return std::make_shared<RookTakeDamage>();
}

std::shared_ptr<IEntitySetCollider> RookFactory::CreateSetColliderComponent()
{
    return std::make_shared<RookSetCollider>();
}
