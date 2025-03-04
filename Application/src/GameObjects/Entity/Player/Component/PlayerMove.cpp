#include "PlayerMove.hpp"
#include "StatSheet.hpp"
#include <SpEngine/Clock/Clock.hpp>
#include "PlayerInfo.hpp"

DX::XMFLOAT2 PlayerMove::Move(const DX::XMFLOAT2& position, const DX::XMFLOAT2& direction, bool& dashInput, std::shared_ptr<Collider> m_collider, bool& isStunned) {
    float deltaTime = Clock::GetDeltaTime();
    DX::XMVECTOR positionXMVector = XMLoadFloat2(&position);
    DX::XMVECTOR directionXMVector = DX::XMVector2Normalize(XMLoadFloat2(&direction));

    this->maxSpeed = StatSheet::GetMoveSpeed();

    if (isStunned)
    {
        isDashing = false;
        dashSpeed = 0.0f;
        dashCooldownTimer = 0.0f;
    }
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
            dashInput = false;
            dashCooldownTimer = dashCooldown;
            dashSpeed = 0.0f;
        }

    }
    //Start the Dash
    else if (dashInput && dashCooldownTimer <= 0) {
        isDashing = true;
        dashInput = true;
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
        dashInput = false;
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

    m_collider->UpdatePosition(newPosition);

    if (PhysicsEngine::WallEntityXCollision(m_collider))      
    {
        newPosition.x = position.x;
    }
    if (PhysicsEngine::WallEntityYCollision(m_collider))
    {
        newPosition.y = position.y;
    }
    PlayerInfo::SetPosition(newPosition);
    return newPosition;
}

