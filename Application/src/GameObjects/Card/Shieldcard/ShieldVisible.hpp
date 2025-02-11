#pragma once
#include "ICardVisible.hpp"
#include <iostream>

class ShieldVisible : public ICardVisible
{
public:
    void Visible(std::string& texture, CardState cardState, float& layer, float& scale) override;
};