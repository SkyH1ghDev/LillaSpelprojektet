#pragma once
#include "IProjectileHit.hpp"
#include <iostream>

class HealHit : public IProjectileHit
{
public:
    void Hit(bool& hasHit) override;
};
