#pragma once
#include <SpEngine/Assets/Game/IScript.hpp>
#include "Actions/Pause.hpp"

class PauseControl : public IScript
{
public:
	PauseControl() = default;
	void OnStart() override;
	void Update() override;

private:
	std::shared_ptr<Pause> m_pause = std::make_shared<Pause>();
	bool m_keyHeld = false;
};
