#pragma once
#include "AnimateMesh.hpp"
#include "StatSheet.hpp"
#include "Mesh.hpp"

void AnimateScript::OnStart()
{
}

void AnimateScript::Update()
{
	std::shared_ptr<Mesh> background = std::static_pointer_cast<Mesh>(m_gameObject.lock());
	background->PerformVisible();
	background->UpdateAnimation();
}

