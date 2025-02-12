#include "PlayerAttack.hpp"
#include "ProjectileManager.hpp"

void PlayerAttack::Attack(DX::XMFLOAT2 position, DX::XMFLOAT2 direction)
{

	std::shared_ptr<Projectile> projectile = std::make_shared<Projectile>(ProjectileType::Base, position, direction, 60.0f, 2.0f);
	ProjectileManager::AddProjectile(projectile);
}
