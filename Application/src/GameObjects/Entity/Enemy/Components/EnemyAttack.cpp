#include "EnemyAttack.hpp"

void EnemyAttack::Attack(DX::XMFLOAT2 position, DX::XMFLOAT2 direction)
{
    const int numProjectiles = 5;    // Total projectiles in spread
    const float spreadAngle = 35.0f; // Total angle variation in degrees

    // Convert direction to XMVECTOR for calculations
    DX::XMVECTOR dirVec = XMLoadFloat2(&direction);
    dirVec = DX::XMVector3Normalize(dirVec); // Ensure it's normalized

    for (int i = 0; i < numProjectiles; ++i)
    {
        // Calculate angle offset (-spreadAngle to +spreadAngle)
        float angleOffset = DX::XMConvertToRadians(spreadAngle * ((i - (numProjectiles - 1) / 2.0f) / ((numProjectiles - 1) / 2.0f)));

        // Create rotation matrix
        DX::XMMATRIX rotationMatrix = DX::XMMatrixRotationZ(angleOffset);

        // Rotate direction vector
        DX::XMVECTOR spreadDirection = XMVector3TransformNormal(dirVec, rotationMatrix);

        // Convert back to XMFLOAT2
        DX::XMFLOAT2 finalDirection;
        XMStoreFloat2(&finalDirection, spreadDirection);

        // Create and add projectile
        ProjectileManager::AddProjectile(position, finalDirection, 60.0f, 8);
    }
}