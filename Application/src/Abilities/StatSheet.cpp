#include "StatSheet.hpp"
#include <SpEngine/Clock/Clock.hpp>

float StatSheet::m_damage = 20.0f;
float StatSheet::m_moveSpeed = 200.0f;
float StatSheet::m_shotSpeed = 300.0f;
float StatSheet::m_shotDelay = 0.5f;
float StatSheet::m_shotLife = 0.5f;
int StatSheet::m_maxHealth = 5;
int StatSheet::m_maxMana = 3;
float StatSheet::m_currentHealth = 5;

std::vector<Effect> StatSheet::m_damageMod;
std::vector<Effect> StatSheet::m_moveSpeedMod;
std::vector<Effect> StatSheet::m_shotSpeedMod;
std::vector<Effect> StatSheet::m_shotLifeMod;
std::vector<Effect> StatSheet::m_shotDelayMod;

/**
  * Returns the damage value with effect added
  * return float value
  */
float StatSheet::GetDamage()
{
	float totalDamage = StatSheet::m_damage;
	for (size_t i = 0; i < StatSheet::m_damageMod.size(); i++)
		totalDamage += StatSheet::m_damageMod[i].GetValue();
	return totalDamage;
}

/**
  * Returns the Projectile Speed value with effect added
  * return float value
  */
float StatSheet::GetShotSpeed()
{
	float totalSpeed = StatSheet::m_shotSpeed;
	for (size_t i = 0; i < StatSheet::m_shotSpeedMod.size(); i++)
		totalSpeed += StatSheet::m_shotSpeedMod[i].GetValue();
	return totalSpeed;
}

/**
  * Returns the movement speed value
  * return float value
  */
float StatSheet::GetMoveSpeed()
{
	float totalSpeed = StatSheet::m_moveSpeed;
	for (size_t i = 0; i < StatSheet::m_moveSpeedMod.size(); i++)
		totalSpeed += StatSheet::m_moveSpeedMod[i].GetValue();
	return totalSpeed;
}

/**
  * Returns the shot delay value (in seconds)
  * return float value
  */
float StatSheet::GetShotDelay()
{
	float totalTime = StatSheet::m_shotDelay;
	for (size_t i = 0; i < StatSheet::m_shotDelayMod.size(); i++)
		totalTime += StatSheet::m_shotDelayMod[i].GetValue();
	return totalTime;
}

/**
  * Returns the shot life value (in seconds)
  * return float value
  */
float StatSheet::GetShotLife()
{
	float totalTime = StatSheet::m_shotLife;
	for (size_t i = 0; i < StatSheet::m_shotLifeMod.size(); i++)
		totalTime += StatSheet::m_shotLifeMod[i].GetValue();
	return totalTime;
}

/**
  * Creates a buff object and adds it to a vector corresponding to stat type
  * MaxHealth and MaxMana cannot be affected
  * @param type Enum for type of stat
  * @param amount Strength of effect, note that shotDelay benefits from negative values
  */
void StatSheet::CreateEffect(StatType type, float lifeTime, float amount)
{
	switch (type)
	{
	case Damage:
		StatSheet::m_damageMod.push_back(Effect(lifeTime, amount));
		break;
	case ShotSpeed:
		StatSheet::m_shotSpeedMod.push_back(Effect(lifeTime, amount));
		break;
	case MoveSpeed:
		StatSheet::m_moveSpeedMod.push_back(Effect(lifeTime, amount));
		break;
	case ShotDelay:
		StatSheet::m_shotDelayMod.push_back(Effect(lifeTime, amount));
		break;
	case ShotLife:
		StatSheet::m_shotLifeMod.push_back(Effect(lifeTime, amount));
		break;
	default:
		break;
	}
}

/**
  * Updates all stored buff objects and removes effects with ended timers
  */
void StatSheet::UpdateEffects()
{
	float gameTime = Clock::GetDeltaTime();
	for (int i = (int)StatSheet::m_damageMod.size() - 1; i >= 0; i--)
		if (StatSheet::m_damageMod[i].Update(gameTime))
			StatSheet::m_damageMod.erase(StatSheet::m_damageMod.begin() + i);

	for (int i = (int)StatSheet::m_moveSpeedMod.size() - 1; i >= 0; i--)
		if (StatSheet::m_moveSpeedMod[i].Update(gameTime))
			StatSheet::m_moveSpeedMod.erase(StatSheet::m_moveSpeedMod.begin() + i);

	for (int i = (int)StatSheet::m_shotDelayMod.size() - 1; i >= 0; i--)
		if (StatSheet::m_shotDelayMod[i].Update(gameTime))
			StatSheet::m_shotDelayMod.erase(StatSheet::m_shotDelayMod.begin() + i);

	for (int i = (int)StatSheet::m_shotLifeMod.size() - 1; i >= 0; i--)
		if (StatSheet::m_shotLifeMod[i].Update(gameTime))
			StatSheet::m_shotLifeMod.erase(StatSheet::m_shotLifeMod.begin() + i);

	for (int i = (int)StatSheet::m_shotSpeedMod.size() - 1; i >= 0; i--)
		if (StatSheet::m_shotSpeedMod[i].Update(gameTime))
			StatSheet::m_shotSpeedMod.erase(StatSheet::m_shotSpeedMod.begin() + i);
}