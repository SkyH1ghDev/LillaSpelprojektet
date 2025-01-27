#pragma once
class IAttack
{
public:
	virtual void Attack() = 0;
	virtual ~IAttack() = default;
};