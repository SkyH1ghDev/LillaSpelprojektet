#pragma once
#include "Entity.hpp"
#include "Mesh.hpp"
#include "Actions/MoveUp.hpp"
#include "Actions/MoveLeft.hpp"
#include "Actions/MoveRight.hpp"
#include "Actions/MoveDown.hpp"
#include "Actions/Attack.hpp"

#include <SpEngine/Assets/IScript.hpp>


class PlayerController : public IScript
{
public:
	void OnStart() override;
	void Update() override;
	std::shared_ptr<IGameObject> GetWeaponObject() const;

private:
	std::shared_ptr<MoveUp> m_up = std::make_shared<MoveUp>();
	std::shared_ptr<MoveLeft> m_left = std::make_shared<MoveLeft>();
	std::shared_ptr<MoveRight> m_right = std::make_shared<MoveRight>();
	std::shared_ptr<MoveDown> m_down = std::make_shared<MoveDown>();
	std::shared_ptr<Attack> m_attack = std::make_shared<Attack>();
	std::shared_ptr<IGameObject> m_weapon = std::make_shared<Mesh>(MeshType::Weapon);
};

inline std::shared_ptr<IGameObject> PlayerController::GetWeaponObject() const 
{
	return this->m_weapon;
}