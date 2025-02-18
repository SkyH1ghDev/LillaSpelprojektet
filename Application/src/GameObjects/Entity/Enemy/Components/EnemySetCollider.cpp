#include "EnemySetCollider.hpp"

#include <SpEngine/Physics/Collider.hpp>

Collider EnemySetCollider::CreateCollider(DX::XMFLOAT2 position)
{
	return Collider(position, 10.0f, CollisionLayer::Enemy, CollisionLayer::Projectile);
}
