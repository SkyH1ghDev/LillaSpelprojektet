#include "BishopBallSetCollider.hpp"

#include <SpEngine/Physics/Collider.hpp>

Collider BishopBallSetCollider::SetCollider(DX::XMFLOAT2 position)
{
	return Collider(position, 1.0f, CollisionLayer::EnemyProjectile, CollisionLayer::Player);
}
