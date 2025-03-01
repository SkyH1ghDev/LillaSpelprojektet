#include "RookMove.hpp"
#include <SpEngine/Clock/Clock.hpp>

#include "RookMove.hpp"
#include <SpEngine/Clock/Clock.hpp>

DX::XMFLOAT2 RookMove::Move(const DX::XMFLOAT2& position, const DX::XMFLOAT2& direction, bool& dashInput, std::shared_ptr<Collider> m_collider) {
    float deltaTime = Clock::GetDeltaTime();
    DX::XMVECTOR positionXMVector = XMLoadFloat2(&position);  // Convert XMFLOAT2 to XMVECTOR
    DX::XMVECTOR directionXMVector = XMLoadFloat2(&direction);

    // Normalize direction vector if it's nonzero
    if (DX::XMVector2LengthSq(directionXMVector).m128_f32[0] > 0.0f) {
        directionXMVector = DX::XMVector2Normalize(directionXMVector);
    }

    // Continue dashing until a wall is hit
    if (isDashing) {
        // Apply dash movement
        DX::XMVECTOR dashMovement = DX::XMVectorScale(XMLoadFloat2(&dashDirection), dashSpeed * deltaTime);
        DX::XMVECTOR newPositionVec = DX::XMVectorAdd(positionXMVector, dashMovement);

        DX::XMFLOAT2 newPosition;
        XMStoreFloat2(&newPosition, newPositionVec);  // Convert back to XMFLOAT2

        m_collider->UpdatePosition(newPosition);

        // Stop dashing if a wall is hit
        if (PhysicsEngine::WallEntityXCollision(m_collider) || PhysicsEngine::WallEntityYCollision(m_collider)) {
            isDashing = false;
            dashInput = false;
            dashSpeed = 0.0f;
        }
        else {
            return newPosition;
        }
    }

    // Start dashing if triggered and not already dashing
    if (dashInput && !isDashing) {
        isDashing = true;
        dashSpeed = 400.0f; // Initial dash speed

        // Set the dash direction based on the initial direction vector
        if (DX::XMVector2LengthSq(directionXMVector).m128_f32[0] > 0.0f) {
            XMStoreFloat2(&dashDirection, directionXMVector); // Convert XMVECTOR to XMFLOAT2
        }
        else {
            // If no direction is provided, default to a direction (e.g., right)
            dashDirection = DX::XMFLOAT2(1.0f, 0.0f);
        }
    }

    // Handle regular movement when not dashing
    if (!isDashing) {
        DX::XMVECTOR movement = DX::XMVectorScale(directionXMVector, m_moveSpeed * deltaTime);
        DX::XMVECTOR newPositionVec = DX::XMVectorAdd(positionXMVector, movement);

        DX::XMFLOAT2 newPosition;
        XMStoreFloat2(&newPosition, newPositionVec);  // Convert back to XMFLOAT2

        m_collider->UpdatePosition(newPosition);

        // Check for collisions and adjust position if necessary
        if (PhysicsEngine::WallEntityXCollision(m_collider) || PhysicsEngine::WallEntityYCollision(m_collider)) {
            // Handle collision (e.g., stop movement or adjust position)
        }
        else {
            return newPosition;
        }
    }

    return position;
}

