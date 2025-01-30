#pragma once
#include <d3d11.h>
#include <DirectXMath.h>
namespace DX = DirectX;
class IMove {
public:
    virtual void Move(DX::XMFLOAT2& position) = 0; // Accept position as a reference
    virtual ~IMove() = default;
};