#pragma once
#include "Entity.hpp"
#include "Mesh.hpp"
#include "Actions/Attack.hpp"

#include <SpEngine/Assets/IScript.hpp>


class PlayerAttackScript : public IScript
{
public:
	void OnStart() override;
	void Update() override;

private:
	std::shared_ptr<Attack> m_attack = std::make_shared<Attack>();
	float m_attackTimer = 0;
};
