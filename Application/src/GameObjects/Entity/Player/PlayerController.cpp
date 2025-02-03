#include "PlayerController.hpp"

#include <SpEngine/Input/Input.hpp>

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

	std::cout << "(" << test.x << ", " << test.y << ")\n";
}
