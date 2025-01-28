#pragma once
class IUseCard
{
public:
	virtual void UseCard() = 0;
	virtual ~IUseCard() = default;
};