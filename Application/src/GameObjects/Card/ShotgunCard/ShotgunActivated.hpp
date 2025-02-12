#pragma once
#include "ICardActivated.hpp"
#include <iostream>

class ShotgunActivated : public ICardActivated
{
public:
    void Activate(const DX::XMFLOAT2& position, const DX::XMFLOAT2& Target) override;
};
