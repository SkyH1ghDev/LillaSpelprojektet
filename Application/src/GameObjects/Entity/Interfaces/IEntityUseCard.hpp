#pragma once
class IEntityUseCard
{
public:
	virtual void UseCard() = 0;
	virtual ~IEntityUseCard() = default;
};