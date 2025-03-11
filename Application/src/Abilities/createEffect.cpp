#include "AbilityManager.hpp"
#include "ProjectileManager.hpp"


/**
  * Creates projectiles based on input parameters
  * @param position Position to spawn projectiles
  * @param direction Travel direction for projectiles
  * @param projectileCount Number of projectiles to spawn
  * @param lifeSpan Lifetime of projectile in seconds
  * @param shotSpeed Speed of projectiles in pixels per second
  * @param spreadAngle Angle offset between projectiles
  */
void AbilityManager::longEffect(DX::XMFLOAT2 position, DX::XMFLOAT2 direction, size_t projectileCount, float lifeSpan, float shotSpeed, float spreadAngle)
{
    ProjectileManager::AddProjectile(ProjectileType::Longshot, DX::XMFLOAT2(position.x, position.y), direction, shotSpeed + shotSpeed + (rand() % 50 - 25), lifeSpan, 10.0f);
}

void AbilityManager::HasteEffect(DX::XMFLOAT2 position, DX::XMFLOAT2 direction, size_t projectileCount, float lifeSpan, float shotSpeed, float spreadAngle)
{
    ProjectileManager::AddProjectile(ProjectileType::Haste, DX::XMFLOAT2(position.x, position.y), direction, shotSpeed + shotSpeed + (rand() % 50 - 25), lifeSpan, 10.0f);
}



