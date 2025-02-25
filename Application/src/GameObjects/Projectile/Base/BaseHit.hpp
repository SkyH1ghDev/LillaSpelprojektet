#pragma once
#include "IProjectileHit.hpp"
#include <iostream>

class BaseHit : public IProjectileHit
{
public:
    void Hit(bool& isActive, bool& shouldRender, bool& isAlive) override;
};
