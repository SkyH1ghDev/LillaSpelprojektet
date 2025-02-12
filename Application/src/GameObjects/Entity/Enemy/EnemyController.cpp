#include "EnemyController.hpp"

#include <SpEngine/Input/Input.hpp>
#include <SpEngine/Clock/Clock.hpp>

EnemyController::EnemyController(std::shared_ptr<IGameObject> player)
	: m_player(player) {
}

void EnemyController::OnStart()
{
	
}

void EnemyController::Update()
{
	std::shared_ptr<Entity> enemy = std::static_pointer_cast<Entity>(m_gameObject.lock());
	DX::XMFLOAT2 enemyPos = enemy->GetPosition();
	DX::XMFLOAT2 playerPos = this->m_player->GetPosition();

	DX::XMVECTOR enemyVec = XMLoadFloat2(&enemyPos);
	DX::XMVECTOR playerVec = XMLoadFloat2(&playerPos);

	DX::XMVECTOR enemyToPlayerVec = DX::XMVectorSubtract(playerVec, enemyVec);

	DX::XMVECTOR directionVec = DX::XMVector3Normalize(enemyToPlayerVec);
	DX::XMFLOAT2 direction;
	XMStoreFloat2(&direction, directionVec);

	float distance = DX::XMVectorGetX(DX::XMVector3Length(enemyToPlayerVec));

	if (distance < 200)
	{
		enemy->PerformAttack(enemyPos, direction);
	}

}
