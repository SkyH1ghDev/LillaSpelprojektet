#pragma once
#include "IProjectileHit.hpp"

class IceBeamHit : public IProjectileHit
{
public:
    void Hit(bool& hasHit) override;
};
