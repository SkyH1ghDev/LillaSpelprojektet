#pragma once
#include "Entity.hpp"
#include "Actions/Attack.hpp"

#include <SpEngine/Assets/Game/IScript.hpp>


class PlayerAttackScript : public IScript
{
public:
	void OnStart() override;
	void Update() override;

private:
	std::shared_ptr<Attack> m_attack = std::make_shared<Attack>();
	float m_attackTimer = 0;
};
