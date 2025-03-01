#pragma once
#include <memory>

#include "Entity.hpp"
#include "IEntityAttack.hpp"
#include "IEntityFactory.hpp"
#include "IEntityMove.hpp"
#include "IEntitySetCollider.hpp"
#include "IEntityTakeDamage.hpp"
#include "IEntityVisible.hpp"

class RookFactory : public IEntityFactory
{
public:
    RookFactory() = default;
    ~RookFactory() override = default;
    RookFactory(const RookFactory& other) = default;
    RookFactory& operator=(const RookFactory& other) = default;
    RookFactory(RookFactory&& other) noexcept = default;
    RookFactory& operator=(RookFactory&& other) noexcept = default;
    
    std::shared_ptr<Entity> CreateEntity() override;

private:
    std::shared_ptr<IEntityAttack> CreateAttackComponent() override;
    std::shared_ptr<IEntityMove> CreateMoveComponent() override;
    std::shared_ptr<IEntityVisible> CreateVisibleComponent() override;
    std::shared_ptr<IEntityTakeDamage> CreateTakeDamageComponent() override;
    std::shared_ptr<IEntitySetCollider> CreateSetColliderComponent() override;
};
