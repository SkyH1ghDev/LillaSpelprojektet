#pragma once
#include <DirectXMath.h>

namespace DX = DirectX;

class IEntityAttack
{
public:
	virtual void Attack(DX::XMFLOAT2 position, DX::XMFLOAT2 direction) = 0;
	virtual void Reset() = 0;
	virtual ~IEntityAttack() = default;
};