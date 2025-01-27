#pragma once
#include "ITakeDamage.hpp"
#include <iostream>

class PlayerTakeDamage : public ITakeDamage
{
public:
    void TakeDamage() override;
};