#pragma once
class IGameObject
{

public:

    IGameObject() = default;
	virtual ~IGameObject() { }
    IGameObject(const IGameObject& other) = default;
    IGameObject& operator=(const IGameObject& other) = default;
    IGameObject(IGameObject&& other) noexcept = default;
    IGameObject& operator=(IGameObject&& other) noexcept = default;


	virtual void Update() = 0;
	virtual void OnStart() = 0;

	bool IsActive() const;
	void SetActive(bool activeState);

private:
	bool m_isActive = true;
};

inline bool IGameObject::IsActive() const
{
	return m_isActive;
}

inline void IGameObject::SetActive(bool activeState)
{
	m_isActive = activeState;
}
