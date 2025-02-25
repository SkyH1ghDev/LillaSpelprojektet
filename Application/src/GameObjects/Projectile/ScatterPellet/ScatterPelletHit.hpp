#pragma once
#include "IProjectileHit.hpp"
#include <iostream>

class ScatterPelletHit : public IProjectileHit
{
public:
    void Hit(bool& isActive, bool& shouldRender) override;
};
