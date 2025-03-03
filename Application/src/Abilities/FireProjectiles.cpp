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
void AbilityManager::Shotgun(DX::XMFLOAT2 position, DX::XMFLOAT2 direction, size_t projectileCount, float lifeSpan, float shotSpeed, float spreadAngle)
{
    // Convert direction to XMVECTOR for calculations
    DX::XMVECTOR dirVec = XMLoadFloat2(&direction);
    dirVec = DX::XMVector3Normalize(dirVec); // Ensure it's normalized

    for (int i = 0; i < projectileCount; ++i)
    {
        // Calculate angle offset (-spreadAngle to +spreadAngle)
        float angleOffset = DX::XMConvertToRadians(spreadAngle * ((i - (projectileCount - 1) / 2.0f) / ((projectileCount - 1) / 2.0f)));

        // Create rotation matrix
        DX::XMMATRIX rotationMatrix = DX::XMMatrixRotationZ(angleOffset);

        // Rotate direction vector
        DX::XMVECTOR spreadDirection = XMVector3TransformNormal(dirVec, rotationMatrix);

        // Convert back to XMFLOAT2
        DX::XMFLOAT2 finalDirection;
        XMStoreFloat2(&finalDirection, spreadDirection);

        // Add projectile
        ProjectileManager::AddProjectile(ProjectileType::ScatterPellet, DX::XMFLOAT2(position.x + finalDirection.x * 15, position.y + finalDirection.y * 15), finalDirection, shotSpeed + shotSpeed + (rand() % 50 - 25), lifeSpan, 10.0f);
    }
}

/**
  * Creates projectiles in eight directions based on input parameters
  * @param position Position to spawn projectiles
  * @param projectileCount Number of projectiles to spawn around position
  * @param lifeSpan Lifetime of projectile in seconds
  * @param shotSpeed Speed of projectiles in pixels per second
  */
void AbilityManager::SurroundShot(DX::XMFLOAT2 position, size_t projectileCount, float lifeSpan, float shotSpeed)
{

    for (int i = 0; i < projectileCount; ++i)
    {
        // Calculate angle offset (-spreadAngle to +spreadAngle)
        float angleOffset = DX::XMConvertToRadians(360 / projectileCount * i);

        // Create rotation matrix
        DX::XMMATRIX rotationMatrix = DX::XMMatrixRotationZ(angleOffset);
        DX::XMFLOAT3 startDir(1, 0, 0);
        // Rotate direction vector
        DX::XMVECTOR spreadDirection = XMVector3TransformNormal(XMLoadFloat3(&startDir), rotationMatrix);

        // Convert back to XMFLOAT2
        DX::XMFLOAT2 finalDirection;
        XMStoreFloat2(&finalDirection, spreadDirection);
        
        // Add projectile
        ProjectileManager::AddProjectile(ProjectileType::FireBall, DX::XMFLOAT2(position.x + finalDirection.x * 15, position.y + finalDirection.y * 15), finalDirection, shotSpeed, lifeSpan, 30.0f);
    }
}

void AbilityManager::SniperShot(DX::XMFLOAT2 position, DX::XMFLOAT2 direction, float shotSpeed, float damageMultiplier)
{
    DX::XMVECTOR dirVec = XMLoadFloat2(&direction);
    dirVec = DX::XMVector2Normalize(dirVec);
    DX::XMFLOAT2 dir;
    XMStoreFloat2(&dir, dirVec);

    // Add projectile
    ProjectileManager::AddProjectile(ProjectileType::SniperBullet, position, dir, shotSpeed, 10.0f, 20.0f * damageMultiplier);
}

void AbilityManager::DisruptorWave(DX::XMFLOAT2 position, DX::XMFLOAT2 direction, float duration)
{
    // Add projectile
    ProjectileManager::AddProjectile(ProjectileType::DisruptorWave, position, direction, 0, duration, 0);
}
