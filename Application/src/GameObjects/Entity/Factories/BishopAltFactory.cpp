#include "BishopAltFactory.hpp" 
#include "BishopAltAttack.hpp"
#include "BishopMove.hpp"
#include "BishopTakeDamage.hpp"
#include "BishopAltVisible.hpp"
#include "BishopSetCollider.hpp"
#include "BishopController.hpp"

std::shared_ptr<Entity> BishopAltFactory::CreateEntity()
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
                EntityType::BishopAlt,
                "BishopDark"
            )
        );

    bishop->Initialize();
    bishop->AttachScript(std::make_shared<BishopController>());
    return bishop;
}

std::shared_ptr<IEntityAttack> BishopAltFactory::CreateAttackComponent()
{
    return std::make_shared<BishopAltAttack>();
}

std::shared_ptr<IEntityMove> BishopAltFactory::CreateMoveComponent()
{
    return std::make_shared<BishopMove>();
}

std::shared_ptr<IEntityVisible> BishopAltFactory::CreateVisibleComponent()
{
    return std::make_shared<BishopAltVisible>();
}

std::shared_ptr<IEntityTakeDamage> BishopAltFactory::CreateTakeDamageComponent()
{
    return std::make_shared<BishopTakeDamage>();
}

std::shared_ptr<IEntitySetCollider> BishopAltFactory::CreateSetColliderComponent()
{
    return std::make_shared<BishopSetCollider>();
}
