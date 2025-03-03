#include "BishopBallSetCollider.hpp"

#include <SpEngine/Physics/Collider.hpp>

Collider BishopBallSetCollider::SetCollider(DX::XMFLOAT2 position)
{
	return Collider(position, 4.0f, CollisionLayer::EnemyProjectile, static_cast<CollisionLayer>(
		static_cast<int>(CollisionLayer::Player) | static_cast<int>(CollisionLayer::DisruptorWave)));
}
