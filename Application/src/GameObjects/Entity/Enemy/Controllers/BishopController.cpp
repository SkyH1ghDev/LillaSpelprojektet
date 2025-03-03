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


	// Only attack if enough time has passed
	if (distance < 700)
	{
		bishop->PerformAttack(bishopPos, direction);
	}

	//Update collider
	std::shared_ptr<Collider> temp = bishop->GetCollider();
	temp->UpdatePosition({ bishopPos.x, bishopPos.y - 5});
	bishop->SetCollider(temp);
}   
