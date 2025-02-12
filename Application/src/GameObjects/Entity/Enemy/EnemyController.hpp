#pragma once
#include "Entity.hpp"

#include <SpEngine/Assets/IScript.hpp>


class EnemyController : public IScript
{
public:
	EnemyController(std::shared_ptr<IGameObject> player);
	~EnemyController() override = default;

	void OnStart() override;
	void Update() override;

private:
	std::shared_ptr<IGameObject> m_player;
	float attackCooldown = 2.0f;
	float attackTimer = 0.0f;
};
