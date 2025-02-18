#include <vector>
#include "Effect.hpp"
#include "SpEngine/Clock/Clock.hpp"

enum StatType
{
	Damage,
	ShotSpeed,
	MoveSpeed,
	ShotDelay,
	ShotLife
};

class StatSheet
{
public:
	StatSheet() = default;
	~StatSheet() = default;

	static void SetBaseDamage(float amount);
	static void SetBaseMoveSpeed(float amount);
	static void SetBaseShotSpeed(float amount);
	static void SetBaseShotLife(float amount);
	static void SetBaseShotDelay(float amount);

	static void SetMaxHealth(int amount);
	static void SetMaxMana(int amount);

	static float GetDamage();
	static float GetMoveSpeed();
	static float GetShotLife();
	static float GetShotSpeed();
	static float GetShotDelay();

	static int GetMaxHealth();
	static int GetMaxMana();

	static void CreateEffect(StatType type, float lifeTime, float amount);
	static void UpdateEffects();
private:
	static float m_damage;
	static float m_moveSpeed;
	static float m_shotSpeed;
	static float m_shotDelay;
	static float m_shotLife;
	static int m_maxHealth;
	static int m_maxMana;

	static std::vector<Effect> m_damageMod;
	static std::vector<Effect> m_moveSpeedMod;
	static std::vector<Effect> m_shotSpeedMod;
	static std::vector<Effect> m_shotLifeMod;
	static std::vector<Effect> m_shotDelayMod;
};

/**
  * Sets the base Damage value (before calculations)
  * @param amount Value to set to stat
  */
inline void StatSheet::SetBaseDamage(float amount)
{
	StatSheet::m_damage = amount;
}

/**
  * Sets the base ShotSpeed value (before calculations)
  * @param amount Value to set to stat
  */
inline void StatSheet::SetBaseShotSpeed(float amount)
{
	StatSheet::m_shotDelay = amount;
}

/**
  * Sets the base Move Speed value (before calculations)
  * @param amount Value to set to stat
  */
inline void StatSheet::SetBaseMoveSpeed(float amount)
{
	StatSheet::m_moveSpeed = amount;
}

/**
  * Sets the base Shot Delay value (before calculations)
  * @param amount Value to set to stat measured in seconds
  */
inline void StatSheet::SetBaseShotDelay(float amount)
{
	StatSheet::m_shotDelay = amount;
}

/**
  * Sets the base Shot Delay value (before calculations)
  * @param amount Value to set to stat measured in seconds
  */
inline void StatSheet::SetBaseShotLife(float amount)
{
	StatSheet::m_shotLife = amount;
}

/**
  * Sets the Max Health value
  * @param amount Value to set to stat
  */
inline void StatSheet::SetMaxHealth(int amount)
{
	StatSheet::m_maxHealth = amount;
}

/**
  * Sets the Max Mana value
  * @param amount Value to set to stat
  */
inline void StatSheet::SetMaxMana(int amount)
{
	StatSheet::m_maxMana = amount;
}

/**
  * Returns the Max Health value
  * return int value
  */
inline int StatSheet::GetMaxHealth()
{
	return StatSheet::m_maxHealth;
}

/**
  * Returns the Max Mana value
  * return int value
  */
inline int StatSheet::GetMaxMana()
{
	return StatSheet::m_maxMana;
}