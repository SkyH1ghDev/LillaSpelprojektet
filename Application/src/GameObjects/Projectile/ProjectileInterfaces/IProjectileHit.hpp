#pragma once

class IProjectileHit
{
public:
    virtual void Hit() = 0;
    virtual ~IProjectileHit() = default;
};
