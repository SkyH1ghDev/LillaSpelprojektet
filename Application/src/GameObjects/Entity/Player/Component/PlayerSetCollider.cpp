#include "PlayerSetCollider.hpp"

#include <SpEngine/Physics/Collider.hpp>

Collider PlayerSetCollider::CreateCollider(DX::XMFLOAT2 position, float radius, float aspectRatio)
{
	return Collider(position, radius, aspectRatio);
}
