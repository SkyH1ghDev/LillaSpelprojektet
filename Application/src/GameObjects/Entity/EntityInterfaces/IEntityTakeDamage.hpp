#pragma once
class IEntityTakeDamage
{
public:
	virtual void TakeDamage(float & hp, float damage, bool& isActive, bool& shouldRender) = 0;
	virtual void SetHealth(float& hp) = 0;

	virtual ~IEntityTakeDamage() = default;
};