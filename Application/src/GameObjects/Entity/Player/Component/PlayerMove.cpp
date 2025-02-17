#include "PlayerMove.hpp"

#include <SpEngine/Clock/Clock.hpp>

DX::XMFLOAT2 PlayerMove::Move(const DX::XMFLOAT2& position, const DX::XMFLOAT2& direction, bool dashInput, Collider m_collider) {
    float deltaTime = Clock::GetDeltaTime();
    DX::XMVECTOR positionXMVector = XMLoadFloat2(&position);
    DX::XMVECTOR directionXMVector = DX::XMVector2Normalize(XMLoadFloat2(&direction));

    //In the middle of the Dash
    if (isDashing) {

		dashSpeed += dashAcceleration * deltaTime;
        if (dashSpeed > maxDashSpeed)
            dashSpeed = maxDashSpeed;

        DX::XMVECTOR dashMovement = DX::XMVectorScale(dashDirection, dashSpeed * deltaTime);
        positionXMVector = DX::XMVectorAdd(positionXMVector, dashMovement);

        dashTimer -= deltaTime;

        if (dashTimer <= 0.0f) {
            isDashing = false;
            dashCooldownTimer = dashCooldown;
            dashSpeed = 0.0f;
        }

    }
    //Start the Dash
    else if (dashInput && dashCooldownTimer <= 0) {
        isDashing = true;
        dashTimer = dashDuration;
        dashSpeed = maxSpeed;

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

        if (DX::XMVector2Length(directionXMVector).m128_f32[0] > 0.0f) {
			facingDirection = directionXMVector;
            currentSpeed += acceleration * deltaTime;

            if (currentSpeed > maxSpeed) 
                currentSpeed = maxSpeed;
        }
        else {
            currentSpeed -= deceleration * deltaTime;

            if (currentSpeed < 0) 
                currentSpeed = 0;
        }

        velocity = DX::XMVectorScale(directionXMVector, currentSpeed);

        DX::XMVECTOR movement = DX::XMVectorScale(velocity, deltaTime);
        positionXMVector = DX::XMVectorAdd(positionXMVector, movement);
    }

    

    DX::XMFLOAT2 newPosition;
    DX::XMStoreFloat2(&newPosition, positionXMVector);

    m_collider.updatePosition(newPosition);

    if (PhysicsEngine::WallEntityXCollision(newPosition.x))
    {
        newPosition.x = position.x;
    }
    if (PhysicsEngine::WallEntityYCollision(newPosition.y))
    {
        newPosition.y = position.y;
    }

    m_collider.updatePosition(newPosition);

    return newPosition;
}

