#include "PlayerController.hpp"

#include <SpEngine/Input/Keyboard.hpp>

#include <SpEngine/Dev/Pattern/Observer/IObserver.hpp>

void PlayerController::OnStart() 
{
	Keyboard::GetKey('w')->Attach(std::static_pointer_cast<IObserver, ForwardAction>(m_forward));
	Keyboard::GetKey('a')->Attach(std::static_pointer_cast<IObserver, LeftAction>(m_left));
	Keyboard::GetKey('d')->Attach(std::static_pointer_cast<IObserver, RightAction>(m_right));
	Keyboard::GetKey('s')->Attach(std::static_pointer_cast<IObserver, BackAction>(m_back));
}

void PlayerController::Update()
{
	
}