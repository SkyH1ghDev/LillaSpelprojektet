#pragma once

#include <SpEngine/Assets/IGameObject.hpp>

class HealthBar : public IGameObject 
{
public:

	void Update() override;
	void OnStart() override;

	void GetHP();
	void SetHP();

private:
	int HP;
};