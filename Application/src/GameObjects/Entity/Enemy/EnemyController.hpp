#pragma once
#include "Entity.hpp"

#include <SpEngine/Assets/Game/IScript.hpp>


class EnemyController : public IScript
{
public:
	EnemyController(std::shared_ptr<IGameObject> player);
	~EnemyController() override = default;

	void OnStart() override;
	void Update() override;

private:
	std::shared_ptr<IGameObject> m_player;
	float m_attackCooldown = 0.7f;
	float m_attackTimer = 0.0f;
};
