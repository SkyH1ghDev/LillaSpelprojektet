#include "PlayerMove.hpp"

#include <SpEngine/Clock/Clock.hpp>

DX::XMFLOAT2 PlayerMove::Move(const DX::XMFLOAT2& position, const DX::XMFLOAT2& direction, bool dashInput) {
    float deltaTime = Clock::GetDeltaTime();
    DX::XMVECTOR positionXMVector = XMLoadFloat2(&position);
    DX::XMVECTOR directionXMVector = DX::XMVector2Normalize(XMLoadFloat2(&direction));

    //In the middle of the Dash
    if (isDashing) {

        DX::XMVECTOR dashMovement = DX::XMVectorScale(dashDirection, dashSpeed * deltaTime);
        positionXMVector = DX::XMVectorAdd(positionXMVector, dashMovement);

        dashTimer -= deltaTime;

        if (dashTimer <= 0.0f) {
            isDashing = false;
            dashCooldownTimer = dashCooldown;
        }

    }
    //Start the Dash
    else if (dashInput && dashCooldownTimer <= 0) {
        isDashing = true;
        dashTimer = dashDuration;

        if (DX::XMVector2Length(directionXMVector).m128_f32[0] > 0.0f) {
            dashDirection = directionXMVector;
            facingDirection = directionXMVector;
        }
        else {
            dashDirection = facingDirection;
        }

    }
    //Regular movement
    else {
        if (dashCooldownTimer > 0)
            dashCooldownTimer -= deltaTime;

        if (DirectX::XMVector2Length(directionXMVector).m128_f32[0] > 0.0f) {
            // Apply acceleration when there's input
            facingDirection = directionXMVector;
            velocity = DX::XMVectorAdd(velocity, DX::XMVectorScale(DX::XMVector2Normalize(directionXMVector), acceleration * deltaTime));

            // Cap velocity to max speed
            if (DirectX::XMVector2Length(velocity).m128_f32[0] > maxVelocity) {
                velocity = DX::XMVectorScale(DX::XMVector2Normalize(velocity), maxVelocity);
            }
        }
        else {
            // Deceleration when no input
            if (DirectX::XMVector2Length(velocity).m128_f32[0] > 0.01f) {
                velocity = DX::XMVectorSubtract(velocity, DX::XMVectorScale(DX::XMVector2Normalize(velocity), deceleration * deltaTime));
            }

            // Clamp velocity to zero if it's very small
            if (DirectX::XMVector2Length(velocity).m128_f32[0] < 0.01f) {
                velocity = DX::XMVectorZero();
            }
        }

        // Apply friction
        velocity = DX::XMVectorScale(velocity, 1.0f - friction * deltaTime);

        // Update position based on velocity
        DX::XMVECTOR movement = DX::XMVectorScale(velocity, deltaTime);
        positionXMVector = DX::XMVectorAdd(positionXMVector, movement);
    }



    DX::XMFLOAT2 newPosition;
    DX::XMStoreFloat2(&newPosition, positionXMVector);

    return newPosition;
}

