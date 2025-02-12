#pragma once
#include <string>

class IUIVisible
{
public:
	virtual void Visible(std::string& texture, float& layer, float& scale) = 0;
	virtual ~IUIVisible() = default;
};