#pragma once
#include "IEntityTakeDamage.hpp"
#include <iostream>

class PlayerTakeDamage : public IEntityTakeDamage
{
public:
    void TakeDamage() override;
};