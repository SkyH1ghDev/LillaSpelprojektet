#pragma once
#include "IProjectileHit.hpp"
#include <iostream>

class LongshotHit : public IProjectileHit
{
public:
    void Hit(bool& hasHit) override;
};
