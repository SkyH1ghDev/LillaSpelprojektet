#pragma once
class IEntityTakeDamage
{
public:
	virtual void TakeDamage(float & hp, float damage, bool& isAlive, bool& shouldRender, float& damageTimer, bool& iFrame) = 0;
	virtual void SetHealth(float& hp) = 0;

	virtual ~IEntityTakeDamage() = default;
};