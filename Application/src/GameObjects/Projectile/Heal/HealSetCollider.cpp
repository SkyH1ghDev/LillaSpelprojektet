#include "LongshotSetCollider.hpp"

#include <SpEngine/Physics/Collider.hpp>

Collider LongshotSetCollider::SetCollider(DX::XMFLOAT2 position)
{
	return Collider(position, 2.0f, CollisionLayer::AllyProjectile, CollisionLayer::Enemy);
}
