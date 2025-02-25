#pragma once

class IProjectileHit
{
public:
    virtual void Hit(bool& isActive, bool& shouldRender, bool& isAlive) = 0;
    virtual ~IProjectileHit() = default;
};
