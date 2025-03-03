#include "PawnAttack.hpp"
#include "ProjectileManager.hpp"

void PawnAttack::Attack(DX::XMFLOAT2 position, DX::XMFLOAT2 direction)
{
    // Convert direction to XMVECTOR for calculations
    DX::XMVECTOR dirVec = XMLoadFloat2(&direction);
    dirVec = DX::XMVector3Normalize(dirVec); // Ensure it's normalized

    this->m_attackTimer += Clock::GetDeltaTime();

    if (this->m_attackTimer >= this->m_attackCooldown)
    {
        // Convert back to XMFLOAT2
        DX::XMFLOAT2 finalDirection;
        XMStoreFloat2(&finalDirection, dirVec);

        // Create and add projectile
        ProjectileManager::AddProjectile(ProjectileType::BishopBall, position, finalDirection, 90.0f, 3, 1.0f);
        this->m_attackTimer = 0;
    }
}