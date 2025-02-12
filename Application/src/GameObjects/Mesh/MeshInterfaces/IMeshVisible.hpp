#pragma once
#include <iostream>
#include <DirectXMath.h>
namespace DX = DirectX;

class IMeshVisible
{
public:
	virtual void Visible(std::string& texture, DX::XMFLOAT2 position, float& layer, float& scale) = 0;
	virtual void UpdateLayer(DX::XMFLOAT2 position, float& layer) = 0;
	virtual ~IMeshVisible() = default;
};