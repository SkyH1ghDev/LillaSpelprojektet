#include "PlayerController.hpp"

#include <SpEngine/Input/Input.hpp>
#include <SpEngine/Clock/Clock.hpp>

void PlayerController::OnStart()
{
	Input::GetKey('W')->Attach(std::static_pointer_cast<IObserver, MoveUp>(m_up));
	Input::GetKey('A')->Attach(std::static_pointer_cast<IObserver, MoveLeft>(m_left));
	Input::GetKey('S')->Attach(std::static_pointer_cast<IObserver, MoveDown>(m_down));
	Input::GetKey('D')->Attach(std::static_pointer_cast<IObserver, MoveRight>(m_right));
	Input::GetKey(VK_SPACE)->Attach(std::static_pointer_cast<IObserver, Dash>(m_dash));
	Input::GetKey(VK_LBUTTON)->Attach(std::static_pointer_cast<IObserver, Attack>(m_attack));
}

void PlayerController::Update()
{
	std::shared_ptr<Entity> player = std::static_pointer_cast<Entity>(m_gameObject.lock());
	player->PerformMove({ m_right->GetMoveDirection().x + m_left->GetMoveDirection().x,  m_up->GetMoveDirection().y + m_down->GetMoveDirection().y }, m_dash->IsDashing());


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

	if (m_up->GetMoveDirection().y == -1)
	{
		player->PerformVisible(EntityState::WalkUp);
	}
	else if (m_down->GetMoveDirection().y == 1)
	{
		player->PerformVisible(EntityState::WalkDown);
	}
	else if (m_right->GetMoveDirection().x == 1)
	{
		player->PerformVisible(EntityState::WalkRight);
	}
	else if (m_left->GetMoveDirection().x == -1)
	{
		player->PerformVisible(EntityState::WalkLeft);
	}

}
