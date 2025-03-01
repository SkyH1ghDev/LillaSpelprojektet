#include "RookController.hpp"
#include "PlayerInfo.hpp"
#include <SpEngine/Input/Input.hpp>
#include <SpEngine/Clock/Clock.hpp>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

void RookController::OnStart()
{
    m_isCharging = false;
    m_chargeTimer = 0.0f;
    m_attackTimer = 0.0f;
    m_currentPatrolDirection = DX::XMFLOAT2(1, 0); // Start moving right by default
    m_patrolTime = 0.0f;
    m_nextDirectionChangeTime = GetRandomDirectionChangeTime();

    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
}

void RookController::Update()
{
    std::shared_ptr<Entity> rook = std::static_pointer_cast<Entity>(m_gameObject.lock());
    DX::XMFLOAT2 rookPos = rook->GetPosition();
    DX::XMFLOAT2 playerPos = PlayerInfo::GetPosition();

    DX::XMVECTOR rookVec = XMLoadFloat2(&rookPos);
    DX::XMVECTOR playerVec = XMLoadFloat2(&playerPos);
    DX::XMVECTOR rookToPlayerVec = DX::XMVectorSubtract(playerVec, rookVec);

    float distance = DX::XMVectorGetX(DX::XMVector3Length(rookToPlayerVec));

    // Charging behavior
    if (m_isCharging) {
        m_chargeTimer -= Clock::GetDeltaTime();
        if (m_chargeTimer <= 0.0f) {
            DX::XMVECTOR directionVec = DX::XMVector3Normalize(rookToPlayerVec);
            DX::XMFLOAT2 direction;
            XMStoreFloat2(&direction, directionVec);

            // Ensure dash is only horizontal or vertical
            if (fabs(direction.x) > fabs(direction.y)) {
                direction.y = 0.0f; // Move horizontally
            }
            else {
                direction.x = 0.0f; // Move vertically
            }

            rook->PerformMove(direction, true); // Dash towards player
            m_isCharging = false;
        }
        return;
    }

    // Search for player in + pattern
    if ((distance < 700) && !rook->Dashing()) { // Adjust search range
        if (fabs(rookPos.x - playerPos.x) < 10 || fabs(rookPos.y - playerPos.y) < 10) {
            m_isCharging = true;
            m_chargeTimer = 1.0f; // Charge time before dashing
            return;
        }
    }

    // Patrol behavior
    if (!m_isCharging) {
        m_patrolTime += Clock::GetDeltaTime();

        // Change direction after a random amount of time
        if (m_patrolTime >= m_nextDirectionChangeTime) {
            m_currentPatrolDirection = GetRandomDirection();
            m_nextDirectionChangeTime = GetRandomDirectionChangeTime();
            m_patrolTime = 0.0f;
        }

        // Move at patrol speed
        DX::XMFLOAT2 patrolMove = { m_currentPatrolDirection.x,
                                    m_currentPatrolDirection.y};

        rook->PerformMove(patrolMove, false);
    }
}

DX::XMFLOAT2 RookController::GetRandomDirection()
{
    // Define possible directions (up, down, left, right)
    std::vector<DX::XMFLOAT2> directions = {
        DX::XMFLOAT2(1, 0),  // Right
        DX::XMFLOAT2(-1, 0), // Left
        DX::XMFLOAT2(0, 1),  // Up
        DX::XMFLOAT2(0, -1)  // Down
    };

    // Bias the direction based on the current direction
    // Higher chance to move in the opposite direction
    if (m_currentPatrolDirection.x != 0) {
        // Currently moving horizontally, bias towards vertical movement
        directions.push_back(DX::XMFLOAT2(0, 1));  // Up
        directions.push_back(DX::XMFLOAT2(0, -1)); // Down
    }
    else if (m_currentPatrolDirection.y != 0) {
        // Currently moving vertically, bias towards horizontal movement
        directions.push_back(DX::XMFLOAT2(1, 0));  // Right
        directions.push_back(DX::XMFLOAT2(-1, 0)); // Left
    }

    // Randomly select a direction
    int index = rand() % directions.size();
    return directions[index];
}

float RookController::GetRandomDirectionChangeTime()
{
    // Return a random time between 1 and 3 seconds
    return 1.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 2.0f));
}