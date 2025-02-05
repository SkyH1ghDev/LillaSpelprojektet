#include "PlayerController.hpp"

#include <SpEngine/Input/Input.hpp>
#include <SpEngine/Clock/Clock.hpp>

void PlayerController::OnStart()
{
	Input::GetKey('W')->Attach(std::static_pointer_cast<IObserver, MoveUp>(m_up));
	Input::GetKey('A')->Attach(std::static_pointer_cast<IObserver, MoveLeft>(m_left));
	Input::GetKey('S')->Attach(std::static_pointer_cast<IObserver, MoveDown>(m_down));
	Input::GetKey('D')->Attach(std::static_pointer_cast<IObserver, MoveRight>(m_right));
}

void PlayerController::Update()
{
	std::weak_ptr<Entity> player = std::static_pointer_cast<Entity>(m_GameObject.lock());
	player.lock()->PerformMove({ m_right->GetMoveDirection().x + m_left->GetMoveDirection().x,  m_up->GetMoveDirection().y + m_down->GetMoveDirection().y });

	if (m_up->GetMoveDirection().y == -1)
	{
		m_player->PerformVisible(EntityState::WalkUp);
	}
	else if (m_down->GetMoveDirection().y == 1)
	{
		m_player->PerformVisible(EntityState::WalkDown);
	}
	else if (m_right->GetMoveDirection().x == 1)
	{
		m_player->PerformVisible(EntityState::WalkRight);
	}
	else if (m_left->GetMoveDirection().x == -1)
	{
		m_player->PerformVisible(EntityState::WalkLeft);
	}
}
