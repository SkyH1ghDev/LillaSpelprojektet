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
		break;
	case EntityType::Rook:
		return std::make_shared<RookSetCollider>();
		break;
	default:
		throw std::invalid_argument("Unknown EntityType in CreateColliderComponent");
		break;
	}
}
