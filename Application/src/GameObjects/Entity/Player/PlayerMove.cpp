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

        float currentSpeed = DirectX::XMVector2Length(velocity).m128_f32[0];
        DX::XMVECTOR newVelocity = velocity;

        if (DirectX::XMVector2Length(directionXMVector).m128_f32[0] > 0.0f) {
            facingDirection = directionXMVector;


            float dotProduct = DirectX::XMVectorGetX(DirectX::XMVector2Dot(directionXMVector, DX::XMVector2Normalize(velocity)));

            if (dotProduct < 0.5f) {
                newVelocity = DX::XMVectorSubtract(velocity, DX::XMVectorScale(velocity, deceleration * deltaTime));
            }

            newVelocity = DX::XMVectorAdd(newVelocity, DX::XMVectorScale(directionXMVector, acceleration * deltaTime));

            float newSpeed = DirectX::XMVector2Length(newVelocity).m128_f32[0];
            if (newSpeed > maxVelocity) {
                newVelocity = DX::XMVectorScale(DX::XMVector2Normalize(newVelocity), maxVelocity);
            }
        }
        else {
            if (currentSpeed > 0.1f) {
                newVelocity = DX::XMVectorSubtract(newVelocity, DX::XMVectorScale(DX::XMVector2Normalize(newVelocity), deceleration * deltaTime));
            }
            if (DirectX::XMVector2Length(newVelocity).m128_f32[0] < 0.01f) {
                newVelocity = DX::XMVectorZero();
            }
        }

        newVelocity = DX::XMVectorScale(newVelocity, 1.0f - friction * deltaTime);
        velocity = newVelocity;

        DX::XMVECTOR movement = DX::XMVectorScale(velocity, deltaTime);
        positionXMVector = DX::XMVectorAdd(positionXMVector, movement);
    }

    DX::XMFLOAT2 newPosition;
    DX::XMStoreFloat2(&newPosition, positionXMVector);

    if (this->m_physics.WallEntityXCollision(newPosition.x))
    {
        newPosition.x = position.x;
    }
    if (this->m_physics.WallEntityYCollision(newPosition.y))
    {
        newPosition.y = position.y;
    }

    return newPosition;
}

