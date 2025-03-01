#pragma once

#include "Entity.hpp"
#include "IEntityAttack.hpp"
#include "IEntityMove.hpp"
#include "IEntityVisible.hpp"
#include "IEntityTakeDamage.hpp"

class IEntityFactory
{
public:
    IEntityFactory() = default;
    virtual ~IEntityFactory() = default;
    IEntityFactory(const IEntityFactory& other) = default;
    IEntityFactory& operator=(const IEntityFactory& other) = default;
    IEntityFactory(IEntityFactory&& other) noexcept = default;
    IEntityFactory& operator=(IEntityFactory&& other) noexcept = default;

    [[nodiscard]]
    virtual std::shared_ptr<Entity> CreateEntity() = 0;
    
protected:
    virtual std::shared_ptr<IEntityAttack> CreateAttackComponent() = 0;
    virtual std::shared_ptr<IEntityMove> CreateMoveComponent() = 0;
    virtual std::shared_ptr<IEntityVisible> CreateVisibleComponent() = 0;
    virtual std::shared_ptr<IEntityTakeDamage> CreateTakeDamageComponent() = 0;
    virtual std::shared_ptr<IEntitySetCollider> CreateSetColliderComponent() = 0;
};
