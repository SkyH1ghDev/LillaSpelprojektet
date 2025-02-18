#pragma once

class IProjectileHit
{
public:
    virtual void Hit(bool& isActive, bool& shouldRender) = 0;
    virtual ~IProjectileHit() = default;
};
