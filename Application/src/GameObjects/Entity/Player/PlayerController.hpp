#include <SpEngine/Assets/IGameObject.hpp>
#include <SpEngine/Dev/Pattern/Observer/IObserver.hpp>
#include <iostream>

class ForwardAction : public IObserver {

	void Update(std::optional<std::any> data) override {
		std::cerr << "Move Forward";
	}
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
	PlayerController() = default;

	void OnStart() override;
	void Update() override;

private:
	std::shared_ptr<ForwardAction> m_forward = std::make_shared<ForwardAction>();
	std::shared_ptr<LeftAction> m_left = std::make_shared<LeftAction>();
	std::shared_ptr<RightAction> m_right = std::make_shared<RightAction>();
	std::shared_ptr<BackAction> m_back = std::make_shared<BackAction>();
};


