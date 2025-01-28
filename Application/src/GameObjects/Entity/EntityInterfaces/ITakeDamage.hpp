#pragma once
class ITakeDamage
{
public:
	virtual void TakeDamage() = 0;
	virtual ~ITakeDamage() = default;
};