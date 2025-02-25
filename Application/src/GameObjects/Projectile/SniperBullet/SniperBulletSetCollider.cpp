#include "SniperBulletSetCollider.hpp"

#include <SpEngine/Physics/Collider.hpp>

Collider SniperBulletSetCollider::SetCollider(DX::XMFLOAT2 position)
{
	return Collider(position, 1.0f, CollisionLayer::AllyProjectile, CollisionLayer::Enemy);
}
