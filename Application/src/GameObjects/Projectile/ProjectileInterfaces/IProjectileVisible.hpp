#pragma once
#include <string>
#include <DirectXMath.h>
namespace DX = DirectX;

enum class ProjectileState {
    Active,
    Inactive,
    Exploding,
};

class IProjectileVisible
{
public:
    virtual void Visible(std::string& texture, DX::XMFLOAT2 position, ProjectileState entityState, float& layer, float& scale, bool& hasDeathAnimation) = 0;
    virtual void UpdateLayer(DX::XMFLOAT2 position, float& layer) = 0;
    virtual ~IProjectileVisible() = default;
};