#pragma once


#include <d3d11.h>
#include <DirectXMath.h>

namespace DX = DirectX;

class ICardActivated
{
public:
	virtual void Activate(const DX::XMFLOAT2& position, const DX::XMFLOAT2& Target) = 0;
	virtual ~ICardActivated() = default;
};