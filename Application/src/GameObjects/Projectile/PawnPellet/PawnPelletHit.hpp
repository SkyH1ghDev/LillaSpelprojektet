#pragma once
#include "IProjectileHit.hpp"

class PawnPelletHit : public IProjectileHit
{
public:
    void Hit(bool& isActive, bool& shouldRender, bool& isAlive) override;
};
