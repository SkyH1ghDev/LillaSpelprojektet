#pragma once
#include <string>
enum class ProjectileState {
    Active,
    Inactive
};

class IProjectileVisible
{
public:
    virtual void Visible(std::string& texture, ProjectileState entityState, float& layer, float& scale) = 0;
    virtual ~IProjectileVisible() = default;
};