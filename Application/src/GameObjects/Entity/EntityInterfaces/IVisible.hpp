#pragma once
#include <iostream>
class IVisible
{
public:
	virtual void Visible(std::string& texture) = 0;
	virtual ~IVisible() = default;
};