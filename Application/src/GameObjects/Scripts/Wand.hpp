#pragma once
#include "Mesh.hpp"
#include <SpEngine/Input/Input.hpp>
#include <SpEngine/Assets/IScript.hpp>


class WandScript : public IScript
{
public:
	WandScript() = default;
	WandScript(std::shared_ptr<IGameObject> player);
	void OnStart() override;
	void Update() override;

private:
	std::shared_ptr<IGameObject> player;
};
