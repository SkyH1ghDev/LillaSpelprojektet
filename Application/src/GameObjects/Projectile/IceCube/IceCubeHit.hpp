#pragma once
#include "IProjectileHit.hpp"

class IceCubeHit : public IProjectileHit
{
public:
    void Hit(bool& hasHit) override;
};
