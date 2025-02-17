#pragma once
#include "IProjectileHit.hpp"
#include <iostream>

class BishopBallHit : public IProjectileHit
{
public:
    bool Hit() override;
};
