#pragma once

#include "IEntitySetCollider.hpp"
#include <DirectXMath.h>

namespace DX = DirectX;

class PlayerSetCollider : public IEntitySetCollider
{
public:
	Collider CreateCollider(DX::XMFLOAT2 position) override;
};