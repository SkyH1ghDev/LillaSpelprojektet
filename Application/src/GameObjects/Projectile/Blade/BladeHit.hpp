#pragma once
#include "IProjectileHit.hpp"

class BladeHit : public IProjectileHit
{
public:
    void Hit(bool& hasHit) override;
};
