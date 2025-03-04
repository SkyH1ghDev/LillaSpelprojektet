#include "FireBallSetCollider.hpp"

#include <SpEngine/Physics/Collider.hpp>

Collider FireBallSetCollider::SetCollider(DX::XMFLOAT2 position)
{
	return Collider(position, 5.0f, 2.0f, CollisionLayer::AllyProjectile, CollisionLayer::Enemy);
}
