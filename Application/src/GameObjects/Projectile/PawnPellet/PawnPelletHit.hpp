#pragma once
#include "IProjectileHit.hpp"
#include <iostream>

class PawnPelletHit : public IProjectileHit
{
public:
    void Hit(bool& isActive, bool& shouldRender, bool& isAlive) override;
};
