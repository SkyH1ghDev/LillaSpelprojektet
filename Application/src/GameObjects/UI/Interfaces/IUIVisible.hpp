#pragma once
#include <string>
#include <DirectXMath.h>

class IUIVisible
{
public:
	virtual void Visible(std::string& texture, float& layer, float& scale, DirectX::XMFLOAT2& position) = 0;
	virtual ~IUIVisible() = default;
};