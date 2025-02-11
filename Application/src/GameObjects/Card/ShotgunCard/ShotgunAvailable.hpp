#pragma once
#include "ICardAvailability.hpp"
#include <iostream>

class ShotgunAvailable : public ICardAvailability
{
public:
    void Available() override;
};