#include "BishopAttack.hpp"
#include "ProjectileManager.hpp"

void BishopAttack::Attack(DX::XMFLOAT2 position, DX::XMFLOAT2 direction)
{
    const int numProjectiles = 3;    // Total projectiles in spread
    const float spreadAngle = 35.0f; // Total angle variation in degrees

    // Convert direction to XMVECTOR for calculations
    DX::XMVECTOR dirVec = XMLoadFloat2(&direction);
    dirVec = DX::XMVector3Normalize(dirVec); // Ensure it's normalized

    this->m_attackTimer += Clock::GetDeltaTime();

    if (this->m_attackTimer >= this->m_attackCooldown)
    {
        this->m_burstTimer += Clock::GetDeltaTime();

        if (this->m_burstTimer >= this->m_burstCooldown && this->m_burstAmount > 0) {
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
                ProjectileManager::AddProjectile(ProjectileType::BishopBall, position, finalDirection, 60.0f, 8, 1.0f);
            }
            this->m_burstAmount -= 1;
            this->m_burstTimer = 0;
            if (m_burstAmount == 0) {
                this->m_burstAmount = 10;
                this->m_burstTimer = 0;
                this->m_attackTimer = 0;
            }

        }

    }
}

void BishopAttack::Reset()
{
    this->m_attackCooldown = 2.0f;
    this->m_burstCooldown = 1.0f;
    this->m_burstTimer = 0.0f;
    this->m_attackTimer = 0.0f;
    this->m_burstAmount = 10;
}
