#include "PlayerController.hpp"

#include <SpEngine/Input/Input.hpp>
#include <SpEngine/Clock/Clock.hpp>

PlayerController::PlayerController(std::shared_ptr<Entity> player)
{
	this->m_player = player;
}

void PlayerController::OnStart()
{
	Input::GetKey('W')->Attach(std::static_pointer_cast<IObserver, MoveUp>(m_up));
	Input::GetKey('A')->Attach(std::static_pointer_cast<IObserver, MoveLeft>(m_left));
	Input::GetKey('S')->Attach(std::static_pointer_cast<IObserver, MoveDown>(m_down));
	Input::GetKey('D')->Attach(std::static_pointer_cast<IObserver, MoveRight>(m_right));
}

void PlayerController::Update()
{
	m_player->PerformMove({ m_right->GetMoveDirection().x + m_left->GetMoveDirection().x,  m_up->GetMoveDirection().y + m_down->GetMoveDirection().y });
}
