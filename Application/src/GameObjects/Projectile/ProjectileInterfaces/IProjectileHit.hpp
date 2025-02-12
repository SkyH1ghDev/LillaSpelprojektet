#pragma once

class IProjectileHit
{
public:
    virtual bool Hit() = 0;
    virtual ~IProjectileHit() = default;
};
