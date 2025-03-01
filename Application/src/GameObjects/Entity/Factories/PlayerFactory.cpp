#include "PlayerFactory.hpp"

#include <memory>

#include "PlayerAttack.hpp"
#include "PlayerController.hpp"
#include "PlayerMove.hpp"
#include "PlayerSetCollider.hpp"
#include "PlayerTakeDamage.hpp"
#include "PlayerVisible.hpp"

std::shared_ptr<Entity> PlayerFactory::CreateEntity()
{
    std::shared_ptr<Entity> player = std::make_shared<Entity>
    (
        Entity
        (
            CreateAttackComponent(),
            CreateMoveComponent(),
            CreateVisibleComponent(),
            CreateTakeDamageComponent(),
            CreateSetColliderComponent(),
            EntityType::Player,
            "Player"
        )
    );

    player->Initialize();
    
    std::shared_ptr<PlayerController> playerController = std::make_shared<PlayerController>();
    player->AttachScript(playerController);
    
    return player;
}

std::shared_ptr<IEntityAttack> PlayerFactory::CreateAttackComponent()
{
    return std::make_shared<PlayerAttack>();
}

std::shared_ptr<IEntityMove> PlayerFactory::CreateMoveComponent()
{
    return std::make_shared<PlayerMove>();
}

std::shared_ptr<IEntityVisible> PlayerFactory::CreateVisibleComponent()
{
    return std::make_shared<PlayerVisible>();
}

std::shared_ptr<IEntityTakeDamage> PlayerFactory::CreateTakeDamageComponent()
{
    return std::make_shared<PlayerTakeDamage>();
}

std::shared_ptr<IEntitySetCollider> PlayerFactory::CreateSetColliderComponent()
{
    return std::make_shared<PlayerSetCollider>();
}
