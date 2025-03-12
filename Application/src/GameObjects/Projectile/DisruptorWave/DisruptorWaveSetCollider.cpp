#include "DisruptorWaveSetCollider.hpp"

#include <SpEngine/Physics/Collider.hpp>

Collider DisruptorWaveSetCollider::SetCollider(DX::XMFLOAT2 position)
{
	return Collider(position, 1.0f, static_cast<CollisionLayer>(
		static_cast<int>(CollisionLayer::DisruptorWave) | static_cast<int>(CollisionLayer::AllyProjectile)), static_cast<CollisionLayer>(
			static_cast<int>(CollisionLayer::Enemy) | static_cast<int>(CollisionLayer::EnemyProjectile)));
}
