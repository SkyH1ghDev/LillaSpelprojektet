#pragma once
#include "Mesh.hpp"
#include <SpEngine/Input/Input.hpp>
#include <SpEngine/Assets/Game/IScript.hpp>


class PauseBackgroundScript : public IScript
{
public:
	PauseBackgroundScript() = default;
	void OnStart() override;
	void Update() override;

private:
};
