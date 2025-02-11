#pragma once
class ICardActivated
{
public:
	virtual void Activate() = 0;
	virtual ~ICardActivated() = default;
};