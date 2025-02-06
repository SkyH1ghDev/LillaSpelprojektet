#pragma once
#include <iostream>

enum class EntityState {
    WalkUp,
    WalkDown,
    WalkRight,
    WalkLeft
};

class IEntityVisible
{
public:
	virtual void Visible(std::string& texture, EntityState entityState, float& layer, float& scale) = 0;
	virtual ~IEntityVisible() = default;
};