#include "PlayerController.hpp"

#include <SpEngine/Input/Input.hpp>
#include <SpEngine/Clock/Clock.hpp>
#include "StatSheet.hpp"

void PlayerController::OnStart()
{
	Input::GetKey('W')->Attach(std::static_pointer_cast<IObserver, MoveUp>(m_up));
	Input::GetKey('A')->Attach(std::static_pointer_cast<IObserver, MoveLeft>(m_left));
	Input::GetKey('S')->Attach(std::static_pointer_cast<IObserver, MoveDown>(m_down));
	Input::GetKey('D')->Attach(std::static_pointer_cast<IObserver, MoveRight>(m_right));

	Input::GetKey(VK_SPACE)->Attach(std::static_pointer_cast<IObserver, Dash>(m_dash));
}

void PlayerController::Update()
{
	StatSheet::UpdateEffects();

	DX::XMFLOAT2 movementDirection =
	{
		m_right->GetMoveDirection().x + m_left->GetMoveDirection().x,
		m_up->GetMoveDirection().y + m_down->GetMoveDirection().y
	};
	std::shared_ptr<Entity> player = std::static_pointer_cast<Entity>(m_gameObject.lock());
	player->PerformDash(movementDirection, m_dash->IsDashing());
	player->PerformMove(movementDirection);
}
