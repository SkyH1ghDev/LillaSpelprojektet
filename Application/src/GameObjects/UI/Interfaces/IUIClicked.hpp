#pragma once
class IUIClicked
{
public:
	virtual void Clicked(int value) = 0;

	virtual ~IUIClicked() = default;
};