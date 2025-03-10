#include "BishopAltAttack.hpp"
#include "ProjectileManager.hpp"

#include "SpEngine/Clock/Clock.hpp"

void BishopAltAttack::Attack(DX::XMFLOAT2 position, DX::XMFLOAT2 direction)
{
   // Convert direction to XMVECTOR for calculations
    DX::XMVECTOR dirVec = XMLoadFloat2(&direction);
    dirVec = DX::XMVector3Normalize(dirVec); // Ensure it's normalized

    DX::XMFLOAT2 finalDirection;
    XMStoreFloat2(&finalDirection, dirVec);

    this->m_attackTimer += Clock::GetDeltaTime();

    if (this->m_attackTimer >= this->m_attackCooldown)
    {
        this->m_burstTimer += Clock::GetDeltaTime();

        if (this->m_burstTimer >= this->m_burstCooldown && this->m_burstAmount > 0)
        {
            ProjectileManager::AddProjectile(ProjectileType::BishopBall, position, finalDirection, 280.0f, 8, 1.0f);
            this->m_burstAmount -= 1;
            this->m_burstTimer = 0;
            if (this->m_burstAmount == 0)
            {
                this->m_burstAmount = 3;
                this->m_attackTimer = 0;
                this->m_burstTimer = 0;
            }
        }

    }
}