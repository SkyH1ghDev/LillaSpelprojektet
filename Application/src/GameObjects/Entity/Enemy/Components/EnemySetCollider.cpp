#include "EnemySetCollider.hpp"

#include <SpEngine/Physics/Collider.hpp>

Collider EnemySetCollider::CreateCollider(DX::XMFLOAT2 position, float radius, float aspectRatio)
{
	return Collider(position, radius, aspectRatio);
}
