#include "PawnAttack.hpp"
#include "ProjectileManager.hpp"

void PawnAttack::Attack(DX::XMFLOAT2 position, DX::XMFLOAT2 direction)
{
    // Convert direction to XMVECTOR for calculations
    DX::XMVECTOR dirVec = XMLoadFloat2(&direction);
    dirVec = DX::XMVector3Normalize(dirVec); // Ensure it's normalized

    // Convert back to XMFLOAT2
    DX::XMFLOAT2 finalDirection;
    XMStoreFloat2(&finalDirection, dirVec);

    // Create and add projectile
    ProjectileManager::AddProjectile(ProjectileType::BishopBall, position, finalDirection, 90.0f, 2, 1.0f);
}
