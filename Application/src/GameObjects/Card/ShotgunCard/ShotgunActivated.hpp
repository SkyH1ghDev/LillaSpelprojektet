#pragma once
#include "ICardActivated.hpp"
#include <iostream>

class ShotgunActivated : public ICardActivated
{
public:
    void Activate() override;
};
