#include "BladeSetCollider.hpp"

#include <SpEngine/Physics/Collider.hpp>

Collider BladeSetCollider::SetCollider(DX::XMFLOAT2 position)
{
	return Collider(position, 4.0f, CollisionLayer::Blade, static_cast<CollisionLayer>(
		static_cast<int>(CollisionLayer::Enemy) | static_cast<int>(CollisionLayer::EnemyProjectile)));
}
