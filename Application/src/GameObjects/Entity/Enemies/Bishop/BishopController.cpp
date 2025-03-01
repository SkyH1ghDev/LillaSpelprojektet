#include "BishopController.hpp"
#include "PlayerInfo.hpp"
#include <SpEngine/Input/Input.hpp>
#include <SpEngine/Clock/Clock.hpp>

void BishopController::OnStart()
{
	
}

void BishopController::Update()
{
	std::shared_ptr<Entity> bishop = std::static_pointer_cast<Entity>(m_gameObject.lock());
	DX::XMFLOAT2 bishopPos = bishop->GetPosition();
	DX::XMFLOAT2 playerPos = PlayerInfo::GetPosition();

	DX::XMVECTOR bishopVec = XMLoadFloat2(&bishopPos);
	DX::XMVECTOR playerVec = XMLoadFloat2(&playerPos);

	DX::XMVECTOR bishopToPlayerVec = DX::XMVectorSubtract(playerVec, bishopVec);

	DX::XMVECTOR directionVec = DX::XMVector3Normalize(bishopToPlayerVec);
	DX::XMFLOAT2 direction;
	XMStoreFloat2(&direction, directionVec);

	float distance = DX::XMVectorGetX(DX::XMVector3Length(bishopToPlayerVec));

	this->m_attackTimer += Clock::GetDeltaTime();

	// Only attack if enough time has passed
	if (distance < 300 && (this->m_attackTimer >= this->m_attackCooldown))
	{
		bishop->PerformAttack(bishopPos, direction);
		this->m_attackTimer = 0;
	}

}   
