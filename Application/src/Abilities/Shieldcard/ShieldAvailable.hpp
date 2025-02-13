#pragma once
#include "ICardAvailability.hpp"
#include <iostream>

class ShieldAvailablility : public ICardAvailability
{
public:
    void Available() override;
};
