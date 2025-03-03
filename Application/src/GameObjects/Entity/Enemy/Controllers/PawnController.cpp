#include "PawnController.hpp"
#include "PlayerInfo.hpp"
#include <SpEngine/Clock/Clock.hpp>

void PawnController::OnStart()
{
	
}

void PawnController::Update()
{
	std::shared_ptr<Entity> pawn = std::static_pointer_cast<Entity>(m_gameObject.lock());
	DX::XMFLOAT2 pawnPos = pawn->GetPosition();
	DX::XMFLOAT2 playerPos = PlayerInfo::GetPosition();

	DX::XMVECTOR bishopVec = XMLoadFloat2(&pawnPos);
	DX::XMVECTOR playerVec = XMLoadFloat2(&playerPos);

	DX::XMVECTOR pawnToPlayerVec = DX::XMVectorSubtract(playerVec, bishopVec);

	DX::XMVECTOR directionVec = DX::XMVector3Normalize(pawnToPlayerVec);
	DX::XMFLOAT2 direction;
	XMStoreFloat2(&direction, directionVec);

	float distance = DX::XMVectorGetX(DX::XMVector3Length(pawnToPlayerVec));
	

	// Only attack if enough time has passed
	if (distance < 200)
	{
		pawn->PerformAttack(pawnPos, direction);
	}

	DX::XMFLOAT2 moveDirection = {};
	if (std::abs(direction.x) == 0 && std::abs(direction.y) == 0)
	{
		moveDirection = { 0, 0};
	}
	
	else if (std::abs(direction.x) > std::abs(direction.y))
	{
		moveDirection = direction.x > 0 ? DX::XMFLOAT2(1, 0) : DX::XMFLOAT2(-1, 0);
	}
	
	else if (std::abs(direction.x) <= std::abs(direction.y))
	{
		moveDirection = direction.y > 0 ? DX::XMFLOAT2(0, 1) : DX::XMFLOAT2(0, -1);
	}

	pawn->PerformMove(moveDirection, false);


}   
