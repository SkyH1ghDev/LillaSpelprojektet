#pragma once
#include "Mesh.hpp"
#include <SpEngine/Assets/Game/IScript.hpp>


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
