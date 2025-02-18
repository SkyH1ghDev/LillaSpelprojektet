
class Effect
{
public:
	Effect(float lifeTime, float amount);
	~Effect() = default;
	bool Update(float gameTime);
	float GetValue();
private:
	float m_lifeTime;
	float m_amount;
};

inline Effect::Effect(float lifeTime, float amount)
{
	this->m_lifeTime = lifeTime;
	this->m_amount = amount;
}

/**
 * Updates lifetime of effect with given time value in seconds
 * @param gameTime float value measured in seconds
 * return true if m_lifeTime < 0, false if not
 */
inline bool Effect::Update(float gameTime)
{
	this->m_lifeTime -= gameTime;

	if (this->m_lifeTime < 0)
		return true;
	return false;
}

/*
 * Returns effect value
 * return float value
 */
inline float Effect::GetValue()
{
	return this->m_amount;
}