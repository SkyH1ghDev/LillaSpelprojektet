#pragma once
#include "ICardActivated.hpp"
#include <iostream>

class ShieldActivated : public ICardActivated
{
public:
    void Activate() override;
};