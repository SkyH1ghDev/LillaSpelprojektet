#pragma once
#include "GameObjects/Entity/Entity.hpp"

class IEntityFactory
{
public:
    IEntityFactory() = default;
    virtual ~IEntityFactory() = default;
    IEntityFactory(const IEntityFactory& other) = default;
    IEntityFactory& operator=(const IEntityFactory& other) = default;
    IEntityFactory(IEntityFactory&& other) noexcept = default;
    IEntityFactory& operator=(IEntityFactory&& other) noexcept = default;

    virtual std::shared_ptr<Entity> CreateEntity(const std::string& name) = 0;

protected:
    virtual std::shared_ptr<IEntityAttack> CreateAttackComponent() = 0;
    virtual std::shared_ptr<IEntityMove> CreateMoveComponent() = 0;
    virtual std::shared_ptr<IEntityTakeDamage> CreateTakeDamageComponent() = 0;
    virtual std::shared_ptr<IEntitySetCollider> CreateSetColliderComponent() = 0;
    virtual std::shared_ptr<IEntityVisible> CreateVisibleComponent() = 0;
    virtual std::shared_ptr<IEntityDash> CreateDashComponent() = 0;

};
