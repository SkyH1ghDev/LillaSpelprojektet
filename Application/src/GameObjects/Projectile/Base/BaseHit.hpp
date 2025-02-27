#pragma once
#include "IProjectileHit.hpp"

class BaseHit : public IProjectileHit
{
public:
    void Hit(bool& isAlive) override;
};
