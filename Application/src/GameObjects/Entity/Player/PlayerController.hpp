#include <SpEngine/Assets/IGameObject.hpp>
#include <SpEngine/Dev/Pattern/Observer/IObserver.hpp>
#include <iostream>
#include "Entity.hpp"

class ForwardAction : public IObserver {
public:
	ForwardAction(std::shared_ptr<Entity> player) : m_player(player) {}

	
	void Update(std::optional<std::any> data) override {
		DX::XMFLOAT2 m_direction = { 1, 0 };
		m_player->PerformMove(m_direction);
	}
private:
	std::shared_ptr<Entity> m_player;
};

class LeftAction : public IObserver {

	void Update(std::optional<std::any> data) override {
		std::cerr << "Move Left";
	}
};

class RightAction : public IObserver {

	void Update(std::optional<std::any> data) override {
		std::cerr << "Move Right";
	}
};

class BackAction : public IObserver {

	void Update(std::optional<std::any> data) override {
		std::cerr << "Move Back";
     	}
};

class PlayerController : public IGameObject
{
public:
	PlayerController(std::shared_ptr<Entity> player);

	void OnStart() override;
	void Update() override;

private:
	std::shared_ptr<ForwardAction> m_forward = std::make_shared<ForwardAction>(m_player);
	std::shared_ptr<LeftAction> m_left = std::make_shared<LeftAction>(m_player);
	std::shared_ptr<RightAction> m_right = std::make_shared<RightAction>(m_player);
	std::shared_ptr<BackAction> m_back = std::make_shared<BackAction>(m_player);
	std::shared_ptr<Entity> m_player;
};


