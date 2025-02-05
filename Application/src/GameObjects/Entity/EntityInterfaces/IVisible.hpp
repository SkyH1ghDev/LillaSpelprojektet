#pragma once
#include <iostream>

enum class EntityState {
    WalkUp,
    WalkDown,
    WalkRight,
    WalkLeft
};

class IVisible
{
public:
	virtual void Visible(std::string& texture, EntityState entityState) = 0;
	virtual ~IVisible() = default;
};