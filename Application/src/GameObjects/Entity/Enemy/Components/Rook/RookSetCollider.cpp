#include "RookSetCollider.hpp"

#include <SpEngine/Physics/Collider.hpp>

Collider RookSetCollider::CreateCollider(DX::XMFLOAT2 position)
{
	return Collider(position, 20.0f, 1.4f, CollisionLayer::Enemy, static_cast<CollisionLayer>(
		static_cast<int>(CollisionLayer::AllyProjectile) | static_cast<int>(CollisionLayer::Player) | static_cast<int>(CollisionLayer::Blade)));
}
