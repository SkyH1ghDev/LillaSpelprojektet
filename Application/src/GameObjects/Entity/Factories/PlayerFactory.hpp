#pragma once
#include "IEntityFactory.hpp"
#include "PlayerAttack.hpp"
#include "PlayerMove.hpp"
#include "PlayerVisible.hpp"
#include "PlayerTakeDamage.hpp"
#include "PlayerSetCollider.hpp"

class PlayerFactory : public IEntityFactory
{
public:
    PlayerFactory() = default;
    ~PlayerFactory() override = default;
    PlayerFactory(const PlayerFactory& other) = default;
    PlayerFactory& operator=(const PlayerFactory& other) = default;
    PlayerFactory(PlayerFactory&& other) noexcept = default;
    PlayerFactory& operator=(PlayerFactory&& other) noexcept = default;

    std::shared_ptr<Entity> CreateEntity(const std::string& name) override;
    
private:
    std::shared_ptr<IEntityAttack> CreateAttackComponent() override;
    std::shared_ptr<IEntityMove> CreateMoveComponent() override;
    std::shared_ptr<IEntityVisible> CreateVisibleComponent() override;
    std::shared_ptr<IEntitySetCollider> CreateSetColliderComponent() override;
    std::shared_ptr<IEntityTakeDamage> CreateTakeDamageComponent() override;
    
};

inline std::shared_ptr<Entity> PlayerFactory::CreateEntity(const std::string& name)
{
    return std::make_shared<Entity>
    (
        Entity
        (
            CreateAttackComponent(),
            CreateMoveComponent(),
            CreateVisibleComponent(),
            CreateSetColliderComponent(),
            CreateTakeDamageComponent(),
            EntityType::Player,
            name
        )
    );
}

inline std::shared_ptr<IEntityAttack> PlayerFactory::CreateAttackComponent()
{
    return std::make_shared<PlayerAttack>();
}

inline std::shared_ptr<IEntityMove> PlayerFactory::CreateMoveComponent()
{
    return std::make_shared<PlayerMove>();
}

inline std::shared_ptr<IEntityVisible> PlayerFactory::CreateVisibleComponent()
{
    return std::make_shared<PlayerVisible>();
}

inline std::shared_ptr<IEntitySetCollider> PlayerFactory::CreateSetColliderComponent()
{
    return std::make_shared<PlayerSetCollider>();
}

inline std::shared_ptr<IEntityTakeDamage> PlayerFactory::CreateTakeDamageComponent()
{
    return std::make_shared<PlayerTakeDamage>();
}
