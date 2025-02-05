#pragma once
class IEntityTakeDamage
{
public:
	virtual void TakeDamage() = 0;
	virtual ~IEntityTakeDamage() = default;
};