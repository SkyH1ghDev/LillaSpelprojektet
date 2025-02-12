#pragma once
#include <string>
#include <DirectXMath.h>

namespace DX = DirectX;

enum class EntityState {
    WalkUp,
    WalkDown,
    WalkRight,
    WalkLeft
};

class IEntityVisible
{
public:
	virtual void Visible(std::string& texture, DX::XMFLOAT2 position, EntityState entityState, float& layer, float& scale) = 0;
	virtual ~IEntityVisible() = default;
};