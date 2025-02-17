#pragma once
#include "Wand.hpp"

WandScript::WandScript(std::shared_ptr<IGameObject> player)
{
	this->player = player;
}

void WandScript::OnStart()
{
	
}

void WandScript::Update()
{
	std::shared_ptr<Mesh> wand = std::static_pointer_cast<Mesh>(m_gameObject.lock());
	DX::XMFLOAT2 zeroAngle = DX::XMFLOAT2(1, 0);

	DX::XMFLOAT2 wandPos;
	DX::XMFLOAT2 pos = this->player->GetPosition();

	DX::XMFLOAT2 mousePos = DX::XMFLOAT2(Input::GetMousePositionX(), Input::GetMousePositionY());

	DX::XMVECTOR playerToMouse = DX::XMVectorSubtract(DX::XMLoadFloat2(&mousePos), DX::XMLoadFloat2(&pos));
	DX::XMStoreFloat2(&wandPos, DX::XMVectorAdd(DX::XMVectorScale(DX::XMVector2Normalize(playerToMouse), 25), DX::XMLoadFloat2(&pos)));

	
	wand->SetPosition(wandPos);
	if (DX::XMVectorGetY(playerToMouse) > 0)
		wand->SetRotation(DX::XMVectorGetX(DX::XMVector2AngleBetweenVectors(playerToMouse, DX::XMLoadFloat2(&zeroAngle))));
	else
		wand->SetRotation(-DX::XMVectorGetX(DX::XMVector2AngleBetweenVectors(playerToMouse, DX::XMLoadFloat2(&zeroAngle))));
	
}

