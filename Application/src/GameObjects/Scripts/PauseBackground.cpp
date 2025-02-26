#pragma once
#include "PauseBackground.hpp"
#include "StatSheet.hpp"

void PauseBackgroundScript::OnStart()
{
}

void PauseBackgroundScript::Update()
{
	std::shared_ptr<Mesh> background = std::static_pointer_cast<Mesh>(m_gameObject.lock());
	background->PerformVisible();
	background->UpdateAnimation();
}

