#include "IceCubeSetCollider.hpp"

#include <SpEngine/Physics/Collider.hpp>

Collider IceCubeSetCollider::SetCollider(DX::XMFLOAT2 position)
{
	return Collider(position, 6.0f, CollisionLayer::AllyProjectile, CollisionLayer::Enemy);
}
