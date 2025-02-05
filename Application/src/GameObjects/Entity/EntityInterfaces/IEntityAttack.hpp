#pragma once
class IEntityAttack
{
public:
	virtual void Attack() = 0;
	virtual ~IEntityAttack() = default;
};