#pragma once

#include <SpEngine/Assets/IGameObject.hpp>

class HealthBar : public IGameObject
{
public:

	void Update() override;
	void OnStart() override;

	void GetMana();
	void SetMana();

private:
	int Mana;
};