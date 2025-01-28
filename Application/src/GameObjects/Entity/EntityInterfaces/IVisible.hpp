#pragma once
class IVisible
{
public:
	virtual void Visible() = 0;
	virtual ~IVisible() = default;
};