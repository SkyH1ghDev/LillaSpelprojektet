#pragma once
#include "IMeshVisible.hpp"
#include <DirectXMath.h>

namespace DX = DirectX;

class ObjectVisible : public IMeshVisible
{
public:
    void Visible(std::string& texture, DX::XMFLOAT2 position, float& layer, float& scale) override;
};