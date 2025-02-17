#pragma once

#include "IEntitySetCollider.hpp"
#include <DirectXMath.h>

namespace DX = DirectX;

class EnemySetCollider : public IEntitySetCollider
{
public:
	Collider CreateCollider(DX::XMFLOAT2 position) override;
};