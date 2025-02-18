#pragma once
#include "IProjectileHit.hpp"
#include <iostream>

class BishopBallHit : public IProjectileHit
{
public:
    void Hit(bool& isActive, bool& shouldRender) override;
};
