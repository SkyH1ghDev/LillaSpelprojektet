#include "EntitySetColliderComponentFactory.hpp"
#include <stdexcept>

std::shared_ptr<IEntitySetCollider> CreateColliderComponent(EntityType type)
{
	switch (type)
	{
	case EntityType::Player:
		return std::make_shared<PlayerSetCollider>();
		break;
	case EntityType::Enemy:
		return std::make_shared<EnemySetCollider>();
	default:
		throw std::invalid_argument("Unknown EntityType in CreateColliderComponent");
		break;
	}
}
