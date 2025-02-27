#include "EntitySetColliderComponentFactory.hpp"
#include <stdexcept>

std::shared_ptr<IEntitySetCollider> CreateColliderComponent(EntityType type)
{
	switch (type)
	{
	case EntityType::Player:
		return std::make_shared<PlayerSetCollider>();
		break;
	case EntityType::Bishop:
		return std::make_shared<BishopSetCollider>();
	default:
		throw std::invalid_argument("Unknown EntityType in CreateColliderComponent");
		break;
	}
}
