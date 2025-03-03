#pragma once
#include <memory>

#include "Entity.hpp"
#include "IEntityAttack.hpp"
#include "IEntityFactory.hpp"
#include "IEntityMove.hpp"
#include "IEntitySetCollider.hpp"
#include "IEntityTakeDamage.hpp"
#include "IEntityVisible.hpp"

class RookAltFactory : public IEntityFactory
{
public:
    RookAltFactory() = default;
    ~RookAltFactory() override = default;
    RookAltFactory(const RookAltFactory& other) = default;
    RookAltFactory& operator=(const RookAltFactory& other) = default;
    RookAltFactory(RookAltFactory&& other) noexcept = default;
    RookAltFactory& operator=(RookAltFactory&& other) noexcept = default;
    
    std::shared_ptr<Entity> CreateEntity() override;

private:
    std::shared_ptr<IEntityAttack> CreateAttackComponent() override;
    std::shared_ptr<IEntityMove> CreateMoveComponent() override;
    std::shared_ptr<IEntityVisible> CreateVisibleComponent() override;
    std::shared_ptr<IEntityTakeDamage> CreateTakeDamageComponent() override;
    std::shared_ptr<IEntitySetCollider> CreateSetColliderComponent() override;
};
