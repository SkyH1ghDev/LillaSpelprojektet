#pragma once
#include "IProjectileHit.hpp"
#include <iostream>

class SniperBulletHit : public IProjectileHit
{
public:
    void Hit(bool& hasHit) override;
};
