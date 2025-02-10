#pragma once
#include <iostream>

class IMeshVisible
{
public:
	virtual void Visible(std::string& texture, float& layer, float& scale) = 0;
	virtual ~IMeshVisible() = default;
};