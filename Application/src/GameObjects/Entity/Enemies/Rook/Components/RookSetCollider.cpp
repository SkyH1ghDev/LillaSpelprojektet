<<<<<<<< HEAD:Application/src/GameObjects/Entity/Enemy/Components/Bishop/BishopSetCollider.cpp
#include "BishopSetCollider.hpp"

#include <SpEngine/Physics/Collider.hpp>

Collider BishopSetCollider::CreateCollider(DX::XMFLOAT2 position)
========
#include "RookSetCollider.hpp"

#include <SpEngine/Physics/Collider.hpp>

Collider RookSetCollider::CreateCollider(DX::XMFLOAT2 position)
>>>>>>>> main:Application/src/GameObjects/Entity/Enemies/Rook/Components/RookSetCollider.cpp
{
	return Collider(position, 10.0f, CollisionLayer::Enemy, static_cast<CollisionLayer>(
		static_cast<int>(CollisionLayer::AllyProjectile) | static_cast<int>(CollisionLayer::Player)));
}
