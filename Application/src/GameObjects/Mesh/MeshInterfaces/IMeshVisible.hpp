#pragma once
#include <iostream>

class IMeshVisible
{
public:
	virtual void Visible(std::string& texture) = 0;
	virtual ~IMeshVisible() = default;
};