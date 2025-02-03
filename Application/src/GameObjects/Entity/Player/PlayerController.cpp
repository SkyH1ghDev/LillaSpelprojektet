#include "PlayerController.hpp"

#include <SpEngine/Input/Keyboard.hpp>



PlayerController::PlayerController(std::shared_ptr<Entity> player)
{
	this->m_player = player;
}

void PlayerController::OnStart()
{
	Keyboard::GetKey('w')->Attach(std::static_pointer_cast<IObserver, ForwardAction>(m_forward));
	Keyboard::GetKey('a')->Attach(std::static_pointer_cast<IObserver, LeftAction>(m_left));
	Keyboard::GetKey('s')->Attach(std::static_pointer_cast<IObserver, BackAction>(m_back));
	Keyboard::GetKey('d')->Attach(std::static_pointer_cast<IObserver, RightAction>(m_right));
}

void PlayerController::Update()
{
	
}
