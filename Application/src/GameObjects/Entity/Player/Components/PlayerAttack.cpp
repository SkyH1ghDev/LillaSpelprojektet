#pragma once

#include "PlayerAttack.hpp"
#include "ProjectileManager.hpp"
#include "AbilityManager.hpp"
#include "StatSheet.hpp"

void PlayerAttack::Attack(DX::XMFLOAT2 position, DX::XMFLOAT2 direction)
{
	ProjectileManager::AddProjectile(ProjectileType::PawnPellet, DX::XMFLOAT2(position.x + direction.x * 15, position.y + direction.y * 15), direction, StatSheet::GetShotSpeed(), StatSheet::GetShotLife(), StatSheet::GetDamage());
}
