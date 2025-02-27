#pragma once

class IProjectileHit
{
public:
    virtual void Hit(bool& isAlive) = 0;
    virtual ~IProjectileHit() = default;
};
