#pragma once
#include "IProjectileHit.hpp"

class PawnPelletHit : public IProjectileHit
{
public:
    void Hit(bool& isAlive) override;
};
