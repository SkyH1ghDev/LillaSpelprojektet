#pragma once
#include "IProjectileHit.hpp"

class BaseHit : public IProjectileHit
{
public:
    void Hit(bool& isActive, bool& shouldRender, bool& isAlive) override;
};
