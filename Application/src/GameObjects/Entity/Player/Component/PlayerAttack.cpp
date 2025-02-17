#pragma once

#include "PlayerAttack.hpp"
#include "ProjectileManager.hpp"
#include "AbilityManager.hpp"

void PlayerAttack::Attack(DX::XMFLOAT2 position, DX::XMFLOAT2 direction)
{
	//std::shared_ptr<Projectile> projectile = std::make_shared<Projectile>(ProjectileType::Base, DX::XMFLOAT2(position.x + direction.x * 15, position.y + direction.y * 15), direction, 300.0f, 0.5f);
	//ProjectileManager::AddProjectile(projectile);
	AbilityManager::Shotgun(position, direction, 5, 8, 300, 15);
}
