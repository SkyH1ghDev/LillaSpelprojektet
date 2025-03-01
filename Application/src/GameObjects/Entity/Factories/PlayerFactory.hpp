#pragma once
#include "IEntityFactory.hpp"

class PlayerFactory : public IEntityFactory
{
public:
    PlayerFactory() = default;
    ~PlayerFactory() override = default;
    PlayerFactory(const PlayerFactory& other) = default;
    PlayerFactory& operator=(const PlayerFactory& other) = default;
    PlayerFactory(PlayerFactory&& other) noexcept = default;
    PlayerFactory& operator=(PlayerFactory&& other) noexcept = default;

    std::shared_ptr<Entity> CreateEntity() override;

private:
    std::shared_ptr<IEntityAttack> CreateAttackComponent() override;
    std::shared_ptr<IEntityMove> CreateMoveComponent() override;
    std::shared_ptr<IEntityVisible> CreateVisibleComponent() override;
    std::shared_ptr<IEntityTakeDamage> CreateTakeDamageComponent() override;
    std::shared_ptr<IEntityUseCard> CreateUseCardComponent() override;
    std::shared_ptr<IEntitySetCollider> CreateSetColliderComponent() override;
    
};
