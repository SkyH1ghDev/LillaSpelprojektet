#pragma once
#include <string>
#include <DirectXMath.h>

namespace DX = DirectX;

enum class EntityState {
    Base,
    WalkUp,
    WalkDown,
    WalkRight,
    WalkLeft,
    Spawning,
    TakingDamage,
    Dying,
    Dead,
    Dashing
};

class IEntityVisible
{
public:
	virtual void Visible(std::string& texture, DX::XMFLOAT2 position, EntityState entityState, float& layer, float& scale) = 0;
    virtual void UpdateLayer(DX::XMFLOAT2 position, float& layer) = 0;

	virtual ~IEntityVisible() = default;

};