#pragma once

#include "IProjectileSetCollider.hpp"
#include <DirectXMath.h>

namespace DX = DirectX;

class BaseSetCollider : public IProjectileSetCollider
{
public:
	Collider SetCollider(DX::XMFLOAT2 position) override;
};