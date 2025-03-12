#pragma once
#include "IProjectileHit.hpp"

class MagicMissileHit : public IProjectileHit
{
public:
    void Hit(bool& hasHit) override;
};
