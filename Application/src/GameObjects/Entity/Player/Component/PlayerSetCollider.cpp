#include "PlayerSetCollider.hpp"

#include <SpEngine/Physics/Collider.hpp>

Collider PlayerSetCollider::CreateCollider(DX::XMFLOAT2 position)
{
	return Collider(position, 9.0f, 1.65f, CollisionLayer::Player, static_cast<CollisionLayer>(
		static_cast<int>(CollisionLayer::EnemyProjectile) | static_cast<int>(CollisionLayer::Enemy)));
}
