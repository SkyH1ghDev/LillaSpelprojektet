#pragma once
#include <iostream>

class BishopTakeDamage : public IEntityTakeDamage
{
public:
    void TakeDamage(float& hp, float damage, bool& isActive, bool& shouldRender, float& iFrameTimer) override;
    void SetHealth(float& hp) override;
};