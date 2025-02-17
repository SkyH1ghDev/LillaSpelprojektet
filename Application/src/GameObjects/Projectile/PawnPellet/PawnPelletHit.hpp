#pragma once
#include "IProjectileHit.hpp"
#include <iostream>

class PawnPelletHit : public IProjectileHit
{
public:
    bool Hit() override;
};
