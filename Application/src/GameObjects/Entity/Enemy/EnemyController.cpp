#include "EnemyController.hpp"
#include "PlayerInfo.hpp"
#include <SpEngine/Input/Input.hpp>
#include <SpEngine/Clock/Clock.hpp>

void EnemyController::OnStart()
{
	
}

void EnemyController::Update()
{
	std::shared_ptr<Entity> enemy = std::static_pointer_cast<Entity>(m_gameObject.lock());
	DX::XMFLOAT2 enemyPos = enemy->GetPosition();
	DX::XMFLOAT2 playerPos = PlayerInfo::GetPosition();

	DX::XMVECTOR enemyVec = XMLoadFloat2(&enemyPos);
	DX::XMVECTOR playerVec = XMLoadFloat2(&playerPos);

	DX::XMVECTOR enemyToPlayerVec = DX::XMVectorSubtract(playerVec, enemyVec);

	DX::XMVECTOR directionVec = DX::XMVector3Normalize(enemyToPlayerVec);
	DX::XMFLOAT2 direction;
	XMStoreFloat2(&direction, directionVec);

	float distance = DX::XMVectorGetX(DX::XMVector3Length(enemyToPlayerVec));

	this->m_attackTimer += Clock::GetDeltaTime();

	// Only attack if enough time has passed
	if (distance < 300 && (this->m_attackTimer >= this->m_attackCooldown))
	{
		enemy->PerformAttack(enemyPos, direction);
		this->m_attackTimer = 0;
	}

}   
