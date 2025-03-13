#include "MagicMissileSetCollider.hpp"

#include <SpEngine/Physics/Collider.hpp>

Collider MagicMissileSetCollider::SetCollider(DX::XMFLOAT2 position)
{
	return Collider(position, 6.0f, CollisionLayer::AllyProjectile, CollisionLayer::Enemy);

}
