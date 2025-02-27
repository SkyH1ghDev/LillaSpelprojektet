#include "DisruptorWaveSetCollider.hpp"

#include <SpEngine/Physics/Collider.hpp>

Collider DisruptorWaveSetCollider::SetCollider(DX::XMFLOAT2 position)
{
	return Collider(position, 1.0f, CollisionLayer::DisruptorWave, CollisionLayer::EnemyProjectile);
}
