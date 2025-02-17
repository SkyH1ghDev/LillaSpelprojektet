#pragma once

#include <DirectXMath.h>
#include <SpEngine/Physics/Collider.hpp>

namespace DX = DirectX;

class IEntitySetCollider
{
public:
	virtual Collider CreateCollider(DX::XMFLOAT2 position) = 0;
	virtual ~IEntitySetCollider() = default;
};