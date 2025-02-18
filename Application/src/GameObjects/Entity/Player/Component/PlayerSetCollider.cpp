#include "PlayerSetCollider.hpp"

#include <SpEngine/Physics/Collider.hpp>

Collider PlayerSetCollider::CreateCollider(DX::XMFLOAT2 position)
{
	return Collider(position, 10.0f, 1.65f, CollisionLayer::Player, CollisionLayer::EnemyProjectile);
}
