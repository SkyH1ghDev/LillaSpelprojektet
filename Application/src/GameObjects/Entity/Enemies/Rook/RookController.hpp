#pragma once
#include "Entity.hpp"

#include <SpEngine/Assets/Game/IScript.hpp>
#include <vector> // Include vector for patrol points

class RookController : public IScript
{
public:
	RookController() = default;
	~RookController() override = default;
	DX::XMFLOAT2 GetRandomDirection();
	float GetRandomDirectionChangeTime();

	void OnStart() override;
	void Update() override;

private:
	float m_attackCooldown;
	float m_attackTimer;
	int m_patrolIndex;
	bool m_isCharging;
	float m_chargeTimer;
	std::vector<DX::XMFLOAT2> patrolPoints;
	float m_patrolTime;
	DX::XMFLOAT2 m_currentPatrolDirection;
	float m_nextDirectionChangeTime;
};
