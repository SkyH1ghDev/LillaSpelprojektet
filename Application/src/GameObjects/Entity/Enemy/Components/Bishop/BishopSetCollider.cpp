#include "BishopSetCollider.hpp"

#include <SpEngine/Physics/Collider.hpp>

Collider BishopSetCollider::CreateCollider(DX::XMFLOAT2 position)
{
	return Collider(position, 6.0f, 3.0f, CollisionLayer::Enemy, static_cast<CollisionLayer>(
		static_cast<int>(CollisionLayer::AllyProjectile) | static_cast<int>(CollisionLayer::Player)));
}
