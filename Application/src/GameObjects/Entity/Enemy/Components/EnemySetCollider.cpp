#include "EnemySetCollider.hpp"

#include <SpEngine/Physics/Collider.hpp>

Collider EnemySetCollider::CreateCollider(DX::XMFLOAT2 position)
{
	return Collider(position, 10.0f, CollisionLayer::Enemy, static_cast<CollisionLayer>(
		static_cast<int>(CollisionLayer::AllyProjectile) | static_cast<int>(CollisionLayer::Player) | static_cast<int>(CollisionLayer::StaticMesh) ));
}
