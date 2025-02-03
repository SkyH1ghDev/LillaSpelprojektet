#include <SpEngine/Assets/IGameObject.hpp>
#include <iostream>

class ForwardAction;
class LeftAction;
class RightAction;
class BackAction;

class PlayerController : public IGameObject
{
public:
	PlayerController() = default;
	void PLayerControls();

	void OnStart() override;
	void Update() override;

private:
	std::shared_ptr<ForwardAction> m_forward;
	std::shared_ptr<LeftAction> m_left;
	std::shared_ptr<RightAction> m_right;
	std::shared_ptr<BackAction> m_back;
};

class ForwardAction : public IObserver {

	void Update(std::optional<std::any> data) override {
		std::cerr << "Move forward";
	}



};

class LeftAction : public IObserver {

	void Update(std::optional<std::any> data) override {
		// Move Left
	}
};

class RightAction : public IObserver {

	void Update(std::optional<std::any> data) override {
		// Move Right
	}
};

class BackAction : public IObserver {

	void Update(std::optional<std::any> data) override {
		// Move Back
	}
};