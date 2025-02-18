#pragma once
class IEntityTakeDamage
{
public:
	virtual void TakeDamage(float & hp, float damage) = 0;
	virtual void SetHealth(float& hp) = 0;

	virtual ~IEntityTakeDamage() = default;
};