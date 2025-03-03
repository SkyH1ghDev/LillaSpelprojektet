#include "RookAltFactory.hpp"

#include "RookAltAttack.hpp"
#include "RookController.hpp"
#include "RookMove.hpp"
#include "RookSetCollider.hpp"
#include "RookTakeDamage.hpp"
#include "RookAltVisible.hpp"

std::shared_ptr<Entity> RookAltFactory::CreateEntity()
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
            EntityType::RookAlt,
            "BishopAlt"
        )
    );
    
    bishop->Initialize();
    bishop->AttachScript(std::make_shared<RookController>());
    return bishop;
}

std::shared_ptr<IEntityAttack> RookAltFactory::CreateAttackComponent()
{
    return std::make_shared<RookAttack>();
}

std::shared_ptr<IEntityMove> RookAltFactory::CreateMoveComponent()
{
    return std::make_shared<RookMove>();
}

std::shared_ptr<IEntityVisible> RookAltFactory::CreateVisibleComponent()
{
    return std::make_shared<RookVisible>();
}

std::shared_ptr<IEntityTakeDamage> RookAltFactory::CreateTakeDamageComponent()
{
    return std::make_shared<RookTakeDamage>();
}

std::shared_ptr<IEntitySetCollider> RookAltFactory::CreateSetColliderComponent()
{
    return std::make_shared<RookSetCollider>();
}
