#include "IceBeamSetCollider.hpp"

#include <SpEngine/Physics/Collider.hpp>

Collider IceBeamSetCollider::SetCollider(DX::XMFLOAT2 position)
{
	return Collider(position, 4.0f, CollisionLayer::AllyProjectile, CollisionLayer::Enemy);
}
