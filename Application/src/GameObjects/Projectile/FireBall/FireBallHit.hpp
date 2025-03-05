#pragma once
#include "IProjectileHit.hpp"

class FireBallHit : public IProjectileHit
{
public:
    void Hit(bool& hasHit) override;
};
