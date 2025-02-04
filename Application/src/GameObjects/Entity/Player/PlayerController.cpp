#include "PlayerController.hpp"

#include <SpEngine/Input/Input.hpp>

PlayerController::PlayerController(std::shared_ptr<Entity> player)
{
	this->m_player = player;
}

void PlayerController::OnStart()
{
	Input::GetKey('w')->Attach(std::static_pointer_cast<IObserver, MoveUp>(m_up));
	Input::GetKey('a')->Attach(std::static_pointer_cast<IObserver, MoveLeft>(m_left));
	Input::GetKey('s')->Attach(std::static_pointer_cast<IObserver, MoveDown>(m_down));
	Input::GetKey('d')->Attach(std::static_pointer_cast<IObserver, MoveRight>(m_right));
}

void PlayerController::Update()
{
	DX::XMVECTOR finalMoveDirection = DX::XMVector2Normalize(DX::XMVectorAdd(DX::XMVectorAdd(m_up->GetMoveDirection(), m_left->GetMoveDirection()), DX::XMVectorAdd( m_down->GetMoveDirection(), m_right->GetMoveDirection())));

	DX::XMFLOAT2 test;
	DX::XMStoreFloat2(&test, finalMoveDirection);

	this->m_player->PerformMove(test);
}
