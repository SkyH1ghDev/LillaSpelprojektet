#include "PlayerAttackScript.hpp"

#include <SpEngine/Input/Input.hpp>
#include <SpEngine/Clock/Clock.hpp>

void PlayerAttackScript::OnStart()
{
	Input::GetKey(VK_LBUTTON)->Attach(std::static_pointer_cast<IObserver, Attack>(m_attack));
}

void PlayerAttackScript::Update()
{
	std::shared_ptr<Entity> player = std::static_pointer_cast<Entity>(m_gameObject.lock());

	DX::XMFLOAT2 pos = player->GetPosition();

	DX::XMFLOAT2 mousePos = DX::XMFLOAT2(Input::GetMousePositionX(), Input::GetMousePositionY());

	DX::XMFLOAT2 wandPos;

	DX::XMVECTOR playerToMouse = DX::XMVectorSubtract(DX::XMLoadFloat2(&mousePos), DX::XMLoadFloat2(&pos));
	DX::XMStoreFloat2(&wandPos, DX::XMVectorAdd(DX::XMVectorScale(DX::XMVector2Normalize(playerToMouse), 20), DX::XMLoadFloat2(&pos)));

	if (m_attackTimer >= 0)
		m_attackTimer -= Clock::GetDeltaTime();

	if (m_attack->GetAttack() && m_attackTimer <= 0)
	{
		player->PerformAttack(wandPos, DX::XMFLOAT2(DX::XMVectorGetX(DX::XMVector2Normalize(playerToMouse)), (DX::XMVectorGetY(DX::XMVector2Normalize(playerToMouse)))));
		m_attackTimer = 0.25f;
	}
}
