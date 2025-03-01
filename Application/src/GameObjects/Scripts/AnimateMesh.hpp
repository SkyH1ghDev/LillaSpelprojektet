#pragma once
#include <SpEngine/Assets/Game/IScript.hpp>


class AnimateScript : public IScript
{
public:
	AnimateScript() = default;
	void OnStart() override;
	void Update() override;

private:
};
