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

        // Create and add projectile
        std::shared_ptr<Projectile> projectile = std::make_shared<Projectile>(ProjectileType::Base, position, finalDirection, shotSpeed, lifeSpan);
        ProjectileManager::AddProjectile(projectile);
    }
}