#pragma once
class IClicked
{
public:
	virtual void Clicked() = 0;
	virtual ~IClicked() = default;
};