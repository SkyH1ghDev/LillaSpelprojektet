#pragma once
class IUIClicked
{
public:
	virtual void Clicked() = 0;
	virtual ~IUIClicked() = default;
};