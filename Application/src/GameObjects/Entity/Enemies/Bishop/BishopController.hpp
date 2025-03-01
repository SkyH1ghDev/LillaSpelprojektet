#pragma once
#include "Entity.hpp"

#include <SpEngine/Assets/Game/IScript.hpp>


class BishopController : public IScript
{
public:
	BishopController() = default;
	~BishopController() override = default;

	void OnStart() override;
	void Update() override;

private:
	float m_attackCooldown = 0.7f;
	float m_attackTimer = 0.0f;
};
