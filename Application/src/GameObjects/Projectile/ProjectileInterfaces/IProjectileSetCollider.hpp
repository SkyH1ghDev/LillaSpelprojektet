#pragma once

#include <DirectXMath.h>
#include <SpEngine/Physics/Collider.hpp>

namespace DX = DirectX;

class IProjectileSetCollider
{
public:
	virtual Collider SetCollider(DX::XMFLOAT2 position) = 0;
	virtual ~IProjectileSetCollider() = default;
};