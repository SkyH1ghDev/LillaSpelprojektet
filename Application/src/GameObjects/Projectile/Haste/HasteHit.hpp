#pragma once
#include "IProjectileHit.hpp"
#include <iostream>

class HasteHit : public IProjectileHit
{
public:
    void Hit(bool& hasHit) override;
};
