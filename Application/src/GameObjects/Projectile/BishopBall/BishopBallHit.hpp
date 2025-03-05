#pragma once
#include "IProjectileHit.hpp"

class BishopBallHit : public IProjectileHit
{
public:
    void Hit(bool& hasHit) override;
};
