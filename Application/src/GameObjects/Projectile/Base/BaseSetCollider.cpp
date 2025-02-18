#include "BaseSetCollider.hpp"

#include <SpEngine/Physics/Collider.hpp>

Collider BaseSetCollider::SetCollider(DX::XMFLOAT2 position)
{
	return Collider(position, 10.0f, CollisionLayer::Enemy, CollisionLayer::AllyProjectile);
}
