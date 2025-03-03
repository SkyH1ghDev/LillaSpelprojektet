#include "RookAltAttack.hpp"
#include "ProjectileManager.hpp"

void RookAltAttack::Attack(DX::XMFLOAT2 position, DX::XMFLOAT2 direction)
{
    const int numProjectiles = 20;    // Total projectiles in spread
    const float shotSpeed = 180.0f;
    const float lifeSpan = 30.0f;
    // Convert direction to XMVECTOR for calculations
    DX::XMVECTOR dirVec = XMLoadFloat2(&direction);
    dirVec = DX::XMVector3Normalize(dirVec); // Ensure it's normalized

    for (int i = 0; i < numProjectiles; ++i)
    {
        float angleOffset = DX::XMConvertToRadians(360 / numProjectiles * i);

        // Create rotation matrix
        DX::XMMATRIX rotationMatrix = DX::XMMatrixRotationZ(angleOffset);
        DX::XMFLOAT3 startDir(1, 0, 0);
        // Rotate direction vector
        DX::XMVECTOR spreadDirection = XMVector3TransformNormal(XMLoadFloat3(&startDir), rotationMatrix);

        // Convert back to XMFLOAT2
        DX::XMFLOAT2 finalDirection;
        XMStoreFloat2(&finalDirection, spreadDirection);

        // Add projectile
        ProjectileManager::AddProjectile(ProjectileType::BishopBall, DX::XMFLOAT2(position.x + finalDirection.x * 15, position.y + finalDirection.y * 15), finalDirection, shotSpeed, lifeSpan, 1.0f);
    }
}