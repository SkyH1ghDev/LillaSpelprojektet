#include "EnemySetCollider.hpp"

#include <SpEngine/Physics/Collider.hpp>

Collider EnemySetCollider::CreateCollider(DX::XMFLOAT2 position)
{
	return Collider(position, 8.0f, 2.0f, CollisionLayer::Enemy, CollisionLayer::AllyProjectile);
}
