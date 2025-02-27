#pragma once
#include "IProjectileHit.hpp"
#include <iostream>

class DisruptorWaveHit : public IProjectileHit
{
public:
    void Hit(bool& isAlive) override;
};
